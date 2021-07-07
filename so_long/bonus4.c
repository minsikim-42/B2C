/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:52:48 by minsikim          #+#    #+#             */
/*   Updated: 2021/07/07 09:06:44 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall, j * 64, i * 64);
	if (data->map[i][j] == 'P')
	{
		data->x = i;
		data->y = j;
	}
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.white, j * 64, i * 64);
	if (data->map[i][j] == 'E')
	{
		data->exit.x = i;
		data->exit.y = j;
	}
	if (data->map[i][j] == 'F')
	{
		data->map[i][j] = '0';
		data->enemy.x = i;
		data->enemy.y = j;
	}
}

void	put_image_c(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img.white, j * 64, i * 64);
	if (data->frame > 30)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img.coffee, j * 64, i * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img.sp_coffee, j * 64, i * 64);
	}
}

void	set_data_things(t_data *data)
{
	data->point = 0;
	data->frame = 0;
	data->moved = 0;
	data->width = 0;
	data->collect = 0;
	data->ex = 0;
	data->x_move = 0;
	data->y_move = 0;
}
