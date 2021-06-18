#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

typedef struct s_arr
{
	int	*arr;
	int	top;
}				t_arr;

typedef struct s_data
{
	t_arr	arr;
	t_arr	brr;
	int		*cp;
	int		width;
	int		sp_count;
}				t_data;

void	sa(t_arr *arr, int *count);
void	sb(t_arr *arr, int *count);
void	ss(t_arr *arr, t_arr *brr, int *count);
void	ra(t_arr *arr, int *count);
void	rb(t_arr *arr, int *count);
void	rr(t_arr *arr, t_arr *brr, int *count);
void	rra(t_arr *arr, int *count);
void	rrb(t_arr *arr, int *count);
void	rrr(t_arr *arr, t_arr *brr, int *count);
void	pa(t_arr *arr, t_arr *brr, int *count);
void	pb(t_arr *arr, t_arr *brr, int *count);

void	error_exit(int i); // utils 1
int		ft_atoi(char *arr);
int		biggest(t_arr arr);
int		smallest(t_arr arr);
int		arrtop(t_arr arr, int i);

void	setzero(t_data *data, int width);
int		check_pushab(t_data *data, int point);
int		check_topbottom(t_arr arr, t_data *data, int point);
void	setarr(t_data *data, int sp_count, char **argv);
void	setcopy(t_data *data);

int		thereis_sp(char *arr);
int		split_count(char **argv);
void	swap(int *arr, int index, int i);
void	roll_b(t_data *data, int *count, int atop);
void	roll_a(t_data *data, int *count, int btop);

void	check_same(int *cp, t_data data);
int		check_pushab(t_data *data, int point);
int		check_topbottom(t_arr arr, t_data *data, int point);
int		check_ab(t_data *data, int point);
int		check_atob(t_arr arr, int push);
int		check_btoa(t_arr arr, int push);
void	check_sort(t_arr arr);

#endif