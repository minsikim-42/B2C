/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:57:16 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:51:00 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tempdest;
	unsigned char	*tempsrc;
	size_t			i;

	i = 0;
	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	while (i < n)
	{
		if (tempsrc[i] == (unsigned char)c)
		{
			tempdest[i] = tempsrc[i];
			return (&tempdest[i + 1]);
		}
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (0);
}
