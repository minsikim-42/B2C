/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikkim <minsikkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:59:11 by minsikim          #+#    #+#             */
/*   Updated: 2022/05/06 17:17:14 by minsikkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void moving(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
							data->img.white, data->y * 64, data->x * 64);
	if (data->y_move)
	{
		moving_y(data);
	}
	if (data->x_move)
	{
		moving_x(data);
	}
	mlx_put_image_to_window(data->mlx, data->win,
							data->img.player_left, data->y * 64, data->x * 64);
}

void enemy_move(t_data *data, t_npc enemy)
{
	int i;

	i = find_player(data->x, data->y, enemy);
	if (i == 1)
	{
		data->enemy.y++;
	}
	if (i == 2)
	{
		data->enemy.x--;
	}
	if (i == 3)
	{
		data->enemy.y--;
	}
	if (i == 4)
	{
		data->enemy.x++;
	}
}

void put_count(t_data *data)
{
	int i;
	static char *temp;

	i = 0;
	while (i < data->width)
	{
		mlx_put_image_to_window(data->mlx, data->win,
								data->img.black, i * 64, data->height * 64);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.black,
							80, data->height * 64);
	mlx_string_put(data->mlx, data->win, 10,
				   data->height * 64, 0x0000EEEE, "move : ");
	mlx_string_put(data->mlx, data->win, 80,
				   data->height * 64, 0x0000EEEE, (temp = ft_itoa(data->moved)));
	free(temp);
}

int loop_move(t_data *data)
{
	if (data->frame == FRAME)
		data->frame = 0;
	data->frame++;
	read_map(data);
	if (data->map[data->exit.x][data->exit.y] == 'P' && data->collect == 0)
		exit(0);
	if (data->enemy.x == data->x && data->enemy.y == data->y)
		exit(0);
	mlx_put_image_to_window(data->mlx, data->win,
							data->img.mzic, data->exit.y * 64, data->exit.x * 64);
	moving(data);
	put_count(data);
	return (0);
}

int main(int argc, char *argv[])
{
	t_data data;

	data.mlx = mlx_init();
	set_data(argc, argv, &data, &data.img);
	data.win = mlx_new_window(data.mlx,
							  data.width * 64, (data.height + 1) * 64, "so_long_bonus");
	mlx_hook(data.win, 2, 0, key, &data);
	mlx_loop_hook(data.mlx, loop_move, &data);
	mlx_loop(data.mlx);
	return (0);
}
