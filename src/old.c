/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:53 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/22 01:08:26 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

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

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D) || mlx_is_key_down(data->mlx,
		MLX_KEY_A) || mlx_is_key_down(data->mlx, MLX_KEY_W) ||
		mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		{
			run_left_animation(data);
			data->player_img->instances[0].x -= 120 * data->mlx->delta_time;
			data->player_box->instances[0].x -= 120 * data->mlx->delta_time;
		}
		if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		{
			data->player_img->instances[0].y += 180 * data->mlx->delta_time;
			data->player_box->instances[0].y += 180 * data->mlx->delta_time;
		}
		if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		{
			data->player_img->instances[0].y -= 120 * data->mlx->delta_time;
			data->player_box->instances[0].y -= 120 * data->mlx->delta_time;
		}
		if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		{
			run_right_animation(data);
			data->player_img->instances[0].x += 180 * data->mlx->delta_time;
			data->player_box->instances[0].x += 180 * data->mlx->delta_time;
		}
	}
	else 
		idle_animation(data);
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
//	mlx_loop_hook(data->mlx, &hook, data);
	draw_map(&data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
