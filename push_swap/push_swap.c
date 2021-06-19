/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:59:00 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 20:27:37 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setdata(t_data *data, int argc, char **argv)
{
	int		i;
	char	**inja;

	data->sp_count = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i] && thereis_sp(argv[i]))
		{
			inja = ft_split(argv[i], ' ');
			data->sp_count += split_count(inja);
		}
		else
			data->sp_count++;
		i++;
	}
	data->width = data->sp_count;
	data->arr.arr = (int *)malloc(sizeof(int) * data->width + 1);
	data->brr.arr = (int *)malloc(sizeof(int) * data->width + 1);
	data->cp = (int *)malloc(sizeof(int) * data->width + 1);
	setzero(data, data->width);
	setarr(data, data->width, argv);
	setcopy(data);
}

void	push_ab(t_data *data, int *count)
{
	int		point;

	if (check_sort(data->arr) == 1)
		return ;
	point = data->width / 3;
	while (data->arr.top + 1 > data->width - point * 2)
	{
		if (arrtop(data->arr, 0) <= data->cp[(point * 2) - 1])
		{
			if (arrtop(data->arr, 0) <= data->cp[point - 1])
			{
				pb(&(data->arr), &(data->brr), count);
				if (arrtop(data->arr, 1) > data->cp[(point * 2) - 1])
					rr(&data->arr, &data->brr, count);
				else
					rb(&data->brr, count);
			}
			else
			{
				pb(&(data->arr), &(data->brr), count);
			}
		}
		else
			ra(&data->arr, count);
	}
}

void	push_c(t_data *data, int *count, int pointab)
{
	int		i;
	int		point;

	if (check_sort(data->arr) == 1 && data->brr.top == -1)
		return ;
	point = pointab / 6;
	i = 0;
	while (i < point * 2)
	{
		if (arrtop(data->arr, 0) <= data->cp[pointab + point * 2 - 1])
		{
			if (arrtop(data->arr, 0) <= data->cp[pointab + point - 1])
				amugeona(data, count, &i, point);
			else
			{
				pb(&(data->arr), &(data->brr), count);
				i++;
			}
		}
		else
			ra(&data->arr, count);
	}
}

void	push_return_cba(t_data *data, int *count)
{
	if (data->brr.top == -1)
		return ;
	while (data->arr.top < data->width - 1)
	{
		top_biggest_roll2(data->brr, count, data);
		pa(&data->arr, &data->brr, count);
	}
}

int		main(int argc, char *argv[])
{
	t_data	data;
	int		count;

	if (argc == 1)
		exit(0);
	count = 0;
	setdata(&data, argc, argv);
	sort_arr(&data);
	if (data.width == 3)
		check_3(&data.arr, &count);
	push_ab(&data, &count);
	if (data.width == 5)
	{
		check_3(&data.arr, &count);
		pa(&data.arr, &data.brr, &count);
		pa(&data.arr, &data.brr, &count);
		return (1);
	}
	push_c(&data, &count, data.width / 3 * 2);
	push_c2(&data, &count);
	push_return_cba(&data, &count);
	free_free(data);
	return (1);
}
