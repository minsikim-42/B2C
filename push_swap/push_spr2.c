/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_spr2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:45 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:01:07 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_arr *arr, int *count)
{
	int		temp;
	int		i;

	if (arr->top <= 0)
		return ;
	temp = arr->arr[arr->top];
	i = arr->top;
	while (i > 0)
	{
		arr->arr[i] = arr->arr[i - 1];
		i--;
	}
	arr->arr[0] = temp;
	write(1, "ra\n", 3);
	(*count)++;
}

void	rb(t_arr *arr, int *count)
{
	int		temp;
	int		i;

	if (arr->top <= 0)
		return ;
	temp = arr->arr[arr->top];
	i = arr->top;
	while (i > 0)
	{
		arr->arr[i] = arr->arr[i - 1];
		i--;
	}
	arr->arr[0] = temp;
	write(1, "rb\n", 3);
	(*count)++;
}

void	rr(t_arr *arr_a, t_arr *arr_b, int *count)
{
	int		temp;
	int		i;

	temp = arr_a->arr[arr_a->top];
	i = arr_a->top;
	while (i > 0)
	{
		arr_a->arr[i] = arr_a->arr[i - 1];
		i--;
	}
	arr_a->arr[0] = temp;
	temp = arr_b->arr[arr_b->top];
	i = arr_b->top;
	while (i > 0)
	{
		arr_b->arr[i] = arr_b->arr[i - 1];
		i--;
	}
	arr_b->arr[0] = temp;
	write(1, "rr\n", 3);
	(*count)++;
}

void	rra(t_arr *arr, int *count)
{
	int		temp;
	int		i;

	temp = arr->arr[0];
	i = 0;
	while (i < arr->top)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;
	}
	arr->arr[arr->top] = temp;
	write(1, "rra\n", 4);
	(*count)++;
}

void	rrb(t_arr *arr, int *count)
{
	int		temp;
	int		i;

	temp = arr->arr[0];
	i = 0;
	while (i < arr->top)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;
	}
	arr->arr[i] = temp;
	write(1, "rrb\n", 4);
	(*count)++;
}
