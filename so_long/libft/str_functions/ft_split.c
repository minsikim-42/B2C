/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybong <ybong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 01:38:18 by ybong             #+#    #+#             */
/*   Updated: 2021/07/04 20:51:50 by ybong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_height(char const *s, char c)
{
	int		count;

	count = 0;
	if (*s != c && *s)
		count++;
	s = ft_strchr(s, (int)c);
	while (s && *s)
	{
		if (s[1] && s[1] != c)
			count++;
		s++;
		s = ft_strchr(s, (int)c);
	}
	return (count);
}

static int	ft_count_width(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
		if (*s == c)
			break ;
	}
	return (count);
}

static char	ft_fill_arr(char const *s, char c, int i, char **arr)
{
	int	j;

	j = 0;
	while (!(s[j] == c) && s[j])
	{
		arr[i][j] = s[j];
		j++;
	}
	arr[i][j] = '\0';
	return (0);
}

static char	**ft_free_mem(char **arr, int current)
{
	int	i;

	i = 0;
	while (i < current)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		height;
	int		i;

	if (!s)
		return (0);
	height = ft_count_height(s, c);
	arr = (char **)malloc(sizeof(char *) * (height + 1));
	if (!(arr))
		return (0);
	arr[height] = NULL;
	i = 0;
	while (i < height)
	{
		while (*s == c)
			s++;
		arr[i] = malloc(sizeof(char) * (ft_count_width(s, c) + 1));
		if (!arr[i])
			return (ft_free_mem(arr, i));
		ft_fill_arr(s, c, i, arr);
		if (ft_strchr(s, (int)c))
			s = ft_strchr(s, (int)c);
		i++;
	}
	return (arr);
}
