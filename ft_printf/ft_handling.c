/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <spalstlr321@naver.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:55:28 by minsikim          #+#    #+#             */
/*   Updated: 2021/02/25 16:04:36 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handling_d(va_list ap, int *count, char *str)
{
	t_type	flag;
	int		num;
	int		rev;

	flag = type_check_d(ap, &str, count);
	num = va_arg(ap, int);
	if (num < 0)
	{
		num = num * (-1); //
		flag.mi = 1;
		(*count)++;
	}
	rev = reverse(flag, -1, num, count);
	if (flag.mi)
		write(1, "-", 1);
	zero(flag, num, count);
	if (flag.prec)
		precision(flag, num, count);
	print_num(num, flag, count);
	rev = reverse(flag, rev, num, count);
}

void	handling_c(va_list ap, int *count, char *str)
{
	char	c;
	t_type	flag;

	flag = type_check_s(ap, &str);
	c = va_arg(ap, int);
	if (!(flag.reverse))
		while ((--flag.width) > 0)
		{
			write(1, " ", 1);
			(*count)++;
		}
	write(1, &c, 1);
	(*count)++;
	if (flag.reverse)
	{
		while (--flag.width > 0)
		{
			write(1, " ", 1);
			(*count)++;
		}
	}
}

void	handling_s(va_list ap, int *count, char *str)
{
	char			*s;
	int				rev;
	t_type			flag;
	unsigned int	i;

	flag = type_check_s(ap, &str);
	s = va_arg(ap, char *);
	i = 0;
	rev = reverse_s(flag, -1, s, count);
	if (!s)
	{
		print_null(flag, i, count);
	}
	else
	{
		zero_s(flag, s, count);
		while (s[i] && i < (unsigned int)flag.prec)
		{
			write(1, &s[i++], 1);
			(*count)++;
		}
	}
	rev = reverse_s(flag, rev, s, count);
}
