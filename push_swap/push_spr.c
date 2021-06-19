/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_spr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:00:23 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:00:25 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_arr *arr, int *count)
{
	int		temp;

	temp = arr->arr[arr->top];
	arr->arr[arr->top] = arr->arr[arr->top - 1];
	arr->arr[arr->top - 1] = temp;
	write(1, "sa\n", 3);
	(*count)++;
}

void	sb(t_arr *arr, int *count)
{
	int		temp;

	temp = arr->arr[arr->top];
	arr->arr[arr->top] = arr->arr[arr->top - 1];
	arr->arr[arr->top - 1] = temp;
	write(1, "sb\n", 3);
	(*count)++;
}

void	ss(t_arr *arr_a, t_arr *arr_b, int *count)
{
	int		temp;

	temp = arr_a->arr[arr_a->top];
	arr_a->arr[arr_a->top] = arr_a->arr[arr_a->top - 1];
	arr_a->arr[arr_a->top - 1] = temp;
	temp = arr_b->arr[arr_b->top];
	arr_b->arr[arr_b->top] = arr_b->arr[arr_b->top - 1];
	arr_b->arr[arr_b->top - 1] = temp;
	write(1, "ss\n", 3);
	(*count)++;
}

void	pa(t_arr *arr_a, t_arr *arr_b, int *count)
{
	arr_a->arr[arr_a->top + 1] = arr_b->arr[arr_b->top];
	arr_b->arr[arr_b->top] = 0;
	arr_b->top--;
	arr_a->top++;
	write(1, "pa\n", 3);
	(*count)++;
}

void	pb(t_arr *arr_a, t_arr *arr_b, int *count)
{
	arr_b->arr[arr_b->top + 1] = arr_a->arr[arr_a->top];
	arr_a->arr[arr_a->top] = 0;
	arr_a->top--;
	arr_b->top++;
	write(1, "pb\n", 3);
	(*count)++;
}
