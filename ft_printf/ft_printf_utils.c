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

int		wr_count(char cnum, int *count)
{
	write(1, &cnum, 1);
	(*count)++;
	return (1);
}

int		ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (6);
	if (!(*str))
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	typeset(t_type *flag)
{
	flag->reverse = 0;
	flag->zero = 0;
	flag->prec = -1;
	flag->width = 0;
	flag->dot = 0;
	flag->mi = 0;
}
