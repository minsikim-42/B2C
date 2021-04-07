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
void	handling_p(va_list ap, int *count, char *str);
void	handling_u(va_list ap, int *count, char *str);
void	handling_X(va_list ap, int *count, char *str);
void	handling_per(va_list ap, int *count, char *str);
int		count_num(long long num, t_type flag);
int		count_num16(unsigned int num, t_type flag);
int     count_num_x(long long num, int j); //
void	print_num(long long num, t_type flag, int *count);
void	print_num16(unsigned int num, t_type flag, char c, int *count);
void    print_num16_p(unsigned long long num, t_type flag, char c, int *count);
void    print_num_x(long long num, t_type flag, int *count); //
void	precision(t_type flag, unsigned int num, int *count);
void	precision_X(t_type flag, int num, int *count);
int		reverse(t_type flag, int j, unsigned int num, int *count);
int		reverse_X(t_type flag, int j, int num, int *count);
int     reverse_s(t_type flag, int k, char *str, int *count);
int     reverse_p(t_type flag, int j, int num, int *count);
int     reverse_per(t_type flag, int j, int *count);
void    zero(t_type flag, unsigned int num, int *count);
void    zero_per(t_type flag, int *count);
void    zero_16(t_type flag, int num, int *count);
void    zero_s(t_type flag, char *str, int *count);
t_type	type_check_d(va_list ap, char **str, int *count);
t_type	type_check_s(va_list ap, char **str);
t_type	type_check_c(va_list ap, char **str);

#endif
