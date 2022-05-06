/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:59:07 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:47:32 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_reslen(long long n)
{
	int			count;
	int			minus;
	int			reslen;

	minus = 0;
	if (n < 0)
		minus = 1;
	count = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	reslen = count + minus;
	return (reslen);
}

char	*ft_itoa(int n)
{
	long long	tempn;
	char		*res;
	int			reslen;

	tempn = (long long)n;
	reslen = ft_count_reslen(tempn);
	res = malloc(reslen + 1);
	if (!res)
		return (0);
	if (tempn < 0)
	{
		res[0] = '-';
		tempn *= -1;
	}
	res[reslen--] = '\0';
	while (tempn / 10 != 0)
	{
		res[reslen] = (tempn % 10) + '0';
		tempn = tempn / 10;
		reslen--;
	}
	res[reslen] = tempn + '0';
	return (res);
}
