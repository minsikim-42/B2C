/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:59:11 by minsikim          #+#    #+#             */
/*   Updated: 2021/07/06 13:40:55 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moving(t_data *data)
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

int	loop_move(t_data *data)
{
	if (data->frame == 60)
		data->frame = 0;
	data->frame++;
	if (data->map[data->exit.x][data->exit.y] == 'P' && data->collect == 0)
		exit(0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.mzic, data->exit.y * 64, data->exit.x * 64);
	moving(data);
	return (0);
}

void	set_data(int argc, char **argv, t_data *data, t_imgs *img)
{
	data->point = 0;
	data->frame = 0;
	data->moved = 0;
	data->width = 0;
	data->collect = 0;
	data->ex = 0;
	data->x_move = 0;
	data->y_move = 0;
	mapparsing(argc, argv, data);
	img->player_left = mlx_xpm_file_to_image(data->mlx, \
		"./textures/face_left.XPM", &data->img_width, &data->img_height);
	img->coffee = mlx_xpm_file_to_image(data->mlx, \
		"./textures/coffee64.XPM", &data->img_width, &data->img_height);
	img->white = mlx_xpm_file_to_image(data->mlx, \
		"./textures/white.XPM", &data->img_width, &data->img_height);
	img->black = mlx_xpm_file_to_image(data->mlx, \
		"./textures/black.XPM", &data->img_width, &data->img_height);
	img->wall = mlx_xpm_file_to_image(data->mlx, \
		"./textures/wall.XPM", &data->img_width, &data->img_height);
	img->mzic = mlx_xpm_file_to_image(data->mlx, \
		"./textures/mzic.XPM", &data->img_width, &data->img_height);
}

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
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.coffee, j * 64, i * 64);
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.white, j * 64, i * 64);
	if (data->map[i][j] == 'E')
	{
		data->exit.x = i;
		data->exit.y = j;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;
	int		j;

	data.mlx = mlx_init();
	set_data(argc, argv, &data, &data.img);
	data.win = mlx_new_window(data.mlx, \
		data.width * 64, data.height * 64, "so_long");
	i = 0;
	while (i < data.height)
	{
		j = 0;
		while (data.map[i][j] != 0)
		{
			put_image(&data, i, j);
			j++;
		}
		i++;
	}
	mlx_hook(data.win, 2, 0, key, &data);
	mlx_loop_hook(data.mlx, loop_move, &data);
	mlx_loop(data.mlx);
	return (0);
}
