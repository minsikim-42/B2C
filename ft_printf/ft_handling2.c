/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.k>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:14:01 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/09 15:14:05 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handling_p(va_list ap, int *count, char *str)
{
	unsigned long long	p;
	t_type				flag;
	int					rev;
	int					num;

	flag = type_check_d(ap, &str, count);
	p = va_arg(ap, unsigned long long);
	num = count_num_x(p, flag.dot);
	rev = reverse_p(flag, -1, num, count);
	write(1, "0x", 2);
	precision_x(flag, p, count);
	print_num16_p(p, flag, 'a', count);
	rev = reverse_p(flag, rev, num, count);
	(*count) = (*count) + 2;
}

void	handling_u(va_list ap, int *count, char *str)
{
	t_type			flag;
	unsigned int	num;
	int				rev;

	flag = type_check_d(ap, &str, count);
	num = va_arg(ap, unsigned int);
	flag.mi = 0;
	rev = reverse(flag, -1, num, count);
	zero(flag, num, count);
	if (flag.prec)
	{
		precision(flag, num, count);
	}
	print_num(num, flag, count);
	rev = reverse(flag, rev, num, count);
}

void	handling_x(va_list ap, int *count, char *str)
{
	t_type			flag;
	unsigned int	num;
	int				rev;

	flag = type_check_d(ap, &str, count);
	num = va_arg(ap, unsigned int);
	rev = reverse_x(flag, -1, num, count);
	zero_16(flag, num, count);
	if (flag.prec)
	{
		precision_x(flag, num, count);
	}
	print_num16(num, flag, *str, count);
	rev = reverse_x(flag, rev, num, count);
}

void	handling_per(va_list ap, int *count, char *str)
{
	t_type	flag;
	int		rev;

	flag = type_check_per(ap, &str);
	rev = reverse_per(flag, -1, count);
	zero_per(flag, count);
	write(1, "%", 1);
	(*count)++;
	rev = reverse_per(flag, rev, count);
}
