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
	{
		i++;
	}
	k = 0;
	while (arr.arr[arr.top - k] != data->cp[point * opt - 1])
	{
		k++;
	}
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

int		check_atob(t_arr arr, int push)
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

int		check_btoa(t_arr arr, int push)
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
	return 0;
}

void	check_sort(t_arr arr) /////////////
{
	int		i;

	i = 0;
	while (i < arr.top - 1)
	{
		if (arr.arr[i] < arr.arr[i + 1])
		{
			printf("FAIL");
			exit(0);
		}
		i++;
	}
	printf("SUCCESS");
}

int		check_big(t_arr arr_a, t_arr arr)
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

int		check_small(t_arr arr_a, t_arr arr)
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

int		check321(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[top] < arr.arr[top - 1] && arr.arr[top - 1] < arr.arr[0])
		return (1);
	else
		return (0);
}

int		check312(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[top - 1] < arr.arr[top] && arr.arr[top] < arr.arr[0])
		return (1);
	else
		return (0);
}

int		check231(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[top] < arr.arr[0] && arr.arr[0] < arr.arr[top - 1])
		return (1);
	else
		return (0);
}

int		check132(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[0] < arr.arr[top] && arr.arr[top] < arr.arr[top - 1])
		return (1);
	else
		return (0);
}

int		check123(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[0] < arr.arr[top - 1] && arr.arr[top - 1] < arr.arr[top])
		return (1);
	else
		return (0);
}

int		check213(t_arr arr)
{
	int		top;

	top = arr.top;
	if (arr.arr[top - 1] < arr.arr[0] && arr.arr[0] < arr.arr[top])
		return (1);
	else
		return (0);
}

void	check_33(t_arr *arr, int *count)
{
	if (check321(*arr))
	{
		ra(arr, count);
	}
	if (check312(*arr))
		ra(arr, count);
	if (check213(*arr))
		ra(arr, count);
	if (check231(*arr))
	{
		sa(arr, count);
		ra(arr, count);
	}
	if (check123(*arr))
	{
		ra(arr, count);
	}
	if (check132(*arr))
	{
		sa(arr, count);
		ra(arr, count);
	}
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
