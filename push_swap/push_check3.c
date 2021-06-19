/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:18 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:00:28 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check231(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[top] < arr.arr[0] && arr.arr[0] < arr.arr[top - 1])
		return (1);
	else
		return (0);
}

int	check132(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[0] < arr.arr[top] && arr.arr[top] < arr.arr[top - 1])
		return (1);
	else
		return (0);
}

int	check123(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[0] < arr.arr[top - 1] && arr.arr[top - 1] < arr.arr[top])
		return (1);
	else
		return (0);
}

int	check213(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[top - 1] < arr.arr[0] && arr.arr[0] < arr.arr[top])
		return (1);
	else
		return (0);
}

void	check_3(t_arr *arr, int *count)
{
	if (check321(*arr))
		return ;
	if (check312(*arr))
	{
		sa(arr, count);
	}
	if (check213(*arr))
	{
		ra(arr, count);
	}
	if (check231(*arr))
	{
		sa(arr, count);
		ra(arr, count);
	}
	if (check123(*arr))
	{
		ra(arr, count);
		sa(arr, count);
	}
	if (check132(*arr))
	{
		rra(arr, count);
	}
}
