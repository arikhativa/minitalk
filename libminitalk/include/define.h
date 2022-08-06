/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:22:39 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/06 14:58:45 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// General
# define EMPTY_STR	""

// Boolean
# define TRUE	1
# define FALSE	(!TRUE)

// File Descriptors
# define STDERROR	2

// Error Codes
typedef enum e_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	BAD_ARG_EXPECT_TWO,
	BAD_ARG_MISSING_MSG,
	BAD_ARG_MISSING_PID
}			t_error_code;

#endif