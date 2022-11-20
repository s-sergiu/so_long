/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:53 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/20 17:32:27 by ssergiu          ###   ########.fr       */
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

void	left_run_animation(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/player/run_left/0.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/player/run_left/1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/player/run_left/2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/player/run_left/3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 28)
	{
		new_image = mlx_load_png("assets/player/run_left/4.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 35)
	{
		new_image = mlx_load_png("assets/player/run_left/5.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 42)
	{
		new_image = mlx_load_png("assets/player/run_left/6.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 49)
	{
		new_image = mlx_load_png("assets/player/run_left/7.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
		frames = -1;
	}
	frames++;
}

void	run_animation(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/player/run_right/0.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 7)
	{
		new_image = mlx_load_png("assets/player/run_right/1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 14)
	{
		new_image = mlx_load_png("assets/player/run_right/2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 21)
	{
		new_image = mlx_load_png("assets/player/run_right/3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 28)
	{
		new_image = mlx_load_png("assets/player/run_right/4.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 35)
	{
		new_image = mlx_load_png("assets/player/run_right/5.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 42)
	{
		new_image = mlx_load_png("assets/player/run_right/6.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 49)
	{
		new_image = mlx_load_png("assets/player/run_right/7.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		mlx_delete_texture(new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
		frames = -1;
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
			run_animation(data);
			data->player_img->instances[0].x += 180 * data->mlx->delta_time;
			data->player_box->instances[0].x += 180 * data->mlx->delta_time;
		}
		else
		{
		left_run_animation(data);
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

void	init_idle_texture(t_idle **texture)
{
	(*texture) = (t_idle *)malloc(sizeof(t_idle));
	(*texture)->right[0] = mlx_load_png("assets/player/idle/right/0.png");
	(*texture)->right[1] = mlx_load_png("assets/player/idle/right/1.png");
	(*texture)->right[2] = mlx_load_png("assets/player/idle/right/2.png");
	(*texture)->right[3] = mlx_load_png("assets/player/idle/right/3.png");
	(*texture)->right[4] = mlx_load_png("assets/player/idle/right/4.png");
	(*texture)->right[5] = mlx_load_png("assets/player/idle/right/5.png");
	(*texture)->right[6] = mlx_load_png("assets/player/idle/right/6.png");
	(*texture)->right[7] = mlx_load_png("assets/player/idle/right/7.png");
	(*texture)->right[8] = NULL;
	(*texture)->left[0] = mlx_load_png("assets/player/idle/left/0.png");
	(*texture)->left[1] = mlx_load_png("assets/player/idle/left/1.png");
	(*texture)->left[2] = mlx_load_png("assets/player/idle/left/2.png");
	(*texture)->left[3] = mlx_load_png("assets/player/idle/left/3.png");
	(*texture)->left[4] = mlx_load_png("assets/player/idle/left/4.png");
	(*texture)->left[5] = mlx_load_png("assets/player/idle/left/5.png");
	(*texture)->left[6] = mlx_load_png("assets/player/idle/left/6.png");
	(*texture)->left[7] = mlx_load_png("assets/player/idle/left/7.png");
	(*texture)->left[8] = NULL;
}

void	init_game_data(t_data **data, char *argv)
{
	init_idle_texture(&(*data)->idle);
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