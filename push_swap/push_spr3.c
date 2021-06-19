/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_spr3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:46 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:01:07 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_arr *arr_a, t_arr *arr_b, int *count)
{
	int		temp;
	int		i;

	temp = arr_a->arr[0];
	i = 0;
	while (i < arr_a->top)
	{
		arr_a->arr[i] = arr_a->arr[i + 1];
		i++;
	}
	arr_a->arr[arr_a->top] = temp;
	temp = arr_b->arr[0];
	i = 0;
	while (i < arr_b->top)
	{
		arr_b->arr[i] = arr_b->arr[i + 1];
		i++;
	}
	arr_b->arr[arr_b->top] = temp;
	write(1, "rrr\n", 4);
	(*count)++;
}
