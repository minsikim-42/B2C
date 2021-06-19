/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikim <minsikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 18:02:14 by minsikim          #+#    #+#             */
/*   Updated: 2021/06/19 18:12:58 by minsikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_arr
{
	int	*arr;
	int	top;
}				t_arr;

typedef struct	s_data
{
	t_arr	arr;
	t_arr	brr;
	int		*cp;
	int		width;
	int		sp_count;
}				t_data;

void			sa(t_arr *arr, int *count);
void			sb(t_arr *arr, int *count);
void			ss(t_arr *arr, t_arr *brr, int *count);
void			ra(t_arr *arr, int *count);
void			rb(t_arr *arr, int *count);
void			rr(t_arr *arr, t_arr *brr, int *count);
void			rra(t_arr *arr, int *count);
void			rrb(t_arr *arr, int *count);
void			rrr(t_arr *arr, t_arr *brr, int *count);
void			pa(t_arr *arr, t_arr *brr, int *count);
void			pb(t_arr *arr, t_arr *brr, int *count);

void			error_exit(int i);
int				ft_atoi(char *arr);
int				biggest(t_arr arr);
int				smallest(t_arr arr);
int				arrtop(t_arr arr, int i);

void			setzero(t_data *data, int width);
int				check_pushab(t_data *data, int point);
int				check_topbottom(t_arr arr, t_data *data, int point);
void			setarr(t_data *data, int sp_count, char **argv);
void			setcopy(t_data *data);

int				thereis_sp(char *arr);
int				split_count(char **argv);
void			swap(int *arr, int index, int i);
void			roll_b(t_data *data, int *count, int atop);
void			roll_a(t_data *data, int *count, int btop);

void			push_c2(t_data *data, int *count);
void			top_biggest_roll2(t_arr arr, int *count, t_data *data);
void			free_free(t_data data);
void			sort_arr(t_data *data);
void			amugeona(t_data *data, int *count, int *i, int point);

void			check_same(int *cp, t_data data);
int				check_pushab(t_data *data, int point);
int				check_topbottom(t_arr arr, t_data *data, int point);
int				check_ab(t_data *data, int point);

int				check_sort(t_arr arr);
int				check_big(t_arr arr_a, t_arr arr);
int				check_small(t_arr arr_a, t_arr arr);
int				check321(t_arr arr);
int				check312(t_arr arr);

int				check231(t_arr arr);
int				check132(t_arr arr);
int				check123(t_arr arr);
int				check213(t_arr arr);
void			check_3(t_arr *arr, int *count);

int				check_atob(t_arr arr, int push);
int				check_btoa(t_arr arr, int push);

void			clear(char **arr, int c);
void			arrange(char **arr, char const *s, char c);
int				strcount(char const *s, char c, int j);
int				spcount(char const *s, char c);
char			**ft_split(char const *s, char c);

#endif
