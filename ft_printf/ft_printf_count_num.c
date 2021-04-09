/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count_num.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.k>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:08:25 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/09 15:08:30 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		count_num16(unsigned int num, t_type flag)
{
	if ((num == 0 && flag.dot == 0) ||
		(num == 0 && flag.dot && flag.prec == -1))
		return (1);
	else if (num == 0 && flag.dot == 1)
		return (0);
	if (num == 0 && flag.dot == 0)
		return (1);
	else if (num == 0 && flag.dot == 1)
		return (0);
	if (num / 16 == 0)
	{
		return (1);
	}
	return (count_num16(num / 16, flag) + 1);
}

int		count_num(long long num, t_type flag)
{
	int		i;

	if ((num == 0 && flag.dot == 0) ||
		(num == 0 && flag.dot && flag.prec == -1))
		return (1);
	else if (num == 0 && flag.dot == 1)
		return (0);
	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int		count_num_x(long long num, int j)
{
	if (num == 0 && j == 0)
		return (1);
	else if (num == 0 && j == 1)
		return (0);
	if (num / 16 == 0)
	{
		return (1);
	}
	return (count_num_x(num / 16, 2) + 1);
}
