// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   signal.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/11 13:24:24 by yoav              #+#    #+#             */
// /*   Updated: 2022/08/11 13:25:48 by yoav             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "signal.h"

// t_error_code	sig_set(void *ptr, int sig)
// {
// 	struct sigaction	*tt = ptr;
// 	t_error_code		err;

// 	err = sigemptyset(&(ptr->sa_mask));
// 	if (SUCCESS != err)
// 		return (SIGEMPTYSET_ERROR);
// 	err = sigaddset(&(ptr->sa_mask), sig);
// 	if (SUCCESS != err)
// 		return (SIGSET_ERROR);
// 	err = sigaction(sig, ptr, NULL);
// 	if (SUCCESS != err)
// 		return (SIGACTION_ERROR);
// 	return (SUCCESS);
// }