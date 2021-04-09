/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42seoul.k>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:09:53 by minsikim          #+#    #+#             */
/*   Updated: 2021/04/09 15:09:55 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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
	int		sp;
}				t_type;

void			typeset(t_type *flag);
t_type			flagset1(t_type flag, char **str, int *count);
t_type			flagset1_per(t_type flag, char **str);
t_type			flagset2(t_type flag, va_list ap, char **str);
t_type			flagset3(t_type flag, va_list ap, char **str);
t_type			flagset1_s(t_type flag, char **str, va_list ap);
t_type			flagset2_s(t_type flag, char **str, va_list ap);

int				ft_printf(char *str, ...);
int				ft_strlen(char *str);
void			handling_d(va_list ap, int *count, char *str);
void			handling_c(va_list ap, int *count, char *str);
void			handling_s(va_list ap, int *count, char *str);
void			handling_p(va_list ap, int *count, char *str);
void			handling_u(va_list ap, int *count, char *str);
void			handling_x(va_list ap, int *count, char *str);
void			handling_per(va_list ap, int *count, char *str);
int				count_num(long long num, t_type flag);
int				count_num16(unsigned int num, t_type flag);
int				count_num_x(long long num, int j);

void			print_num(long long num, t_type flag, int *count);
void			print_num16(unsigned int num, t_type flag, char c, int *count);
void			print_num16_p(unsigned long long num,
					t_type flag, char c, int *count);
void			print_num_x(long long num, t_type flag, int *count);
void			print_null(t_type flag, int i, int *count);
int				wr_count(char cnum, int *count);

void			precision(t_type flag, unsigned int num, int *count);
void			precision_x(t_type flag, int num, int *count);
int				reverse(t_type flag, int j, unsigned int num, int *count);
int				reverse_x(t_type flag, int j, int num, int *count);
int				reverse_s(t_type flag, int k, char *str, int *count);
int				reverse_p(t_type flag, int j, int num, int *count);
int				reverse_per(t_type flag, int j, int *count);
void			zero(t_type flag, unsigned int num, int *count);
void			zero_per(t_type flag, int *count);
void			zero_16(t_type flag, int num, int *count);
void			zero_s(t_type flag, char *str, int *count);

t_type			type_check_d(va_list ap, char **str, int *count);
t_type			type_check_per(va_list ap, char **str);
t_type			type_check_s(va_list ap, char **str);
t_type			type_check_c(va_list ap, char **str);

#endif
