/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:16:37 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:52:12 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (n > 0 && (s1[i] || s2[i]))
	{
		if (s1[i] == s2[i])
		{
			i++;
			n--;
		}
		else if (s1[i] > s2[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}
