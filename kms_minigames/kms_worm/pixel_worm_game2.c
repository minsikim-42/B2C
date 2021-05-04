//gcc -lmlx -framework OpenGL -framework Appkit test.c
// #include "mlx.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <time.h>
#include "pixel_worm_tracing.c"
#include "pixel_worm_game.h"

char arr[1200][1200] = {0,};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->add + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_move(t_data *data)
{
	if (data->left == 1 && data->player.x > 0)
	{
		data->player.x -= 1;
		printf("x = %d, y= %d\n", data->player.x, data->player.y);
	}
	if (data->right == 1 && data->player.x < data->width / 2 - data->size_x / 2)
	{
    	data->player.x += 1;
    	printf("x = %d, y= %d\n", data->player.x, data->player.y);
	}
	if (data->up == 1 && data->player.y > 0)
	{
		data->player.y -= 1;
		printf("x = %d, y= %d\n", data->player.x, data->player.y);
	}
	if (data->down == 1 && data->player.y < data->height / 2 - data->size_y / 2)
	{
		data->player.y += 1;
		printf("x = %d, y= %d\n", data->player.x, data->player.y);
	}
	if (arr[data->player.x][data->player.y] == 1 && data->score > 0)
	{
		printf("left win!! move point is %d", data->score);
		exit(0);
	}
	arr[data->player.x][data->player.y] = 1;
	return (0);
}

int		ft_move_2(t_data *data)
{
	if (data->left2 == 1 && data->player_2.x > 0)
	{
		data->player_2.x -= 1;
		printf("x = %d, y= %d\n", data->player_2.x, data->player_2.y);
	}
	if (data->right2 == 1 && data->player_2.x < data->width / 2 - data->size_x / 2)
	{
    	data->player_2.x += 1;
    	printf("x = %d, y= %d\n", data->player_2.x, data->player_2.y);
	}
	if (data->up2 == 1 && data->player_2.y > 0)
	{
		data->player_2.y -= 1;
		printf("x = %d, y= %d\n", data->player_2.x, data->player_2.y);
	}
	if (data->down2 == 1 && data->player_2.y < data->height / 2 - data->size_y / 2)
	{
		data->player_2.y += 1;
		printf("x = %d, y= %d\n", data->player_2.x, data->player_2.y);
	}
	if (arr[data->player_2.x][data->player_2.y] == 1 && data->score > 0)
	{
		printf("right win!! move point is %d", data->score);
		exit(0);
	}
	arr[data->player_2.x][data->player_2.y] = 1;
	return (0);
}

int		ft_draw(t_data *data)
{
	int i, j, k, l;
	int x = data->player.x;
	int y = data->player.y;

	if (data->pause == 0)
	{
		for(i = x; i < data->size_x + x; i++)
		{
			for (j = y; j < data->size_y + y; j++)
			{
				my_mlx_pixel_put(data, i + x, j + y, data->player.color);
				//my_mlx_pixel_put(data, i + data->size_x / 2 - 5 + x, j + data->size_y / 2 - 5 + y, 0x00FF0000);
			}
		}
		for(i = x + data->size_x / 2 - 5; i < data->size_x / 2 + 5 + x; i++)
		{
			for (j = y + data->size_x / 2 - 5; j < data->size_y / 2 + 5 + y; j++)
			{
				my_mlx_pixel_put(data, i + x, j + y, 0x00FF0000);
			}
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	else
	{
		for(i = x + data->size_x / 2 - 5; i < data->size_x / 2 + 5 + x; i++)
		{
			for (j = y + data->size_x / 2 - 5; j < data->size_y / 2 + 5 + y; j++)
			{
				my_mlx_pixel_put(data, i + x, j + y, data->player.color);
			}
		}
		clock_t start = clock();
		while(clock() - start < 2000);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	return (0);
}

int		ft_draw_2(t_data *data)
{
	int i, j, k, l;
	int x = data->player_2.x;
	int y = data->player_2.y;

	if (data->pause == 0)
	{
		for(i = x; i < data->size_x + x; i++)
		{
			for (j = y; j < data->size_y + y; j++)
			{
				my_mlx_pixel_put(data, i + x, j + y, data->player_2.color);
				//my_mlx_pixel_put(data, i + data->size_x / 2 - 5 + x, j + data->size_y / 2 - 5 + y, 0x00FF0000);
			}
		}
		for(i = x + data->size_x / 2 - 5; i < data->size_x / 2 + 5 + x; i++)
		{
			for (j = y + data->size_x / 2 - 5; j < data->size_y / 2 + 5 + y; j++)
			{
				my_mlx_pixel_put(data, i + x, j + y, 0x00FF0000);
			}
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	else
	{
		for(i = x + data->size_x / 2 - 5; i < data->size_x / 2 + 5 + x; i++)
		{
			for (j = y + data->size_x / 2 - 5; j < data->size_y / 2 + 5 + y; j++)
			{
				my_mlx_pixel_put(data, i + x, j + y, data->player_2.color);
			}
		}
		clock_t start = clock();
		while(clock() - start < 2000);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	}
	return (0);
}

int		main_loop(t_data *data)
{
	if (data->start != 1)
		return (0);
	data->score++;
	ft_draw(data);
	ft_move(data);
	ft_draw_2(data);
	ft_move_2(data);
	return (1);
}

void	data_set(t_data *data)
{
	int		ga = 800, se = 600;

	data->width = ga;
	data->height = se;
	data->player.x = 0;
	data->player.y = 0;
	data->player_2.x = ga / 2 - 50;
	data->player_2.y = se / 2 - 50;
	data->size_x = 30;
	data->size_y = 30;

	data->left = 0;
	data->right = 0;
	data->up = 0;
	data->down = 0;
	data->left2 = 0;
	data->right2 = 0;
	data->up2 = 0;
	data->down2 = 0;
	data->player.color = 0x00FFFF00;
	data->player_2.color = 0x00F0F0F0;

	data->score = -500;
	data->pause = 0;
	data->start = 0;

	data->color_c = 0;
}

int		main()
{
	t_data	data;
	t_data	img;
	
	data_set(&data);
	//data.timee = clock();

	data.mlx = mlx_init();

	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "pixel_put");
	data.img = mlx_new_image(data.mlx, data.width, data.height); // include image instance
	data.add = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian); // image's address malloc
	//mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	
	// mlx_hook(data.mlx_win, 4, 1L>>0, tracing, &data); // why 1L>>0 (int x_mask)?? >> : bit move
	// mlx_hook(data.mlx_win, 5, 1L>>0, release_m, &data); // 5. button release
	mlx_hook(data.mlx_win, 2, 0, tracing, &data); //2. key press
	mlx_hook(data.mlx_win, 3, 0, release_k, &data); // 3. key release //

	mlx_loop_hook(data.mlx, main_loop, &data); // frame update
	//mlx_loop_hook(data.mlx, main_loop_2, &player_2);
	mlx_loop(data.mlx);
}
