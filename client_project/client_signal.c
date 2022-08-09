/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:22:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/09 13:56:25 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	handler_continue(int sig, siginfo_t *info, void *context)
{
	t_client_meta	*m;

	m = clinet_meta(NULL);
	m->con = TRUE;
	(void)sig;
	(void)info;
	(void)context;
}

void	handler_error(int sig, siginfo_t *info, void *context)
{
	ft_printf("clinet: server error\nserver pid: %d\n", info->si_pid);
}

t_error_code	client_signal_init(int pid)
{
	t_error_code		error_code;
	struct sigaction	con;
	struct sigaction	err;

	con.sa_sigaction = handler_continue;
	con.sa_flags = SA_SIGINFO;
	err.sa_sigaction = handler_error;
	err.sa_flags = SA_SIGINFO;
	error_code = sg_set(&con, STC_CONTINUE);
	if (SUCCESS != error_code)
		return (error_code);
	error_code = sig_set(&err, STC_ERROR);
	if (SUCCESS != error_code)
		return (error_code);
	return (SUCCESS);
}
