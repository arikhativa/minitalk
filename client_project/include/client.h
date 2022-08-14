/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:31:00 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/14 12:18:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# include "libft.h"
# include "ft_printf.h"
# include "error.h"
# include "minitalk_signal.h"

typedef struct s_client_meta
{
	int				server_pid;
	char			*mgs;
	int				index;
	unsigned char	bit;
	int				con;
}				t_client_meta;

t_client_meta	*clinet_meta(t_client_meta *new);
t_error_code	client_signal_init(void);
t_error_code	send_str(t_client_meta *m);
t_error_code	input_is_valid(int ac, char **av);

#endif
