/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:38:17 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/12 18:15:51 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static inline void	error_print(char *s)
{
	ft_putstr_fd(s, STDERROR);
}

void	error_code_print(t_error_code err)
{
	if (BAD_ARG_EXPECT_TWO == err)
		error_print("BAD_ARG_EXPECT_TWO\n");
	else if (BAD_ARG_MISSING_PID == err)
		error_print("BAD_ARG_MISSING_PID\n");
	else if (BAD_ARG_MISSING_MSG == err)
		error_print("BAD_ARG_MISSING_MSG\n");
	else if (KILL_ERROR == err)
		error_print("KILL_ERROR\n");
	else if (FAILED_TO_INIT_SERVER == err)
		error_print("FAILED_TO_INIT_SERVER\n");
	else if (FAILED_TO_EXTEND_MSG == err)
		error_print("FAILED_TO_EXTEND_MSG\n");
	else if (SERVER_ERROR == err)
		error_print("SERVER_ERROR\n");
	else if (UNKNOWN_PID == err)
		error_print("UNKNOWN_PID\n");
	else
		error_print("Unknown error code\n");
}

t_error_code	error_code(t_error_code err)
{
	error_code_print(err);
	return (err);
}
