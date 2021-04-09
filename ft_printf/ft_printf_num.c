/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:00:32 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/07 22:04:11 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_num(long long num, t_type flag, int *count)
{
	char	cnum;

	if ((num == 0 && flag.dot == 0) ||
		(num == 0 && flag.dot && flag.prec == -1))
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	else if (num == 0 && flag.dot == 1)
		return ;
	cnum = (char)(num % 10);
	if (cnum < 0)
		cnum = cnum * (-1);
	cnum = cnum + '0';
	if (num / 10 == 0)
	{
		write(1, &cnum, 1);
		(*count)++;
		return ;
	}
	print_num(num / 10, flag, count);
	write(1, &cnum, 1);
	(*count)++;
}

void	print_num_x(long long num, t_type flag, int *count)
{
	char	cnum;

	if ((num == 0 && flag.dot == 0))
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	else if (num == 0 && flag.dot == 1)
		return ;
	cnum = (char)(num % 10);
	if (cnum < 0)
		cnum = cnum * (-1);
	cnum = cnum + '0';
	if (num / 10 == 0)
	{
		write(1, &cnum, 1);
		(*count)++;
		return ;
	}
	print_num(num / 10, flag, count);
	write(1, &cnum, 1);
	(*count)++;
}

void	print_num16(unsigned int num, t_type flag, char c, int *count)
{
	char	cnum;

	if ((num == 0 && flag.dot == 0) ||
		(num == 0 && flag.dot && flag.prec == -1))
		if (wr_count('0', count))
			return ;
	if (num == 0 && flag.dot == 1)
		return ;
	if (c != 'x' && c != 'X')
		c = c + 23;
	if (num == 0 && flag.dot == 0)
		if (wr_count('0', count))
			return ;
	if (num == 0 && flag.dot == 1)
		return ;
	if (num % 16 < 10)
		cnum = (num % 16) + '0';
	else
		cnum = (num % 16) - 10 - 23 + c;
	if (num / 16 == 0)
		if (wr_count(cnum, count))
			return ;
	print_num16(num / 16, flag, c, count);
	write(1, &cnum, 1);
	(*count)++;
}

void	print_num16_p(unsigned long long num, t_type flag, char c, int *count)
{
	char	cnum;

	if ((num == 0 && flag.dot == 0) ||
		(num == 0 && flag.dot && flag.prec == -1))
		if (wr_count('0', count))
			return ;
	if (num == 0 && flag.dot == 1)
		return ;
	if (c != 'x' && c != 'X')
		c = c + 23;
	if (num == 0 && flag.dot == 0)
		if (wr_count('0', count))
			return ;
	if (num == 0 && flag.dot == 1)
		return ;
	if (num % 16 < 10)
		cnum = (num % 16) + '0';
	else
		cnum = (num % 16) - 10 - 23 + c;
	if (num / 16 == 0)
		if (wr_count(cnum, count))
			return ;
	print_num16_p(num / 16, flag, c, count);
	wr_count(cnum, count);
}

void	print_null(t_type flag, int i, int *count)
{
	char	*null;

	null = "(null)\0";
	while (null[i] && (unsigned int)i < (unsigned int)flag.prec)
	{
		write(1, &null[i++], 1);
		(*count)++;
	}
}
