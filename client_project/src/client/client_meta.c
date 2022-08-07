/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_meta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:08:55 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/06 16:55:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_client_meta	*clinet_meta(t_client_meta *new)
{
	static t_client_meta	*m = NULL;

	if (!m)
	{
		m = new;
		ft_bzero(m, sizeof(t_client_meta));
	}
	return (m);
}

