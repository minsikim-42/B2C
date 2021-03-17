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

#include "ft_printf.h"
//#include <stdarg.h>

void	handling_d(va_list ap, int *count, char *str)
{
	t_type	flag;
	int		num;
	int		rev;

	flag = type_check_d(ap, &str);
	num = va_arg(ap, int);
	if (num < 0)
	{
		num = num * (-1);
		flag.mi = 1;
	}
	printf("reverse = %d, zero = %d, width = %d, prec = %d, num = %d\n", flag.reverse, flag.zero, flag.width, flag.prec, num);
	rev = reverse(flag, -1, num);
	if (/*(flag.zero || flag.prec) &&*/ flag.mi)
		write(1, "-", 1);
	printf("mi = %d", flag.mi);
	zero(flag, num);
	if (flag.prec)
	{
		precision(flag, num);
	}
	*count = *count + count_num(num);
	print_num(num);
	rev = reverse(flag, rev, num);
}

void	handling_c(va_list ap, int *count, char *str)
{
	char	c;
	t_type	flag;

	flag = type_check_s(ap, &str);
	c = va_arg(ap, int);
	if (!(flag.reverse))
		while ((--flag.width))
			write(1, " ", 1);
	write(1, &c, 1);
	printf("reverse = %d, width = %d", flag.reverse, flag.width);
	if (flag.reverse)
		while (--flag.width)
			write(1, " ", 1);
	(*count)++;
}

void	handling_s(va_list ap, int *count, char *str)
{
	char			*s;
	int				rev;
	t_type			flag;
	unsigned int	i;

	flag = type_check_s(ap, &str);
	s = va_arg(ap, char *);
	printf("reverse = %d, zero = %d, width = %d, prec = %d, str = %s, mi = %d\n", flag.reverse, flag.zero, flag.width, flag.prec, s, flag.mi);
	i = 0;
	rev = reverse_s(flag, -1, s, i);
	while (s[i] && i < (unsigned int)flag.prec)
	{
		write(1, &s[i++], 1);
		(*count)++;
	}
	rev = reverse_s(flag, rev, s, i);
}

void	handling_p(va_list ap, int *count)
{
	long long	p;
	//t_type		flag;

	//flag = type_check_s(ap, &str);
	p = va_arg(ap, long long);
	write(1, "0x", 2);
	print_num16(p);
	(*count)++;
}

void	handling_u(va_list ap, int *count, char *str)
{
	t_type			flag;
	unsigned int	num;
	int				rev;

	flag = type_check_d(ap, &str);
	num = va_arg(ap, int);
	flag.mi = 0;
	//printf("reverse = %d, zero = %d, width = %d, prec = %d, num = %u, count_num = %d\n", flag.reverse, flag.zero, flag.width, flag.prec, num, count_num(num));
	rev = reverse(flag, -1, num);
	//printf("mi = %d", flag.mi);
	zero(flag, num);
	if (flag.prec)
	{
		precision(flag, num);
	}
	*count = *count + count_num(num);
	print_num(num);
	rev = reverse(flag, rev, num);
}

void	handling_X(va_list ap, int *count, char *str)
{
	t_type	flag;
	int		num;
	int		rev;

	flag = type_check_d(ap, &str);
	num = va_arg(ap, int);
	if (num < 0)
	{
		num = num * (-1);
		flag.mi = 1;
	}
	//printf("reverse = %d, zero = %d, width = %d, prec = %d, num = %d", flag.reverse, flag.zero, flag.width, flag.prec, num);
	rev = reverse_X(flag, -1, num);
	if (/*(flag.zero || flag.prec) &&*/ flag.mi)
		write(1, "-", 1);
	//printf("mi = %d", flag.mi);
	zero(flag, num);
	if (flag.prec)
	{
		precision_X(flag, num);
	}
	*count = *count + count_num(num);
	print_num16(num);
	rev = reverse_X(flag, rev, num);
}