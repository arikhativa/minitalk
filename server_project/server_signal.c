/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:22:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/09 14:20:44 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "server.h"

#include <signal.h>
#include <unistd.h>
#include <zconf.h>
#include <stdlib.h>

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

t_error_code	server_signal_init(void)
{
	t_error_code		err;
	struct sigaction	one;
	struct sigaction	zero;

	one.sa_sigaction = handler_one;
	one.sa_flags = SA_SIGINFO;
	zero.sa_sigaction = handler_zero;
	zero.sa_flags = SA_SIGINFO;
	err = sig_set(&zero, CTS_ZERO);
	if (SUCCESS != err)
		return (err);
	err = sig_set(&one, CTS_ONE);
	if (SUCCESS != err)
		return (err);
	return (SUCCESS);
}
