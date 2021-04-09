/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.k>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:19:22 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/09 15:19:57 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	zero(t_type flag, unsigned int num, int *count)
{
	int		i;
	int		j;

	i = 0;
	j = count_num(num, flag);
	if (flag.mi)
		j++;
	if (flag.zero && flag.prec == -1)
	{
		while (flag.width - j > i)
		{
			write(1, "0", 1);
			i++;
			(*count)++;
		}
	}
}

void	zero_16(t_type flag, int num, int *count)
{
	int		i;
	int		j;

	i = 0;
	j = count_num16(num, flag);
	if (flag.mi)
		j++;
	if (flag.zero && flag.prec == -1)
	{
		while (flag.width - j > i)
		{
			write(1, "0", 1);
			i++;
			(*count)++;
		}
	}
}

void	zero_per(t_type flag, int *count)
{
	int		i;

	i = 0;
	if (flag.zero && !(flag.reverse))
	{
		while (flag.width - 1 > i)
		{
			write(1, "0", 1);
			(*count)++;
			i++;
		}
	}
}

void	zero_s(t_type flag, char *str, int *count)
{
	int		len;

	if (flag.zero && !(flag.reverse))
	{
		len = ft_strlen(str);
		while (len < flag.width)
		{
			write(1, "0", 1);
			(*count)++;
			len++;
		}
	}
}
