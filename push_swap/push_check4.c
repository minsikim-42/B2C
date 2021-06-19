/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:20 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:00:27 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_atob(t_arr arr, int push)
{
	if (push > arr.arr[arr.top] && push < arr.arr[0])
	{
		return (1);
	}
	else if (push > biggest(arr) && arr.arr[arr.top] == biggest(arr))
		return (1);
	else if (push > arr.arr[arr.top])
		return (-1);
	else if (push < arr.arr[arr.top])
		return (-2);
	return (0);
}

int	check_btoa(t_arr arr, int push)
{
	if (push < arr.arr[arr.top] && push > arr.arr[0])
	{
		return (1);
	}
	else if (push < smallest(arr) && arr.arr[arr.top] == smallest(arr))
		return (1);
	else if (push > arr.arr[arr.top])
		return (-1);
	else if (push < arr.arr[arr.top])
		return (-2);
	return (0);
}
