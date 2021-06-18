#include "push_swap.h"

void	error_exit(int i)
{
	write(1, "Error\n", 6);
	exit(i);
}

int	ft_atoi(char *arr)
{
	int			i;
	long long	result;
	int			mi;

	result = 0;
	i = 0;
	mi = 0;
	while (arr[i] != 0)
	{
		if (arr[i] == '-')
		{
			mi = 1;
			i++;
		}
		if (arr[i] > '9' || arr[i] < '0')
			error_exit(0);
		result = result * 10 + arr[i] - 48;
		i++;
	}
	if (mi == 1)
		result *= -1;
	if (result > 2147483647 || result < -2147483648 || i == 0)
		error_exit(0);
	return ((int)result);
}

int	biggest(t_arr arr)
{
	long long	big;
	int		i;

	if (arr.top == 0)
		return (arr.arr[0]);
	i = 0;
	big = -2147483648;
	while (i < arr.top + 1)
	{
		if (big < arr.arr[i])
			big = arr.arr[i];
		i++;
	}
	return ((int)big);
}

int	smallest(t_arr arr)
{
	long long	small;
	int		i;

	if (arr.top == 0)
		return (arr.arr[0]);
	i = 0;
	small = 2147483647;
	while (i < arr.top + 1)
	{
		if (small > arr.arr[i])
			small = arr.arr[i];
		i++;
	}
	return ((int)small);
}

int	arrtop(t_arr arr, int i)
{
	return (arr.arr[arr.top - i]);
}
