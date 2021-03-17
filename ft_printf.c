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

#include "ft_printf.h"
//#include <stdarg.h>

/*type	find_type(char *str, int i)
{
	if (str[i + 1] == 0)
		return (0);
	else if (str[i + 1] == 'c')r
		return (char);
	else if (str[i + 1] == 's')
		return (char *);
	else if (str[i + 1] == 'p')
		return (long long);
	else if (str[i + 1] == 'd')
		return (int);
	else if (str[i + 1] == 'u')
		return (unsigned int);
	else
		return (unsigned int);

}*/

int 	handling(char *str, va_list ap, int *count) // start as %++
{
	int		i;

	i = 0;
	while ((str[i]) != 'd' && str[i] != 's' && str[i] != 'c' &&
	str[i] != 'p' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' && str[i] != '%') // find d, sß
		i++;
	if (str[i] == 'd')
		handling_d(ap, count, str);
	else if (str[i] == 'c')
		handling_c(ap, count, str);
	else if (str[i] == 's')
		handling_s(ap, count, str);
	else if (str[i] == 'p')
		handling_p(ap, count);
	else if (str[i] == 'u')
	 	handling_u(ap, count, str);
	 else if (str[i] == 'x' || str[i] == 'X')
	 	handling_X(ap, count, str);
	else if (str[i] == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
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
	//va_arg(ap, find_type(str, count));//va_arg(char*, type);
	va_end(ap);//end
	return (count);
}
/*
int main(){
	int i = printf("hi %s %02djeim ", "abc", 23);
	ft_printf("%d", i);
}*/