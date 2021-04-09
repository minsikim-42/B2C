/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flagset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.k>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:09:08 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/09 15:09:10 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_type	flagset1(t_type flag, char **str, int *count)
{
	while (**str == '0' || **str == '-' || **str == ' ')
	{
		if (**str == '0')
		{
			flag.zero = 1;
			(*str)++;
		}
		else if (**str == ' ')
		{
			flag.sp++;
			(*str)++;
			wr_count(' ', count);
		}
		else
		{
			flag.reverse = 1;
			(*str)++;
		}
	}
	return (flag);
}

t_type	flagset2(t_type flag, va_list ap, char **str)
{
	if (flag.zero && flag.reverse)
		flag.zero = 0;
	if (**str == '*')
	{
		flag.width = va_arg(ap, int);
		(*str)++;
		if (flag.width < 0)
		{
			flag.width = flag.width * (-1);
			flag.reverse = 1;
			flag.zero = 0;
		}
	}
	else
	{
		while (**str >= '0' && **str <= '9')
		{
			flag.width = flag.width * 10 + (int)**str - 48;
			(*str)++;
		}
	}
	if (flag.width - flag.sp > 0 && flag.sp)
		flag.width = flag.width - flag.sp;
	return (flag);
}

t_type	flagset3(t_type flag, va_list ap, char **str)
{
	while (**str == '.')
	{
		flag.dot = 1;
		(*str)++;
		flag.prec = 0;
	}
	if (**str == '*')
	{
		flag.prec = va_arg(ap, int);
		(*str)++;
		if (flag.prec < 0)
			flag.prec = -1;
	}
	while (**str >= '0' && **str <= '9')
	{
		if (flag.prec < 0)
			flag.prec = 0;
		flag.prec = flag.prec * 10 + (int)**str - '0';
		(*str)++;
	}
	return (flag);
}

t_type	flagset1_s(t_type flag, char **str, va_list ap)
{
	while (**str == '-')
	{
		flag.reverse = 1;
		(*str)++;
	}
	while (**str == '0')
	{
		flag.zero = 1;
		(*str)++;
	}
	if (**str == '*')
	{
		flag.width = va_arg(ap, int);
		(*str)++;
	}
	else
	{
		while (**str >= '0' && **str <= '9')
		{
			flag.width = flag.width * 10 + (int)**str - 48;
			(*str)++;
		}
	}
	return (flag);
}

t_type	flagset2_s(t_type flag, char **str, va_list ap)
{
	if (flag.width < 0)
	{
		flag.width = flag.width * (-1);
		flag.reverse = 1;
		flag.zero = 0;
	}
	while (**str == '.')
	{
		flag.dot = 1;
		flag.prec = 0;
		(*str)++;
	}
	if (**str == '*')
	{
		flag.prec = va_arg(ap, int);
		(*str)++;
		if (flag.prec < 0)
			flag.prec = -1;
	}
	return (flag);
}
