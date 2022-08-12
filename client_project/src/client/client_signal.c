/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:22:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/12 18:47:16 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	handler_continue(int sig, siginfo_t *info, void *context)
{
	t_client_meta	*m;

	(void)sig;
	(void)info;
	(void)context;
	m = clinet_meta(NULL);
	if (m->server_pid == info->si_pid)
		m->con = TRUE;
}

void	handler_error(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	error_code(SERVER_ERROR);
	exit(SERVER_ERROR);
}

t_error_code	client_signal_init(void)
{
	t_error_code		error_code;
	struct sigaction	con;
	struct sigaction	err;

	con.sa_sigaction = handler_continue;
	con.sa_flags = SA_SIGINFO;
	err.sa_sigaction = handler_error;
	err.sa_flags = SA_SIGINFO;
	error_code = sig_set(&con, STC_CONTINUE);
	if (SUCCESS != error_code)
		return (error_code);
	error_code = sig_set(&err, STC_ERROR);
	if (SUCCESS != error_code)
		return (error_code);
	return (SUCCESS);
}
