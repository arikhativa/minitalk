/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:22:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/09 13:27:30 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler_one(int sig, siginfo_t *info, void *context)
{
	t_server_meta	*m;
	t_error_code	err;

	m = server_meta(NULL);
	err = add_bit_to_msg(m, 1);
	if (SUCCESS != err)
	{
		kill(info->si_pid, STC_ERROR);
		error_code(err);
		server_meta_free(m);
		exit(err);
	}
	if (ERROR == kill(info->si_pid, STC_CONTINUE))
	{
		error_code(KILL_ERROR);
		exit(KILL_ERROR);
	}
}

void	handler_zero(int sig, siginfo_t *info, void *context)
{
	t_server_meta	*m;
	t_error_code	err;

	m = server_meta(NULL);
	err = add_bit_to_msg(m, 0);
	if (SUCCESS != err)
	{
		kill(info->si_pid, STC_ERROR);
		error_code(err);
		server_meta_free(m);
		exit(err);
	}
	if (TRUE == m->print)
	{
		ft_printf("%s\n", (char *)m->msg);
		server_meta_free(m);
	}
	if (ERROR == kill(info->si_pid, STC_CONTINUE))
	{
		error_code(KILL_ERROR);
		exit(KILL_ERROR);
	}
}

void	server_signal_init(void)
{
	struct sigaction	one;
	struct sigaction	zero;

	one.sa_sigaction = handler_one;
	sigemptyset(&one.sa_mask);
	one.sa_flags = SA_SIGINFO;
	zero.sa_sigaction = handler_zero;
	sigemptyset(&zero.sa_mask);
	zero.sa_flags = SA_SIGINFO;
	sigaction(CTS_ONE, &one, NULL);
	sigaction(CTS_ZERO, &zero, NULL);
}
