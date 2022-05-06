/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:59:54 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:50:51 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*src;

	dst = (char *)malloc(len + 1);
	if (!s || !dst)
		return (0);
	if (start < ft_strlen(s))
	{
		src = (char *)&s[start];
		dst[len] = '\0';
		while (len--)
			dst[len] = src[len];
	}
	else
		*dst = '\0';
	return (dst);
}
