/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <spalstlr321@naver.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:51:04 by minsikim          #+#    #+#             */
/*   Updated: 2021/02/25 16:29:18 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	handling(char *str, va_list ap, int *count) // start as %++
{
	int		i;

	i = 0;
	while ((str[i]) != 'd' && str[i] != 's' && str[i] != 'c' && str[i] != 'i' &&
	str[i] != 'p' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' && str[i] != '%') // find d, sß
		i++;
	if (str[i] == 'd' || str[i] == 'i')
		handling_d(ap, count, str);
	else if (str[i] == 'c')
		handling_c(ap, count, str);
	else if (str[i] == 's')
		handling_s(ap, count, str);
	else if (str[i] == 'p')
		handling_p(ap, count, str);
	else if (str[i] == 'u')
	 	handling_u(ap, count, str);
	 else if (str[i] == 'x' || str[i] == 'X')
	 	handling_X(ap, count, str);
	else if (str[i] == '%')
		handling_per(ap, count, str);
	i++;
	return (i);
}

int		ft_printf(char *str, ...)
{
	va_list		ap; //pointer
	int			count;

	count = 0;
	va_start(ap, str);//pointer move(to start arg1)
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str = str + handling(str, ap, &count);
		}
		else
			count = count + write(1, str++, 1);
	}
	va_end(ap);//end
	return (count);
}