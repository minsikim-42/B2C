/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:24:34 by minsikim          #+#    #+#             */
/*   Updated: 2021/07/06 20:43:01 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(int num)
{
	int		i;
	int		mi;
	char	*arr;
	int		c;

	if (num < 0)
	{
		num *= -1;
		mi = 1;
	}
	i = num;
	c = 0;
	while (i != 0)
	{
		i /= 10;
		c++;
	}
	arr = (char *)malloc(sizeof(char) * c);
	arr[c] = 0;
	while (c--)
	{
		arr[c] = num % 10 + 48;
		num /= 10;
	}
	return (arr);
}

int	find_dae(t_npc enemy, int x, int y)
{
	if (x - enemy.x > 0 && y - enemy.y > 0)
	{
		if (x - enemy.x > y - enemy.y)
			return (4);
		return (1);
	}
	if (x - enemy.x > 0 && y - enemy.y < 0)
	{
		if (x - enemy.x > enemy.y - y)
			return (4);
		return (3);
	}
	if (x - enemy.x < 0 && y - enemy.y > 0)
	{
		if (enemy.x - x > y - enemy.y)
			return (2);
		return (1);
	}
	if (x - enemy.x < 0 && y - enemy.y < 0)
	{
		if (enemy.x - x > enemy.y - y)
			return (2);
		return (3);
	}
	return (0);
}

int	find_player(int x, int y, t_npc enemy)
{
	int	i;

	printf("|%d %d|\n", x - enemy.x, y - enemy.y);
	i = find_dae(enemy, x, y);
	if (i != 0)
		return (i);
	if (x - enemy.x == 0 && y - enemy.y > 0)
		return (1);
	if (x - enemy.x == 0 && y - enemy.y < 0)
		return (3);
	if (x - enemy.x > 0 && y - enemy.y == 0)
		return (4);
	if (x - enemy.x < 0 && y - enemy.y == 0)
		return (2);
	return (0);
}

void	set_data(int argc, char **argv, t_data *data, t_imgs *img)
{
	set_data_things(data);
	mapparsing(argc, argv, data);
	printf("h:%d, w:%d\n", data->height, data->width);
	img->player_left = mlx_xpm_file_to_image(data->mlx, \
		"./textures/face_left.XPM", &data->img_width, &data->img_height);
	img->coffee = mlx_xpm_file_to_image(data->mlx, \
		"./textures/coffee64.XPM", &data->img_width, &data->img_height);
	img->sp_coffee = mlx_xpm_file_to_image(data->mlx, \
		"./textures/sp_coffee.XPM", &data->img_width, &data->img_height);
	img->white = mlx_xpm_file_to_image(data->mlx, \
		"./textures/white.XPM", &data->img_width, &data->img_height);
	img->black = mlx_xpm_file_to_image(data->mlx, \
		"./textures/black.XPM", &data->img_width, &data->img_height);
	img->wall = mlx_xpm_file_to_image(data->mlx, \
		"./textures/wall.XPM", &data->img_width, &data->img_height);
	img->mzic = mlx_xpm_file_to_image(data->mlx, \
		"./textures/mzic.XPM", &data->img_width, &data->img_height);
	img->enemy1 = mlx_xpm_file_to_image(data->mlx, \
		"./textures/enemy1.XPM", &data->img_width, &data->img_height);
	img->enemy2 = mlx_xpm_file_to_image(data->mlx, \
		"./textures/enemy2.XPM", &data->img_width, &data->img_height);
}
