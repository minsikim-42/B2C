/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikkim <minsikkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:25:57 by minsikim          #+#    #+#             */
/*   Updated: 2022/05/06 17:18:06 by minsikkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int key(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		data->y_move = 1;
	if (keycode == 1)
		data->y_move = -1;
	if (keycode == 0)
		data->x_move = 1;
	if (keycode == 2)
		data->x_move = -1;
	data->moved += 1;
	return (keycode);
}

void moving_x(t_data *data)
{
	data->map[data->x][data->y] = '0';
	if (data->map[data->x][data->y - data->x_move] == '1')
	{
		data->x_move = 0;
		return;
	}
	if (data->map[data->x][data->y - data->x_move] == 'C')
	{
		data->point++;
		data->collect--;
	}
	data->y -= data->x_move;
	data->map[data->x][data->y] = 'P';
	data->x_move = 0;
}

void moving_y(t_data *data)
{
	data->map[data->x][data->y] = '0';
	if (data->map[data->x - data->y_move][data->y] == '1')
	{
		data->y_move = 0;
		return;
	}
	if (data->map[data->x - data->y_move][data->y] == 'C')
	{
		data->point++;
		data->collect--;
	}
	data->x -= data->y_move;
	data->map[data->x][data->y] = 'P';
	data->y_move = 0;
}

void error_exit(int i, char e)
{
	if (e == 'w')
		perror("well error\n");
	if (e == 's')
		perror("sprite error\n");
	exit(i);
}

void read_map(t_data *data)
{
	int i;
	int j;

	if (data->frame == 1)
		enemy_move(data, data->enemy);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j] != 0)
		{
			put_image(data, i, j);
			if (data->map[i][j] == 'C')
				put_image_c(data, i, j);
			j++;
		}
		i++;
	}
	if (data->frame > FRAME / 2)
		mlx_put_image_to_window(data->mlx, data->win, data->img.enemy1,
								data->enemy.y * 64, data->enemy.x * 64);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.enemy2,
								data->enemy.y * 64, data->enemy.x * 64);
}
