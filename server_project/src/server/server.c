/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:11:45 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/06 17:41:07 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	t_server_meta	meta;

	server_meta(&meta);
	server_meta_init(&meta);
	ft_printf("server pid: %d\n", getpid());
	server_signal_init();
	while (1)
		pause();
	return (SUCCESS);
}
