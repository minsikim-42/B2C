/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:14 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:03:59 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_same(int *cp, t_data data)
{
	int		i;

	i = 0;
	while (i < data.width)
	{
		if (cp[i] == cp[i + 1])
			exit(0);
		i++;
	}
}

int		check_pushab(t_data *data, int point)
{
	int		i;

	i = 0;
	while (i < data->arr.top + 1)
	{
		if (data->arr.arr[i] < data->cp[(point * 2) - 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_topbottom(t_arr arr, t_data *data, int point)
{
	int		i;
	int		k;
	int		opt;

	opt = 1;
	i = 0;
	while (i < arr.top + 1)
	{
		if (arr.arr[i] > data->cp[point - 1])
			opt = 2;
		i++;
	}
	point = (data->arr.top + 1) / 3;
	i = 0;
	while (arr.arr[i] != data->cp[point * opt - 1])
		i++;
	k = 0;
	while (arr.arr[arr.top - k] != data->cp[point * opt - 1])
		k++;
	if (i == 1 || k == 1)
		return (0);
	else if (i < k)
		return (1);
	else
		return (2);
}

int		check_ab(t_data *data, int point)
{
	int		i;

	i = 0;
	while (i < data->width)
	{
		if (data->brr.arr[i] > data->cp[(point * 2) - 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
