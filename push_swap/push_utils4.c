/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:59:48 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:01:02 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_c2(t_data *data, int *count)
{
	if (check_sort(data->arr) == 1 && data->brr.top == -1)
		return ;
	while (data->arr.top > 0)
	{
		while (biggest(data->arr) == data->arr.arr[data->arr.top])
			ra(&data->arr, count);
		pb(&data->arr, &data->brr, count);
	}
}

void	top_biggest_roll2(t_arr arr, int *count, t_data *data)
{
	int		i;
	int	 	j;

	i = 0;
	while (arr.arr[i] != biggest(arr))
		i++;
	j = 0;
	while (arr.arr[arr.top - j] != biggest(arr))
		j++;
	if (i > j)
	{
		while (arr.arr[arr.top] != biggest(arr) && i < data->width)
			rb(&arr, count);
	}
	else
	{
		while (arr.arr[arr.top] != biggest(arr) && i < data->width)
			rrb(&arr, count);
	}
}

void	free_free(t_data data)
{
	free(data.arr.arr);
	free(data.brr.arr);
	free(data.cp);
}

void	sort_arr(t_data *data)
{
	int		i;
	int		j;
	long	small;
	int		index;

	i = 0;
	while (i < data->arr.top)
	{
		small = 2147483648;
		j = i;
		while (j <= data->arr.top)
		{
			if (small == data->cp[j])
				error_exit(0);
			if (small > data->cp[j])
			{
				small = data->cp[j];
				index = j;
			}
			j++;
		}
		swap(data->cp, index, i);
		i++;
	}
}
