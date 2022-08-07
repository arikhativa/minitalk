/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:11:45 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/07 15:14:05 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	t_server_meta	meta;

	server_meta(&meta);
	server_meta_init(&meta);
	ft_printf("%d\n", getpid());
	server_signal_init();
	while (1)
		pause();
	return (SUCCESS);
}
