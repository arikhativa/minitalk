/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:31:00 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/06 17:59:13 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>

# include "input.h"
# include "libft.h"
# include "ft_printf.h"
# include "libminitalk.h"

typedef	struct s_client_meta
{
	int		server_pid;
	char	*mgs;
	int		index;
	int		bit;
	int		con;
}				t_client_meta;

t_client_meta	*clinet_meta(t_client_meta *new);

void			client_signal_init(int pid);
t_error_code	send_str(t_client_meta *m);

#endif
