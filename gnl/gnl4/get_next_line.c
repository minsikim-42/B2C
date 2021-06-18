/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <spalstlr321@naver.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:26:01 by minsikim          #+#    #+#             */
/*   Updated: 2021/02/02 13:33:28 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_n(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*split_n(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*p;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	count = ft_strlen_n(str, i);
	if (str[i] == 0)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (count + 1));
	j = 0;
	i++;
	while (str[i])
	{
		p[j] = str[i];
		i++;
		j++;
	}
	p[j] = 0;
	return (p);
}

char	*swapfree(char *backup, char c)
{
	char	*temp;
	char	*p;

	if (c == 's')
	{
		temp = backup;
		p = split_n(temp);
		free(temp);
		temp = 0;
		backup = 0;
		return (p);
	}
	else if (c == 'a')
	{
		temp = backup;
		p = ft_strdup_n(temp);
		return (p);
	}
	else if (c == 'r')
	{
		free(backup);
		backup = 0;
		return (0);
	}
	return (NULL);
}

char	*joinfree(char *backup, int fd, int *r)
{
	char	*temp2;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	*r = read(fd, temp, BUFFER_SIZE);
	if (*r < 0)
	{
		free(temp);
		return (NULL);
	}
	temp[*r] = 0;
	temp2 = backup;
	backup = ft_strjoin(temp2, temp);
	free(temp2);
	free(temp);
	return (backup);
}

int		get_next_line(int fd, char **line)
{
	int			r;
	static char	*backup[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || !(line) || fd < 0 || fd > OPEN_MAX)
		return (-1);
	r = BUFFER_SIZE;
	if (!backup[fd] || !(find_n(backup[fd])))
	{
		while (!(find_n(backup[fd])) && r != 0)
		{
			if (!(backup[fd] = joinfree(backup[fd], fd, &r)))
				return (-1);
		}
	}
	*line = swapfree(backup[fd], 'a');
	backup[fd] = swapfree(backup[fd], 's');
	if (!(backup[fd]) && r != BUFFER_SIZE)
	{
		swapfree(backup[fd], 'r');
		return (0);
	}
	return (1);
}
