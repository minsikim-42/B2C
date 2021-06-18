#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_utils.c"
#include "push_spr.c"
#include "ft_split.c"
#include "push_utils2.c"
#include "push_utils3.c"
#include "push_check.c"

void	setdata(t_data *data, int argc, char **argv)
{
	int	i;
	char	**inja;

	data->sp_count = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i] && thereis_sp(argv[i]))
		{
			inja = ft_split(argv[i], ' ');
			data->sp_count += split_count(inja);
		}
		else
			data->sp_count++;
		i++;
	}
	data->width = data->sp_count;
	data->arr.arr = (int *)malloc(sizeof(int) * data->width + 1);
	data->brr.arr = (int *)malloc(sizeof(int) * data->width + 1);
	data->cp = (int *)malloc(sizeof(int) * data->width + 1);
	setzero(data, data->width);
	setarr(data, data->width, argv);
	setcopy(data);
}

void	push_ab(t_data *data, int *count)
{
	int		point;

	point = data->width / 3;
	while (data->arr.top + 1 > data->width - point * 2)// !(check_pushab(data, point))
	{
		if (arrtop(data->arr, 0) <= data->cp[(point * 2) - 1])
		{
			if (arrtop(data->arr, 0) <= data->cp[point - 1])
			{
				pb(&(data->arr), &(data->brr), count);
				if (arrtop(data->arr, 1) > data->cp[(point * 2) - 1])
					rr(&data->arr, &data->brr, count);
				else
					rb(&data->brr, count);
			}
			else
			{
				pb(&(data->arr), &(data->brr), count);
			}
		}
		else
			ra(&data->arr, count);
	}
}

void	push_c(t_data *data, int *count, int pointab)
{
	int		i;
	int		point;

	point = pointab / 6;
	i = 0;
	while (i < point * 2)
	{
		if (arrtop(data->arr, 0) <= data->cp[pointab + point * 2 - 1])
		{
			if (arrtop(data->arr, 0) <= data->cp[pointab + point - 1])
			{
				pb(&(data->arr), &(data->brr), count);
				i++;
				if (arrtop(data->arr, 1) > data->cp[(point * 8) - 1])
					rr(&data->arr, &data->brr, count);
				else
					rb(&data->brr, count);
			}
			else
			{
				pb(&(data->arr), &(data->brr), count);
				i++;
			}
		}
		else
			ra(&data->arr, count);
	}
	while (data->arr.top > 0)
	{
		while (biggest(data->arr) == data->arr.arr[data->arr.top])
			ra(&data->arr, count);
		pb(&data->arr, &data->brr, count);
	}
}

// void	top_smallest_roll(t_arr arr, int *count)
// {
// 	if (smallest(arr) == arr.arr[arr.top])
// 		return ;
// 	while (!(smallest(arr) == arr.arr[arr.top]))
// 		rra(&arr, count);
// }

// void	top_biggest_roll(t_arr arr, int *count)
// {
// 	if (biggest(arr) == arr.arr[arr.top])
// 		return ;
// 	while (!(biggest(arr) == arr.arr[arr.top]))
// 		rrb(&arr, count);
// }

void	top_biggest_roll2(t_arr arr, int *count, t_data *data)
{
	int		i;
	int	 	j;

	i = 0;
	while (arr.arr[i] != biggest(arr))
		i++;
	j = 0;
	while (arr.arr[arr.top - j] != biggest(arr))
		j++;
	if (i > j)
	{
		i = 0;
		while (arr.arr[arr.top] != biggest(arr) && i < data->width)
		{
			rb(&arr, count);
			i++;
		}
		if (i == data->width)
			error_exit(0); //
	}
	else
	{
		i = 0;
		while (arr.arr[arr.top] != biggest(arr) && i < data->width)
		{
			rrb(&arr, count);
			i++;
		}
		if (i == data->width)
			error_exit(0); //
	}
}

void	push_return_cba(t_data *data, int *count)
{
	while (data->arr.top < data->width - 1)
	{
		top_biggest_roll2(data->brr, count, data);
		pa(&data->arr, &data->brr, count);
	}
}

void	sort_arr(t_data *data)
{
	int		i;
	int		j;
	long	small;
	int		index;

	i = 0;
	while (i < data->arr.top)
	{
		small = 2147483648;
		j = i;
		while (j <= data->arr.top)
		{
			if (small == data->cp[j])
				error_exit(0);
			if (small > data->cp[j])
			{
				small = data->cp[j];
				index = j;
			}
			j++;
		}
		swap(data->cp, index, i);
		i++;
	}
}

int	main(int argc, char *argv[]){
	t_data	data;
	int	count;

	if (argc == 1)
		exit(0);
	count = 0;
	setdata(&data, argc, argv);
	sort_arr(&data);
	if (data.width == 3)
	{
		check_3(&data.arr, &count);
		check_sort(data.arr);
		return (1);
	}
	push_ab(&data, &count);
	if (data.width == 5)
	{
		check_3(&data.arr, &count);
		pa(&data.arr, &data.brr, &count);
		pa(&data.arr, &data.brr, &count);
		check_sort(data.arr);//
		return (1);
	}
	push_c(&data, &count, data.width / 3 * 2);
	push_return_cba(&data, &count);
	for (int j = data.width; j > 0; j--)//
	{
		printf ("\n|%d %d %d|", data.arr.arr[j - 1], data.brr.arr[j - 1], data.cp[j - 1]);
	}
	printf("count: %d, width:%d ", count, data.width);
	check_sort(data.arr);//
}
