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
