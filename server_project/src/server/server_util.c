/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:36:44 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/12 19:12:34 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

#include <stdio.h>

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
	if (m->index == m->len)
	{
		tmp = m->msg;
		m->msg = ft_calloc(((m->len * 2) + 1), sizeof(unsigned char));
		if (!m->msg)
		{
			free(tmp);
			return (FAILED_TO_EXTEND_MSG);
		}
		ft_memcpy(m->msg, tmp, (m->index));
		m->msg[m->index] = 0;
		m->len = (m->len * 2);
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
