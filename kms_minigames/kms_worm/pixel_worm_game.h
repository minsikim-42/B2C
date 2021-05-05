#ifndef PIXEL_WORM_GAME_H
# define PIXEL_WORM_GAME_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define UP2	13
# define DOWN2	1
# define LEFT2	0
# define RIGHT2	2

# define R		15
# define P		35
# define SP		49
# define SF		258

typedef struct  s_player {
    
    int		x, y;
    int		score;
    unsigned int	color;
}               t_player;

typedef	struct	s_data {
    t_player player;
    t_player player_2;
	t_player wall;

	void	*img;
	char	*add;

	int		endian;
	int		width, height, size_x, size_y;
	int		bits_per_pixel;
	int		line_length;
	int		up, down, left, right, pause, start;
    int     up2, down2, left2, right2;
	int		l_up, l_down, l_left, l_right;
    int		l_up2, l_down2, l_left2, l_right2;

	int		color_c;
	int		hook;
	int		score;

	void	*mlx;
	void	*mlx_win;
}				t_data;

int ft_move(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     ft_move(t_data *data);
int		ft_draw(t_data *data);
int		ft_draw_2(t_data *data);
int		main_loop(t_data *data);
int		main_loop_2(t_data *data);
void	data_set(t_data *data);
int		tracing(int keycode, t_data *data);
int		release_k(int keycode, t_data *data);

#endif
//char arr[1200][1200] = {0,};