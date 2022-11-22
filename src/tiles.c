/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:44:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/22 02:00:32 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
void init_tile_textures(t_data **data)
{
	t_texture *tiles;

	(*data)->tiles  = (t_texture *)malloc(sizeof(t_texture));
	tiles = (*data)->tiles;
	tiles->floor[0] = mlx_load_png("assets/tiles/floor/0.png");
	tiles->floor[1] = mlx_load_png("assets/tiles/floor/1.png");
	tiles->floor[2] = mlx_load_png("assets/tiles/floor/2.png");
	tiles->floor[3] = mlx_load_png("assets/tiles/floor/3.png");
	tiles->floor[4] = mlx_load_png("assets/tiles/floor/4.png");
	tiles->floor[5] = mlx_load_png("assets/tiles/floor/5.png");
	tiles->floor[6] = mlx_load_png("assets/tiles/floor/6.png");
	tiles->floor[7] = mlx_load_png("assets/tiles/floor/7.png");
	tiles->floor[8] = NULL;
	tiles->wall[0] = mlx_load_png("assets/tiles/wall/0.png");
	tiles->wall[1] = mlx_load_png("assets/tiles/wall/1.png");
	tiles->wall[2] = mlx_load_png("assets/tiles/wall/2.png");
	tiles->wall[3] = mlx_load_png("assets/tiles/wall/3.png");
	tiles->wall[4] = mlx_load_png("assets/tiles/wall/4.png");
	tiles->wall[5] = NULL;
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
