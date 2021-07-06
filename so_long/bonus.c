/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:59:11 by minsikim          #+#    #+#             */
/*   Updated: 2021/07/06 20:52:45 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void    enemy_move(t_data *data, t_npc enemy)
{
    int     i;

    i = find_player(data->x, data->y, enemy);
    if (i == 1)
    {
        enemy.x++;
    }
    if (i == 2)
    {
        enemy.y--;
    }
    if (i == 3)
    {
        enemy.x--;
    }
    if (i == 4)
    {
        enemy.y++;
    }
}

int	loop_move(t_data *data)
{
	if (data->frame == 60)
		data->frame = 0;
	data->frame++;
	read_map(data);
    if (data->frame == 30)
        enemy_move(data, data->enemy);
	if (data->map[data->exit.x][data->exit.y] == 'P' && data->collect == 0)
		exit(0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.mzic, data->exit.y * 64, data->exit.x * 64);
	moving(data);
	return (0);
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
	printf("h:%d, w:%d\n", data.height, data.width);
	// i = 0;
	// while (i < data.height)
	// {
	// 	j = 0;
	// 	while (data.map[i][j] != 0)
	// 	{
	// 		put_image(&data, i, j);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_hook(data.win, 2, 0, key, &data);
	mlx_loop_hook(data.mlx, loop_move, &data);
	mlx_loop(data.mlx);
	return (0);
}
