/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:53:54 by yoav              #+#    #+#             */
/*   Updated: 2022/08/09 13:54:25 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"

t_error_code	sig_set(struct sigaction *ptr, int sig)
{
	t_error_code		err;

	err = sigemptyset(&(ptr->sa_mask));
	if (SUCCESS != err)
		return (SIGEMPTYSET_ERROR);
	err = sigaddset(&(ptr->sa_mask), sig);
	if (SUCCESS != err)
		return (SIGSET_ERROR);
	err = sigaction(sig, ptr, NULL);
	if (SUCCESS != err)
		return (SIGACTION_ERROR);
	return (SUCCESS);
}
