/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:40:35 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:52:26 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_setornot(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_fill_res(char const *s1, char *res, int size, int i)
{
	int	j;

	j = 0;
	while (j < size)
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	res[size] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	int			front;
	int			lastidx;
	int			reslen;

	if (!s1 || !set)
		return (0);
	front = 0;
	lastidx = ft_strlen(s1) - 1;
	while (s1[front] && ft_setornot(s1[front], set) == 1)
		front++;
	while (0 <= lastidx && ft_setornot(s1[lastidx], set) == 1)
		lastidx--;
	reslen = lastidx - front + 1;
	if (reslen < 0)
		reslen = 0;
	res = malloc(sizeof(char) * reslen + 1);
	if (!res)
		return (0);
	return (ft_fill_res(s1, res, reslen, front));
}
