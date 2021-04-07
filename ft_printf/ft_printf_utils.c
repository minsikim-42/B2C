/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:00:32 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/02 21:09:23 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_num(long long num, t_type flag, int *count)
{
	char	cnum;

	if ((num == 0 && flag.dot == 0) || (num == 0 && flag.dot && flag.prec == -1))
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
	char    cnum;

	if ((num == 0 && flag.dot == 0) || (num == 0 && flag.dot && flag.prec == -1))
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	else if (num == 0 && flag.dot == 1)
		return ;
	if (c != 'x' && c != 'X') // if *str(%x, %X, %a(per)) == 'a'(a = 97, +23, x = 120)
		c = c + 23;
	if (num == 0 && flag.dot == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	else if (num == 0 && flag.dot == 1)
		return ;
	if (num % 16 < 10)
		cnum = (num % 16) + '0'; // 7 char 7 char '7' 48>0 49>1
	else
		cnum = (num % 16) - 10 - 23 + c;
	if (num / 16 == 0)
	{
		write(1, &cnum, 1);
		(*count)++;
		return ;
	}
	print_num16(num / 16, flag, c, count);
	write(1, &cnum, 1);
	(*count)++;
}

void	print_num16_p(unsigned long long num, t_type flag, char c, int *count)
{
	char	cnum;

	if ((num == 0 && flag.dot == 0) || (num == 0 && flag.dot && flag.prec == -1))
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	else if (num == 0 && flag.dot == 1)
		return ;
	if (c != 'x' && c != 'X') // if *str(%x, %X, %a(per)) == 'a'(a = 97, +23, x = 120)
		c = c + 23;
	if (num == 0 && flag.dot == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	else if (num == 0 && flag.dot == 1)
		return ;
	if (num % 16 < 10)
		cnum = (num % 16) + '0'; // 7 char '7' 48>0 49>1
	else
		cnum = (num % 16) - 10 - 23 + c;
	if (num / 16 == 0)
	{
		write(1, &cnum, 1);
		(*count)++;
		return ;
	}
	print_num16_p(num / 16, flag, c, count);
	write(1, &cnum, 1);
	(*count)++;
}

int		count_num16(unsigned int num, t_type flag)
{
	if ((num == 0 && flag.dot == 0) || (num == 0 && flag.dot && flag.prec == -1))
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
	int     i;

	if ((num == 0 && flag.dot == 0) || (num == 0 && flag.dot && flag.prec == -1))
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

int		ft_strlen(char *str)
{
	int     i;

	if (!str)
		return (6);
	if (!(*str))
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
