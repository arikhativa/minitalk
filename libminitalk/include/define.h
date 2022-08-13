/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:22:39 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/13 17:23:59 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <signal.h>

// Bit Operation
# define BYTE_SIZE	8
# define ONE		(0x01)
# define ZERO		(0x00)

// General
# define DEFAULT_MSG_LEN	10000

// Boolean
# define TRUE	1
# define FALSE	(!TRUE)

// File Descriptors
# define STDERROR	2

// Signals
# define CTS_ONE		(SIGUSR1)
# define CTS_ZERO		(SIGUSR2)
# define STC_CONTINUE	(SIGUSR1)
# define STC_ERROR		(SIGUSR2)

// Error Codes
typedef enum e_error_code
{
	ERROR = -1,
	SUCCESS = 0,
	BAD_ARG_EXPECT_TWO,
	BAD_ARG_MISSING_MSG,
	BAD_ARG_MISSING_PID,
	KILL_ERROR,
	FAILED_TO_INIT_SERVER,
	FAILED_TO_EXTEND_MSG,
	SIGADDSET_ERROR,
	SIGACTION_ERROR,
	SIGEMPTYSET_ERROR,
	SERVER_ERROR,
	UNKNOWN_PID
}			t_error_code;

#endif