#include "pixel_worm_game.h"

int		tracing(int keycode, t_data *data)
{
	data->start = 1;
	//printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);

	if (keycode == LEFT)
	{
		data->l_left = 0;
		if (keycode == UP)
			data->up = 1;
		if (keycode == DOWN)
			data->down = 1;
		if (data->left == 0)
		{
			//printf("bonus!!");
			data->score += 50;
		}
		data->left = 1;
		data->right = 0;
		//data->up = 0;
		//data->down = 0;
	}
	if (keycode == RIGHT)
	{
		if (keycode == UP)
			data->up = 1;
		if (keycode == DOWN)
			data->down = 1;
		if (data->right == 0)
		{
			//printf("bonus!!");
			data->score += 50;
		}
		data->left = 0;
		data->right = 1;
		//data->up = 0;
		//data->down = 0;
	}
	if (keycode == UP)
	{
		if (keycode == LEFT)
			data->left = 1;
		if (keycode == RIGHT)
			data->right = 1;	
		if (data->up == 0)
		{
			//printf("bonus!!");
			data->score += 50;
		}
		//data->left = 0;
		//data->right = 0;
		data->up = 1;
		data->down = 0;
	}
	if (keycode == DOWN)
	{
		if (keycode == LEFT)
			data->left = 1;
		if (keycode == RIGHT)
			data->right = 1;
		if (data->down == 0)
		{
			//printf("bonus!!");
			data->score += 50;
		}
		//data->left = 0;
		//data->right = 0;
		data->up = 0;
		data->down = 1;
	}
    if (keycode == LEFT2)
	{
		data->l_left2 = 0;
		if (keycode == UP2)
			data->up2 = 1;
		if (keycode == DOWN2)
			data->down2 = 1;
		if (data->left2 == 0)
		{
			//printf("bonus!!");
			data->score += 50;
		}
		data->left2 = 1;
		data->right2 = 0;
		//data->up = 0;
		//data->down = 0;
	}
	if (keycode == RIGHT2)
	{
		if (keycode == UP2)
			data->up2 = 1;
		if (keycode == DOWN2)
			data->down2 = 1;
		if (data->right2 == 0)
		{
			//printf("bonus!!");
			data->score += 50;
		}
		data->left2 = 0;
		data->right2 = 1;
		//data->up = 0;
		//data->down = 0;
	}
	if (keycode == UP2)
	{
		if (keycode == LEFT2)
			data->left2 = 1;
		if (keycode == RIGHT2)
			data->right2 = 1;	
		if (data->up2 == 0)
		{
			//printf("bonus!!");
			data->score += 50;
		}
		//data->left = 0;
		//data->right = 0;
		data->up2 = 1;
		data->down2 = 0;
	}
	if (keycode == DOWN2)
	{
		if (keycode == LEFT2)
			data->left2 = 1;
		if (keycode == RIGHT2)
			data->right2 = 1;
		if (data->down2 == 0)
		{
			//printf("bonus!!");
			data->score += 50;
		}
		//data->left = 0;
		//data->right = 0;
		data->up2 = 0;
		data->down2 = 1;
	}
	if (keycode == P && data->pause == 0)
		data->pause = 1;
	else if (keycode == P && data->pause == 1)
		data->pause = 0;
	
	if (keycode == SF)
	{
		data->color_c++;
		//printf("color is %x", data->player.color);
		if (data->color_c % 6 == 1)
			data->player_2.color = 0x00990000;
		else if (data->color_c % 6 == 2)
			data->player_2.color = 0x000000FF;
		else if (data->color_c % 6 == 3)
			data->player_2.color = 0x0000FFFF;
		else if (data->color_c % 6 == 4)
			data->player_2.color = 0x00FFFF00;
		else if (data->color_c % 6 == 5)
			data->player_2.color = 0x00FFFFFF;
		else if (data->color_c % 6 == 0)
			data->player_2.color = 0x0000FF00;
	}
	if (keycode == SP)
	{
		data->color_c++;
		//printf("color is %x", data->player.color);
		if (data->color_c % 6 == 1)
			data->player.color = 0x00990000;
		else if (data->color_c % 6 == 2)
			data->player.color = 0x000000FF;
		else if (data->color_c % 6 == 3)
			data->player.color = 0x0000FFFF;
		else if (data->color_c % 6 == 4)
			data->player.color = 0x00FFFF00;
		else if (data->color_c % 6 == 5)
			data->player.color = 0x00FFFFFF;
		else if (data->color_c % 6 == 0)
			data->player.color = 0x0000FF00;
	}
		 
	return (1);
	//mlx_destroy_window(keyb->mlx, keyb->win); // close window
}

int		release_k(int keycode, t_data *data)
{
	data->hook = 0;
	
	if (keycode == LEFT)
	{
		data->l_left = 1;
		//data->l_right = 0;
		//data->l_up = 0;
		//data->l_down = 0;

		data->left = 0;
	}
	else if (keycode == RIGHT)
	{
		//data->l_left = 0;
		data->l_right = 1;
		//data->l_up = 0;
		//data->l_down = 0;

		data->right = 0;
	}
	else if (keycode == UP)
	{
		//data->l_left = 0;
		//data->l_right = 0;
		data->l_up = 1;
		//data->l_down = 0;

		data->up = 0;
	}
	else if (keycode == DOWN)
	{
		//data->l_left = 0;
		//data->l_right = 0;
		//data->l_up = 0;
		data->l_down = 1;

		data->down = 0;
	}


	if (keycode == LEFT2)
	{
		data->l_left2 = 1;
		//data->l_right = 0;
		//data->l_up = 0;
		//data->l_down = 0;

		data->left2 = 0;
	}
	else if (keycode == RIGHT2)
	{
		//data->l_left = 0;
		data->l_right2 = 1;
		//data->l_up = 0;
		//data->l_down = 0;

		data->right2 = 0;
	}
	else if (keycode == UP2)
	{
		//data->l_left = 0;
		//data->l_right = 0;
		data->l_up2 = 1;
		//data->l_down = 0;

		data->up2 = 0;
	}
	else if (keycode == DOWN2)
	{
		//data->l_left = 0;
		//data->l_right = 0;
		//data->l_up = 0;
		data->l_down2 = 1;

		data->down2 = 0;
	}
	return (1);
}
