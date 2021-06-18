/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <spalstlr321@naver.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:00:07 by minsikim          #+#    #+#             */
/*   Updated: 2021/01/14 11:33:59 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear(char **arr, int c)
{
	int		i;

	i = 0;
	while (i < c)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	arrange(char **arr, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	arr[0] = (char *)malloc(sizeof(char) * 1);
	arr[0][0] = '1';
	while (s[j] && arr[i])
	{
		if (s[j] == c)
		{
			while (s[j] == c)
				j++;
			k = 0;
		}
		else
		{
			while (s[j] != c && s[j])
				arr[i][k++] = s[j++];
			arr[i][k] = 0;
			i++;
		}
	}
}

static int	strcount(char const *s, char c, int j)
{
	int		count;

	count = 0;
	while (s[j] != c && s[j])
	{
		count++;
		j++;
	}
	return (count);
}

static int	spcount(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	if (!s)
		return (0);
	if (!(arr = (char **)malloc(sizeof(char *) * (spcount(s, c) + 2))))
		return (0);
	i = 0;
	j = 0;
	while (++i < spcount(s, c) + 1 && s[j])
	{
		if (s[j] == c)
			while (s[j] == c)
				j++;
		if (!(arr[i] = (char *)malloc(sizeof(char) * (strcount(s, c, j) + 1))))
		{
			clear(arr, i);
			return (0);
		}
		j = j + strcount(s, c, j);
	}
	arr[i] = 0;
	arrange(arr, s, c);
	return (arr);
}
