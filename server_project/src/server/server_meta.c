/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_meta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:05:03 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/06 18:48:20 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_server_meta	*server_meta(t_server_meta *new)
{
	static t_server_meta	*m = NULL;

	if (!m)
	{
		m = new;
		ft_bzero(m, sizeof(t_server_meta));
	}
	return (m);
}

t_error_code	server_meta_init(t_server_meta *m)
{
	t_error_code	err;
	m->len = DEFAULT_MSG_LEN;
	m->msg = ft_calloc(m->len + 1, sizeof(unsigned char));
	if (!m->msg)
		return (FAILED_TO_INIT_SERVER);
	return (SUCCESS);
}

void	server_meta_free(t_server_meta *m)
{
	if (m)
	{
		free(m->msg);
		ft_bzero(m, sizeof(t_server_meta));
	}
}
