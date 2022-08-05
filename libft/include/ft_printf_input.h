/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:14:00 by yoav              #+#    #+#             */
/*   Updated: 2022/07/26 17:14:01 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INPUT_H
# define FT_PRINTF_INPUT_H

# include <stdarg.h>

# include "libft.h"

int			is_escp(const char *s);
const char	*skip_escp(const char *s);
int			is_flag(const char *s);
int			parse_input(const char *input, t_list **node, va_list list);
size_t		count_normal_char_len(const char *s);

#endif
