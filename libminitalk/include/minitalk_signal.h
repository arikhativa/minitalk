/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_signal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:24:53 by yoav              #+#    #+#             */
/*   Updated: 2022/08/11 13:32:11 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_SIGNAL_H
# define MINITALK_SIGNAL_H

# include <signal.h>
# include <unistd.h>

# include "error.h"

t_error_code	sig_set(struct sigaction *ptr, int sig);

#endif
