/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.k>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:17:57 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/09 15:17:58 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		reverse(t_type flag, int j, unsigned int num, int *count)
{
	int		i;

	if (j < 0 && flag.reverse)
		return (1);
	if (j == 1 && flag.reverse != 1)
		return (0);
	if ((flag.width - flag.prec <= 0) || (flag.prec == -1 && flag.zero))
		return (1);
	i = (flag.prec > count_num(num, flag)) ?
		(flag.prec) : (count_num(num, flag));
	if (flag.mi == 1)
		i++;
	if (flag.width > i)
	{
		while (i < flag.width)
		{
			write(1, " ", 1);
			i++;
			(*count)++;
		}
		return (1);
	}
	return (0);
}

int		reverse_x(t_type flag, int j, int num, int *count)
{
	int		i;

	i = 0;
	if (j < 0 && flag.reverse)
		return (1);
	if (j == 1 && flag.reverse != 1)
		return (0);
	if ((flag.width - flag.prec <= 0) || (flag.prec == -1 && flag.zero))
		return (1);
	i = (flag.prec > count_num16(num, flag)) ?
		(flag.prec) : (count_num16(num, flag));
	if (j == 1 && flag.reverse != 1)
		return (0);
	if (i < flag.width)
	{
		while ((i++) < flag.width)
		{
			write(1, " ", 1);
			(*count)++;
		}
		return (1);
	}
	return (0);
}

int		reverse_s(t_type flag, int k, char *str, int *count)
{
	int		i;

	if (k < 0 && (flag.reverse || flag.zero))
		return (1);
	if (k == 1 && !(flag.reverse))
		return (0);
	i = (flag.prec >= 0 && flag.prec < ft_strlen(str))
		? (flag.prec) : (ft_strlen(str));
	if (flag.width > i)
	{
		while (i < flag.width)
		{
			write(1, " ", 1);
			i++;
			(*count)++;
		}
		return (1);
	}
	return (0);
}

int		reverse_per(t_type flag, int j, int *count)
{
	int		i;

	i = 0;
	if (j < 0 && (flag.reverse || flag.zero))
		return (1);
	if (j == 1 && !(flag.reverse))
		return (0);
	if (1 + i < flag.width)
	{
		while (1 + (i++) < flag.width)
		{
			write(1, " ", 1);
			(*count)++;
		}
		return (1);
	}
	return (0);
}

int		reverse_p(t_type flag, int j, int num, int *count)
{
	int		i;

	i = 0;
	if (j < 0 && (flag.reverse || flag.zero))
		return (1);
	if (j == 1 && !(flag.reverse))
		return (0);
	if (1 + i < flag.width)
	{
		while (num + 2 + (i++) < flag.width)
		{
			write(1, " ", 1);
			(*count)++;
		}
		return (1);
	}
	return (0);
}
