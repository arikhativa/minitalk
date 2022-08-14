/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:23:44 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/14 12:21:14 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# include "error.h"
# include "define.h"
# include "libft.h"
# include "minitalk_signal.h"
# include "ft_printf.h"

typedef struct s_server_meta
{
	unsigned char	*msg;
	int				len;
	int				index;
	int				print;
	unsigned char	bit;
	unsigned char	byte;
	int				current_client;
	int				mid_msg;
}				t_server_meta;

t_server_meta	*server_meta(t_server_meta *new);
t_error_code	server_meta_init(t_server_meta *m);
void			server_meta_free(t_server_meta *m);
t_error_code	server_signal_init(void);
t_error_code	add_bit_to_msg(t_server_meta *m, int bit);

#endif
