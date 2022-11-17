/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:53 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/17 15:56:35 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	attack_left(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/Attack1_1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/Attack1_2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/Attack1_3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 40)
	{
		new_image = mlx_load_png("assets/Attack1_4.png");
		player = mlx_texture_to_image(data->mlx, new_image);
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
		new_image = mlx_load_png("assets/RAttack1_1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/RAttack1_2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/RAttack1_3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/RAttack1_4.png");
		player = mlx_texture_to_image(data->mlx, new_image);
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
		new_image = mlx_load_png("assets/Death_1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/Death_2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/Death_3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/Death_4.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 28)
	{
		new_image = mlx_load_png("assets/Death_5.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 35)
	{
		new_image = mlx_load_png("assets/Death_6.png");
		player = mlx_texture_to_image(data->mlx, new_image);
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
		new_image = mlx_load_png("assets/Run_back_1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/Run_back_2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/Run_back_3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/Run_back_4.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 28)
	{
		new_image = mlx_load_png("assets/Run_back_5.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 35)
	{
		new_image = mlx_load_png("assets/Run_back_6.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 42)
	{
		new_image = mlx_load_png("assets/Run_back_7.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	if (frames == 49)
	{
		new_image = mlx_load_png("assets/Run_back_8.png");
		player = mlx_texture_to_image(data->mlx, new_image);
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
		new_image = mlx_load_png("assets/Run_1.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 7)
	{
		new_image = mlx_load_png("assets/Run_2.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 14)
	{
		new_image = mlx_load_png("assets/Run_3.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 21)
	{
		new_image = mlx_load_png("assets/Run_4.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 28)
	{
		new_image = mlx_load_png("assets/Run_5.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 35)
	{
		new_image = mlx_load_png("assets/Run_6.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 42)
	{
		new_image = mlx_load_png("assets/Run_7.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
	}
	else if (frames == 49)
	{
		new_image = mlx_load_png("assets/Run_8.png");
		player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
		frames = -1;
	}
	frames++;
}

void	idle_animation(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*player[8];
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/Idle_s_1.png");
		player[0] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player[0]->pixels, 64 * 64 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/Idle_s_2.png");
		player[1] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player[1]->pixels, 64 * 64 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/Idle_s_3.png");
		player[2] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player[2]->pixels, 64 * 64 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/Idle_s_4.png");
		player[3] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player[3]->pixels, 64 * 64 * 4);
	}
	if (frames == 28)
	{
		new_image = mlx_load_png("assets/Idle_s_5.png");
		player[4] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player[4]->pixels, 64 * 64 * 4);
	}
	if (frames == 35)
	{
		new_image = mlx_load_png("assets/Idle_s_6.png");
		player[5] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player[5]->pixels, 64 * 64 * 4);
	}
	if (frames == 42)
	{
		new_image = mlx_load_png("assets/Idle_s_7.png");
		player[6] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player[6]->pixels, 64 * 64 * 4);
	}
	if (frames == 49)
	{
		new_image = mlx_load_png("assets/Idle_s_8.png");
		player[7] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, player[7]->pixels, 64 * 64 * 4);
		frames = -1;
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
			data->player_img->instances[0].y -= 3;
		else
			data->player_img->instances[0].y += 3;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) || mlx_is_key_down(data->mlx,
			MLX_KEY_D))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		{
			run_animation(data);
			data->player_img->instances[0].x += 3;
		}
		else
		{
		left_run_animation(data);
		data->player_img->instances[0].x -= 3;
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
			new_image = mlx_load_png("assets/Death_6.png");
			player = mlx_texture_to_image(data->mlx, new_image);
			memcpy(data->player_img->pixels, player->pixels, 64 * 64 * 4);
			break ;
		}
	}
}

void	init_game(char *argv)
{
	t_data	*data;

	if (init_game_data(&data, argv))
	{
		mlx_loop_hook(data->mlx, &hook, data);
		put_tile(&data);
		add_player(&data);
		mlx_loop(data->mlx);
		mlx_terminate(data->mlx);
	}
}
