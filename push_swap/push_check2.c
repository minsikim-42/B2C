/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:17 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:00:29 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_arr arr)
{
	int		i;

	i = 0;
	while (i < arr.top - 1)
	{
		if (arr.arr[i] < arr.arr[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_big(t_arr arr_a, t_arr arr)
{
	int		num;
	int		i;

	num = arr_a.arr[arr_a.top];
	i = 0;
	while (i < arr.top + 1)
	{
		if (num < arr.arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_small(t_arr arr_a, t_arr arr)
{
	int		num;
	int		i;

	num = arr_a.arr[arr_a.top];
	i = 0;
	while (i < arr.top + 1)
	{
		if (num > arr.arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	check321(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[top] < arr.arr[top - 1] && arr.arr[top - 1] < arr.arr[0])
		return (1);
	else
		return (0);
}

int	check312(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[top - 1] < arr.arr[top] && arr.arr[top] < arr.arr[0])
		return (1);
	else
		return (0);
}
