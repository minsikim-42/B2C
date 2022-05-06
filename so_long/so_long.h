/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsikkim <minsikkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 09:59:07 by minsikim          #+#    #+#             */
/*   Updated: 2022/05/06 17:02:06 by minsikkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include "./minilibx_mms_20200219/mlx.h"
#include <fcntl.h>
#include "./get_next_line.h"

typedef struct s_imgs
{
	void *wall;
	void *player_left;
	void *eat;
	void *exit;
	void *coffee;
	void *black;
	void *white;
	void *mzic;
	void *enemy1;
	void *enemy2;
} t_imgs;

typedef struct s_npc
{
	int x;
	int y;
} t_npc;

typedef struct s_data
{
	void *mlx;
	void *win;
	t_imgs img;
	int moved;
	int point;
	int height;
	int width;
	int img_width;
	int img_height;
	int frame;
	int collect;
	int ex;
	int x_move;
	int y_move;
	int x;
	int y;
	t_npc enemy;
	t_npc exit;
	char **map;
} t_data;

void moving(t_data *data);
int loop_move(t_data *data);
void set_data(int argc, char **argv, t_data *data, t_imgs *img);
void put_image(t_data *data, int i, int j);

int key(int keycode, t_data *data);
void write_num(int num);
void moving_y(t_data *data);
void moving_x(t_data *data);
char *ft_itoa(int num);

int mapparsing(int argc, char **argv, t_data *data);
void check_sa(int fd, char **argv, t_data *data);
void check_map_pc(char **map, t_data *data);
void check_map_a(char **map, t_data *data);
void check_map_w(char **map, t_data data);

void error_exit(int i, char e);
void check_ber(char *argv);

#endif
