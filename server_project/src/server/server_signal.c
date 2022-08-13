/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:22:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/13 17:24:41 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	is_valid_clinet(t_server_meta *m, int pid)
{
	if (FALSE == m->mid_msg)
	{
		m->mid_msg = TRUE;
		m->current_client = pid;
	}
	else if (m->current_client != pid)
	{
		kill(m->current_client, STC_ERROR);
		return (UNKNOWN_PID);
	}
	return (SUCCESS);
}

static void	generic_handler(t_server_meta *m, int sig_pid, int bit)
{
	t_error_code	err;

	err = is_valid_clinet(m, sig_pid);
	if (SUCCESS != err)
	{
		error_code(err);
		exit(err);
	}
	err = add_bit_to_msg(m, bit);
	if (SUCCESS != err)
	{
		kill(m->current_client, STC_ERROR);
		error_code(err);
		server_meta_free(m);
		exit(err);
	}
	if (ERROR == kill(m->current_client, STC_CONTINUE))
	{
		error_code(KILL_ERROR);
		exit(KILL_ERROR);
	}
}

void	handler_one(int sig, siginfo_t *info, void *context)
{
	t_server_meta	*m;

	(void)sig;
	(void)context;
	m = server_meta(NULL);
	generic_handler(m, info->si_pid, ONE);
}

void	handler_zero(int sig, siginfo_t *info, void *context)
{
	t_server_meta	*m;

	(void)sig;
	(void)context;
	m = server_meta(NULL);
	generic_handler(m, info->si_pid, ZERO);
	if (TRUE == m->print)
	{
		ft_printf("%s\n", (char *)m->msg);
		server_meta_free(m);
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
	err = sig_set(&one, CTS_ONE);
	if (SUCCESS != err)
		return (err);
	err = sig_set(&zero, CTS_ZERO);
	if (SUCCESS != err)
		return (err);
	return (SUCCESS);
}
