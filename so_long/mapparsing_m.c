/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparsing_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikkim <minsikkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:59:13 by minsikim          #+#    #+#             */
/*   Updated: 2022/05/06 17:11:53 by minsikkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_sa(int fd, char **argv, t_data *data)
{
	int i;
	char *line;
	int width;

	line = 0;
	get_next_line(fd, &line);
	while (line[data->width] != 0)
		data->width++;
	i = 1;
	while (get_next_line(fd, &line) > 0)
	{
		width = 0;
		while (line[width] != 0)
			width++;
		if (data->width != width)
			error_exit(0, 'w');
		i++;
	}
	data->map = (char **)malloc(sizeof(char *) * i + 1);
	data->height = i;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &(data->map[i])))
		i++;
}

void check_map_pc(char **map, t_data *data)
{
	int i;
	int j;
	int p;

	i = 0;
	j = 0;
	p = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				data->ex++;
			if (map[i][j] == 'C')
				data->collect++;
			j++;
		}
		i++;
	}
	if (p != 1 || data->ex == 0 || data->collect == 0)
		error_exit(0, 's');
}

void check_map_a(char **map, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (!(map[i][j] == 'P' || map[i][j] == 'E' ||
				  map[i][j] == 'C' || map[i][j] == '0' || map[i][j] == '1'))
				error_exit(0, 's');
			j++;
		}
		i++;
	}
}

void check_map_w(char **map, t_data data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data.height)
	{
		j = 0;
		while (j < data.width)
		{
			if (i == 0 && map[i][j] != '1')
				error_exit(0, 'w');
			if (i == data.height - 1 && map[i][j] != '1')
				error_exit(0, 'w');
			if (j == 0 && map[i][j] != '1')
				error_exit(0, 'w');
			if (j == data.width - 1 && map[i][j] != '1')
				error_exit(0, 'w');
			j++;
		}
		i++;
	}
}

int mapparsing(int argc, char **argv, t_data *data)
{
	int fd;

	if (argc != 2)
		error_exit(0, 'i');
	check_ber(argv[1]);
	fd = open(argv[1], O_RDONLY);
	check_sa(fd, argv, data);
	check_map_w(data->map, *data);
	check_map_pc(data->map, data);
	check_map_a(data->map, data);
	return (0);
}
