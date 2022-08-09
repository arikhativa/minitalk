/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:53:54 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/09 13:38:59 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_error_code	input_is_valid(int ac, char **av)
{
	if (3 != ac)
		return (BAD_ARG_EXPECT_TWO);
	if (!av[1][0])
		return (BAD_ARG_MISSING_PID);
	if (!av[2][0])
		return (BAD_ARG_MISSING_MSG);
	return (SUCCESS);
}
