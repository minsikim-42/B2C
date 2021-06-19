/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:58 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:04:58 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		thereis_sp(char *arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		split_count(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	i--;
	return (i);
}

void	swap(int *arr, int index, int i)
{
	int		temp;

	temp = arr[i];
	arr[i] = arr[index];
	arr[index] = temp;
}

void	roll_b(t_data *data, int *count, int atop)
{
	while (!(check_atob(data->brr, atop) == 1))
	{
		if (check_atob(data->brr, atop) == -1)
			rrb(&data->brr, count);
		else if (check_atob(data->brr, atop) == -2)
			rb(&data->brr, count);
		atop = data->arr.arr[data->arr.top];
	}
	pb(&data->arr, &data->brr, count);
}

void	roll_a(t_data *data, int *count, int btop)
{
	while (!(check_btoa(data->arr, btop) == 1))
	{
		if (check_btoa(data->arr, btop) == -1)
			ra(&data->arr, count);
		else if (check_btoa(data->arr, btop) == -2)
			rra(&data->arr, count);
		btop = data->brr.arr[data->brr.top];
	}
	pa(&data->arr, &data->brr, count);
}
