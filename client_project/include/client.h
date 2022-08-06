/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:31:00 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/06 15:48:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>

# include "input.h"
# include "ft_printf.h"
# include "libminitalk.h"

typedef	struct s_client_meta
{
	int	server_pid;
}				t_client_meta;


void	client_signal_init(int pid);
t_error_code	send_str(t_client_meta *m, char *s);

#endif
