/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:56 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:01:05 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setzero(t_data *data, int width)
{
	int		i;

	i = 0;
	while (i < width + 1)
	{
		data->arr.arr[i] = 0;
		i++;
	}
	i = 0;
	while (i < width + 1)
	{
		data->brr.arr[i] = 0;
		i++;
	}
}

void	setarr(t_data *data, int sp_count, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**inja;

	i = 1;
	k = 0;
	while (argv[i])
	{
		if (thereis_sp(argv[i]))
		{
			inja = ft_split(argv[i], ' ');
			j = 1;
			while (inja[j] != 0)
				data->arr.arr[sp_count - k++ - 1] = ft_atoi(inja[j++]);
		}
		else
		{
			data->arr.arr[sp_count - k - 1] = ft_atoi(argv[i]);
			k++;
		}
		i++;
	}
	data->arr.top = sp_count - 1;
	data->brr.top = -1;
}

void	setcopy(t_data *data)
{
	int		i;
	int		sorted;

	sorted = 1;
	i = 0;
	while (i < data->arr.top + 1)
	{
		if (data->arr.arr[i] <= data->arr.arr[i + 1])
			sorted = 0;
		data->cp[i] = data->arr.arr[i];
		i++;
	}
	data->cp[i] = 0;
	if (sorted == 1)
		exit(0);
}
