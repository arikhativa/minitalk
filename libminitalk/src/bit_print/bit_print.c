/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:15:58 by yrabby            #+#    #+#             */
/*   Updated: 2022/08/07 16:16:07 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bit_print(unsigned char c)
{
	int	i = 0;
	unsigned char mask = (1 << 7);

	while (i < 8)
	{
		ft_printf("%d", (!!(c & mask)));
		mask >>= 1;
		++i;
	}
	ft_printf("\n");
}
