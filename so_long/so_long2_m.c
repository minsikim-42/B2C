/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2_m.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikkim <minsikkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:35:54 by minsikim          #+#    #+#             */
/*   Updated: 2022/05/06 16:55:47 by minsikkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void write_num(int num)
{
	int result;
	char c;

	if (num == 0)
	{
		write(1, "0", 1);
		return;
	}
	result = num / 10;
	if (result != 0)
		write_num(result);
	c = num % 10 + 48;
	write(1, &c, 1);
}

void moving_y(t_data *data)
{
	write(1, "moving: ", 8);
	write_num(data->moved);
	write(1, "\n", 1);
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
	data->map[data->x][data->y] = 0;
	data->x -= data->y_move;
	data->map[data->x][data->y] = 'P';
	data->y_move = 0;
}

void moving_x(t_data *data)
{
	write(1, "moving: ", 8);
	write_num(data->moved);
	write(1, "\n", 1);
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
	data->map[data->x][data->y] = 0;
	data->y -= data->x_move;
	data->map[data->x][data->y] = 'P';
	data->x_move = 0;
}

char *ft_itoa(int num)
{
	int i;
	char *arr;
	int c;

	if (num < 0)
	{
		num *= -1;
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
