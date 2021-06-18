/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <spalstlr321@naver.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:43:22 by minsikim          #+#    #+#             */
/*   Updated: 2021/02/02 13:45:26 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen_n(char *str, int i)
{
	int		count;

	if (str[i] == '\n')
		i++;
	count = 0;
	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}

char	*ft_strdup(char *dst)
{
	char	*p;
	char	*arr;
	int		i;

	i = 0;
	while (dst[i] != 0)
		i++;
	if (!(arr = (char *)malloc(i + 1)))
		return (0);
	p = arr;
	while (*dst != 0)
		*p++ = *dst++;
	*p = 0;
	return (arr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (!(p = (char *)malloc(i + j + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	j = -1;
	while (s2[++j])
		p[i + j] = s2[j];
	p[i + j] = 0;
	return (p);
}

char	*ft_strdup_n(char *str)
{
	int		i;
	char	*p;

	i = 0;
	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!(p = (char *)malloc(i + 1)))
		return (0);
	i = -1;
	while (str[++i] != 0 && str[i] != '\n')
		p[i] = str[i];
	p[i] = 0;
	return (p);
}
