/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:46:25 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:52:15 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_firstchar(const char *dst, const char *src, size_t n, size_t i)
{
	while (!(dst[i] == src[0]) && i < n && dst[i])
		i++;
	return (i);
}

static int	ft_sameornot(const char *dst, const char *src, size_t n, size_t i)
{
	while (i < n && *src && dst[i])
	{
		if (dst[i] == *src)
		{
			i++;
			src++;
		}
		else
			return (0);
	}
	if (*src)
		return (2);
	return (1);
}

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	char		*ptr;
	size_t		i;

	i = 0;
	if (*src == '\0')
		return ((char *)dst);
	while (i < n)
	{
		i = ft_firstchar(dst, src, n, i);
		ptr = (char *)&dst[i];
		if (ft_sameornot(dst, src, n, i) == 1)
			return (ptr);
		if (ft_sameornot(dst, src, n, i) == 2)
			return (0);
		i++;
	}
	return (0);
}
