/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:22:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/07 16:15:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_error_code	extend_msg_if_needed(t_server_meta *m)
{
	t_error_code	err;
	unsigned char	*tmp;

	if (0 == m->len)
	{
		err = server_meta_init(m);
		if (SUCCESS != err)
			return (err);
	}
	if (m->index >= m->len)
	{
		tmp = m->msg;
		m->msg = ft_calloc(((m->len * 2) + 1), sizeof(unsigned char));
		if (!m->msg)
		{
			free(tmp);
			return (FAILED_TO_EXTEND_MSG);
		}
		ft_memcmp(m->msg, tmp, m->len);
		m->len = m->len * 2;
		free(tmp);
		tmp = NULL;
	}
	return (SUCCESS);
}

void	add_bit_to_char(t_server_meta *m, unsigned char bit)
{
	m->byte |= (bit << m->bit);
	++m->bit;
}

void	add_char_to_msg(t_server_meta *m)
{
	if (m->bit == BYTE_SIZE)
	{
		m->msg[m->index] = m->byte;
		if ('\0' == m->byte)
			m->print = TRUE;
		++m->index;
		m->bit = 0;
		m->byte = 0;
	}
}

t_error_code	add_bit_to_msg(t_server_meta *m, int bit)
{
	t_error_code	err;

	err = extend_msg_if_needed(m);
	if (SUCCESS != err)
		return (err);
	add_bit_to_char(m, bit);
	add_char_to_msg(m);
	return (SUCCESS);
}

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
