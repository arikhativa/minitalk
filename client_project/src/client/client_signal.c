/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:22:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/06 18:08:43 by yrabby           ###   ########.fr       */
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

void	client_signal_init(int pid)
{
	struct sigaction	con;
	struct sigaction	err;

	con.sa_sigaction = handler_continue;
	sigemptyset(&con.sa_mask);
	con.sa_flags = SA_SIGINFO;
	err.sa_sigaction = handler_error;
	sigemptyset(&err.sa_mask);
	err.sa_flags = SA_SIGINFO;

	sigaction(STC_CONTINUE, &con, NULL);
	sigaction(STC_ERROR, &err, NULL);
}
