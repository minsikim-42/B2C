/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <spalstlr321@naver.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:29:17 by minsikim          #+#    #+#             */
/*   Updated: 2021/02/25 16:03:35 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_type
{
	int		reverse;
	int		zero;
	int		prec;
	int		width;
	int		dot;
	int		mi;
}				t_type;

int		ft_printf(char *str, ...);
int		ft_strlen(char *str);
void	handling_d(va_list ap, int *count, char *str);
void	handling_c(va_list ap, int *count, char *str);
void	handling_s(va_list ap, int *count, char *str);
void	handling_p(va_list ap, int *count);
void	handling_u(va_list ap, int *count, char *str);
void	handling_X(va_list ap, int *count, char *str);
int		count_num(long long num);
int		count_num16(long long num);
void	print_num(long long num);
void	print_num16(long long num);
void	precision(t_type flag, unsigned int num);
void	precision_X(t_type flag, int num);
int		reverse(t_type flag, int count, unsigned int num);
int		reverse_X(t_type flag, int count, int num);
int     reverse_s(t_type flag, int count, char *str, int j);
void    zero(t_type flag, int num);

t_type	type_check_d(va_list ap, char **str);
t_type	type_check_s(va_list ap, char **str);
t_type	type_check_c(va_list ap, char **str);

#endif
