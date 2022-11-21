/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:53 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/21 18:27:26 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	attack_left(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/player/attack_left/0.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/player/attack_left/1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/player/attack_left/2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 40)
	{
		new_image = mlx_load_png("assets/player/attack_left/3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
		frames = -1;
	}
	frames++;
}

void	attack_right(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/player/attack_right/0.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/player/attack_right/1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/player/attack_right/2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/player/attack_right/3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
		frames = -1;
	}
	frames++;
}

void	death_animation(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/player/death_right/0.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/player/death_right/1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/player/death_right/2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/player/death_right/3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 28)
	{
		new_image = mlx_load_png("assets/player/death_right/4.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 35)
	{
		new_image = mlx_load_png("assets/player/death_right/5.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
		data->player_dead = 1;
		frames = -1;
	}
	frames++;
}

void	run_left_animation(void *param)
{
	t_data			*data;
	mlx_image_t		*player[8];
	static int		frames;
	static int		i;

	data = param;
	if (frames == 0 || frames % 7 == 0)
	{
		player[i] = mlx_texture_to_image(data->mlx, data->run->left[i]);
		memcpy(data->player_img->pixels, player[i]->pixels, 64 * 64 * 4);
		if(i == 7)
		{
			frames = -1;
			i = - 1;
		}
		i++;
	}
	frames++;
}

void	run_right_animation(void *param)
{
	t_data			*data;
	mlx_image_t		*player[8];
	static int		frames;
	static int		i;

	data = param;
	if (frames == 0 || frames % 7 == 0)
	{
		player[i] = mlx_texture_to_image(data->mlx, data->run->right[i]);
		memcpy(data->player_img->pixels, player[i]->pixels, 64 * 64 * 4);
		if(i == 7)
		{
			frames = -1;
			i = - 1;
		}
		i++;
	}
	frames++;
}

void	idle_animation(void *param)
{
	t_data			*data;
	mlx_image_t		*player[8];
	static int		frames;
	static int		i;

	data = param;
	if (frames == 0 || frames % 7 == 0)
	{
		player[i] = mlx_texture_to_image(data->mlx, data->idle->right[i]);
		memcpy(data->player_img->pixels, player[i]->pixels, 64 * 64 * 4);
		if(i == 7)
		{
			frames = -1;
			i = - 1;
		}
		i++;
	}
	frames++;
}

void	hook(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*player;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) || mlx_is_key_down(data->mlx,
		MLX_KEY_S))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		{
			data->player_img->instances[0].y -= 120 * data->mlx->delta_time;
			data->player_box->instances[0].y -= 120 * data->mlx->delta_time;
		}
		else
		{
			data->player_img->instances[0].y += 180 * data->mlx->delta_time;
			data->player_box->instances[0].y += 180 * data->mlx->delta_time;
		}
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) || mlx_is_key_down(data->mlx,
			MLX_KEY_D))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		{
			run_right_animation(data);
			data->player_img->instances[0].x += 180 * data->mlx->delta_time;
			data->player_box->instances[0].x += 180 * data->mlx->delta_time;
		}
		else
		{
		run_left_animation(data);
		data->player_img->instances[0].x -= 120 * data->mlx->delta_time;
		data->player_box->instances[0].x -= 120 * data->mlx->delta_time;
		}
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		attack_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_X))
		death_animation(data);
	else
	{
		idle_animation(data);
		while (data->player_dead == 1)
		{
			new_image = mlx_load_png("assets/player/death_right/1.png");
			player = mlx_texture_to_image(data->mlx, new_image);
			mlx_delete_texture(new_image);
			memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
			break ;
		}
	}
}

void	init_run_texture(t_data **data)
{
	t_run *run;

	(*data)->run  = (t_run *)malloc(sizeof(t_run));
	run = (*data)->run;
	run->right[0] = mlx_load_png("assets/player/run/right/0.png");
	run->right[1] = mlx_load_png("assets/player/run/right/1.png");
	run->right[2] = mlx_load_png("assets/player/run/right/2.png");
	run->right[3] = mlx_load_png("assets/player/run/right/3.png");
	run->right[4] = mlx_load_png("assets/player/run/right/4.png");
	run->right[5] = mlx_load_png("assets/player/run/right/5.png");
	run->right[6] = mlx_load_png("assets/player/run/right/6.png");
	run->right[7] = mlx_load_png("assets/player/run/right/7.png");
	run->right[8] = NULL;
	run->left[0] = mlx_load_png("assets/player/run/left/0.png");
	run->left[1] = mlx_load_png("assets/player/run/left/1.png");
	run->left[2] = mlx_load_png("assets/player/run/left/2.png");
	run->left[3] = mlx_load_png("assets/player/run/left/3.png");
	run->left[4] = mlx_load_png("assets/player/run/left/4.png");
	run->left[5] = mlx_load_png("assets/player/run/left/5.png");
	run->left[6] = mlx_load_png("assets/player/run/left/6.png");
	run->left[7] = mlx_load_png("assets/player/run/left/7.png");
	run->left[8] = NULL;
}

void	init_idle_texture(t_data **data)
{
	t_idle *idle;
	
	(*data)->idle = (t_idle *)malloc(sizeof(t_idle));
	idle = (*data)->idle;	
	idle->right[0] = mlx_load_png("assets/player/idle/right/0.png");
	idle->right[1] = mlx_load_png("assets/player/idle/right/1.png");
	idle->right[2] = mlx_load_png("assets/player/idle/right/2.png");
	idle->right[3] = mlx_load_png("assets/player/idle/right/3.png");
	idle->right[4] = mlx_load_png("assets/player/idle/right/4.png");
	idle->right[5] = mlx_load_png("assets/player/idle/right/5.png");
	idle->right[6] = mlx_load_png("assets/player/idle/right/6.png");
	idle->right[7] = mlx_load_png("assets/player/idle/right/7.png");
	idle->right[8] = NULL;
	idle->left[0] = mlx_load_png("assets/player/idle/left/0.png");
	idle->left[1] = mlx_load_png("assets/player/idle/left/1.png");
	idle->left[2] = mlx_load_png("assets/player/idle/left/2.png");
	idle->left[3] = mlx_load_png("assets/player/idle/left/3.png");
	idle->left[4] = mlx_load_png("assets/player/idle/left/4.png");
	idle->left[5] = mlx_load_png("assets/player/idle/left/5.png");
	idle->left[6] = mlx_load_png("assets/player/idle/left/6.png");
	idle->left[7] = mlx_load_png("assets/player/idle/left/7.png");
	idle->left[8] = NULL;
}

void	init_game_data(t_data **data, char *argv)
{
	init_idle_texture(data);
	init_run_texture(data);
	(*data)->map_string = read_map(argv);
	(*data)->map = ft_split((*data)->map_string, '\n');
	free((*data)->map_string);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	(*data)->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	(*data)->img = mlx_new_image((*data)->mlx, WIDTH, HEIGHT);
}

void	game_loop(char *argv)
{
	t_data *data;

	init_game_data(&data, argv);
	mlx_loop_hook(data->mlx, &hook, data);
	draw_map(&data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
