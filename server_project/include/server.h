/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:23:44 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/06 15:34:36 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>

# include "define.h"
# include "ft_printf.h"

void	server_handler(int sig, siginfo_t *info, void *context);
void	server_signal_init(int pid);

#endif