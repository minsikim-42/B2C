/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.k>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:41:14 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/08 18:41:18 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_type	type_check_d(va_list ap, char **str, int *count)
{
	t_type	flag;

	typeset(&flag);
	flag = flagset1(flag, str, count);
	flag = flagset2(flag, ap, str);
	flag = flagset3(flag, ap, str);
	return (flag);
}

t_type	type_check_s(va_list ap, char **str)
{
	t_type	flag;

	typeset(&flag);
	flag = flagset1_s(flag, str, ap);
	flag = flagset2_s(flag, str, ap);
	while (**str >= '0' && **str <= '9')
	{
		if (flag.prec < 0)
			flag.prec = 0;
		flag.prec = flag.prec * 10 + (int)**str - '0';
		(*str)++;
	}
	return (flag);
}

void	precision(t_type flag, unsigned int num, int *count)
{
	int		i;

	if (flag.prec < 0)
		return ;
	i = count_num(num, flag);
	if (flag.prec > i)
	{
		while (i < flag.prec)
		{
			write(1, "0", 1);
			i++;
			(*count)++;
		}
	}
}

void	precision_x(t_type flag, int num, int *count)
{
	int		i;

	if (flag.prec < 0)
		return ;
	i = count_num16((unsigned int)num, flag);
	if (flag.prec > i)
	{
		while (i < flag.prec)
		{
			write(1, "0", 1);
			(*count)++;
			i++;
		}
	}
}
