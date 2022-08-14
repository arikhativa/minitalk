/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:29:37 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/11 13:29:43 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int ac, char **av)
{
	t_error_code	err;
	t_client_meta	meta;
	t_client_meta	*ptr;

	err = input_is_valid(ac, av);
	if (SUCCESS != err)
		return (error_code(err));
	ptr = clinet_meta(&meta);
	ptr->server_pid = ft_atoi(av[1]);
	ptr->mgs = av[2];
	err = client_signal_init();
	if (SUCCESS != err)
		return (error_code(err));
	err = send_str(clinet_meta(NULL));
	if (SUCCESS != err)
		return (error_code(err));
	return (SUCCESS);
}
