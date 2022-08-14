/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:20:44 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/14 12:17:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static inline void	wait_for_signal(t_client_meta *m)
{
	while (!m->con)
		usleep(SLEEP_MILI_SEC);
	m->con = FALSE;
}

static t_error_code	send_bit(t_client_meta *m)
{
	unsigned char	c;

	c = (unsigned char)m->mgs[m->index];
	if ((c >> m->bit) & ONE)
	{
		if (ERROR == kill(m->server_pid, CTS_ONE))
			return (KILL_ERROR);
	}
	else
	{
		if (ERROR == kill(m->server_pid, CTS_ZERO))
			return (KILL_ERROR);
	}
	return (SUCCESS);
}

static t_error_code	send_null(t_client_meta *m)
{
	int	i;

	i = 0;
	while (i < BYTE_SIZE)
	{
		if (ERROR == kill(m->server_pid, CTS_ZERO))
			return (KILL_ERROR);
		wait_for_signal(m);
		++i;
	}
	return (SUCCESS);
}

t_error_code	send_str(t_client_meta *m)
{
	t_error_code	err;

	while (m->mgs[m->index])
	{
		while (m->bit < BYTE_SIZE)
		{
			err = send_bit(m);
			if (SUCCESS != err)
				return (err);
			++m->bit;
			wait_for_signal(m);
		}
		m->bit = 0;
		++m->index;
	}
	return (send_null(m));
}
