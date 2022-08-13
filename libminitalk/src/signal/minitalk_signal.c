/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:24 by yoav              #+#    #+#             */
/*   Updated: 2022/08/13 17:20:09 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_signal.h"

t_error_code	sig_set(struct sigaction *ptr, int sig)
{
	t_error_code		err;

	err = sigemptyset(&(ptr->sa_mask));
	if (SUCCESS != err)
		return (SIGEMPTYSET_ERROR);
	err = sigaction(sig, ptr, NULL);
	if (SUCCESS != err)
		return (SIGACTION_ERROR);
	return (SUCCESS);
}
