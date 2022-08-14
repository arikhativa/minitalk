/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:11:45 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/11 13:35:26 by yoav             ###   ########.fr       */
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
	err = server_signal_init();
	if (SUCCESS != err)
		return (error_code(err));
	while (1)
		pause();
	return (SUCCESS);
}
