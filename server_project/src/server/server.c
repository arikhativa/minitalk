/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:11:45 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/09 13:23:54 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	t_error_code	err;
	t_server_meta	meta;

	server_meta(&meta);
	err = server_meta_init(&meta);
	if (SUCCESS != err)
		return (error_code(err));
	ft_printf("%d\n", getpid());
	server_signal_init();
	while (1)
		pause();
	return (SUCCESS);
}
