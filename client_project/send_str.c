/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:20:44 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/09 13:31:53 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_error_code	send_bit(t_client_meta *m)
{
	unsigned char	c;

	c = (unsigned char)m->mgs[m->index];
	if ((c >> m->bit) & ONE)
	{
		if (ERROR == kill(m->server_pid, CTS_ONE))
			return (KILL_ERROR);
	}
	else
		if (ERROR == kill(m->server_pid, CTS_ZERO))
			return (KILL_ERROR);
	return (SUCCESS);
}

t_error_code	send_null(t_client_meta *m)
{
	int	i;

	i = 0;
	while (i < BYTE_SIZE)
	{
		if (ERROR == kill(m->server_pid, CTS_ZERO))
			return (KILL_ERROR);
		while (!m->con)
			pause();
		m->con = FALSE;
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
			while (!m->con)
				pause();
			m->con = FALSE;
		}
		m->bit = 0;
		++m->index;
	}
	return (send_null(m));
}
