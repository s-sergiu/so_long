/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:44:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/24 16:11:20 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	delete_tile_textures(t_data **data)
{
	t_texture	*tiles;

	tiles = (*data)->tiles;
	mlx_delete_texture(tiles->floor[0]);
	mlx_delete_texture(tiles->floor[1]);
	mlx_delete_texture(tiles->floor[2]);
	mlx_delete_texture(tiles->floor[3]);
	mlx_delete_texture(tiles->floor[4]);
	mlx_delete_texture(tiles->floor[5]);
	mlx_delete_texture(tiles->floor[6]);
	mlx_delete_texture(tiles->floor[7]);
	mlx_delete_texture(tiles->wall[0]);
	mlx_delete_texture(tiles->wall[1]);
	mlx_delete_texture(tiles->wall[2]);
	mlx_delete_texture(tiles->wall[3]);
	mlx_delete_texture(tiles->wall[4]);
}

void	delete_run_textures(t_data **data)
{
	t_run	*run;

	run = (*data)->run;
	mlx_delete_texture(run->right[0]);
	mlx_delete_texture(run->right[1]);
	mlx_delete_texture(run->right[2]);
	mlx_delete_texture(run->right[3]);
	mlx_delete_texture(run->right[4]);
	mlx_delete_texture(run->right[5]);
	mlx_delete_texture(run->right[6]);
	mlx_delete_texture(run->right[7]);
	mlx_delete_texture(run->left[0]);
	mlx_delete_texture(run->left[1]);
	mlx_delete_texture(run->left[2]);
	mlx_delete_texture(run->left[3]);
	mlx_delete_texture(run->left[4]);
	mlx_delete_texture(run->left[5]);
	mlx_delete_texture(run->left[6]);
	mlx_delete_texture(run->left[7]);
}

void	delete_idle_textures(t_data **data)
{
	t_idle	*idle;

	idle = (*data)->idle;
	mlx_delete_texture(idle->right[0]);
	mlx_delete_texture(idle->right[1]);
	mlx_delete_texture(idle->right[2]);
	mlx_delete_texture(idle->right[3]);
	mlx_delete_texture(idle->right[4]);
	mlx_delete_texture(idle->right[5]);
	mlx_delete_texture(idle->right[6]);
	mlx_delete_texture(idle->right[7]);
	mlx_delete_texture(idle->left[0]);
	mlx_delete_texture(idle->left[1]);
	mlx_delete_texture(idle->left[2]);
	mlx_delete_texture(idle->left[3]);
	mlx_delete_texture(idle->left[4]);
	mlx_delete_texture(idle->left[5]);
	mlx_delete_texture(idle->left[6]);
	mlx_delete_texture(idle->left[7]);
}

void	load_run_images(t_data **data)
{
	t_run	*run;

	run = (*data)->run;
	run->right_run[0] = mlx_texture_to_image((*data)->mlx, run->right[0]);
	run->right_run[1] = mlx_texture_to_image((*data)->mlx, run->right[1]);
	run->right_run[2] = mlx_texture_to_image((*data)->mlx, run->right[2]);
	run->right_run[3] = mlx_texture_to_image((*data)->mlx, run->right[3]);
	run->right_run[4] = mlx_texture_to_image((*data)->mlx, run->right[4]);
	run->right_run[5] = mlx_texture_to_image((*data)->mlx, run->right[5]);
	run->right_run[6] = mlx_texture_to_image((*data)->mlx, run->right[6]);
	run->right_run[7] = mlx_texture_to_image((*data)->mlx, run->right[7]);
	run->right_run[8] = NULL;
	run->left_run[0] = mlx_texture_to_image((*data)->mlx, run->left[0]);
	run->left_run[1] = mlx_texture_to_image((*data)->mlx, run->left[1]);
	run->left_run[2] = mlx_texture_to_image((*data)->mlx, run->left[2]);
	run->left_run[3] = mlx_texture_to_image((*data)->mlx, run->left[3]);
	run->left_run[4] = mlx_texture_to_image((*data)->mlx, run->left[4]);
	run->left_run[5] = mlx_texture_to_image((*data)->mlx, run->left[5]);
	run->left_run[6] = mlx_texture_to_image((*data)->mlx, run->left[6]);
	run->left_run[7] = mlx_texture_to_image((*data)->mlx, run->left[7]);
	run->left_run[8] = NULL;
}

void	destroy_run_structure(t_data **data)
{
	t_run	*image;

	image = (*data)->run;
	free(image);
}

void	load_idle_images(t_data **data)
{
	t_idle	*idle;

	idle = (*data)->idle;
	idle->right_idle[0] = mlx_texture_to_image((*data)->mlx, idle->right[0]);
	idle->right_idle[1] = mlx_texture_to_image((*data)->mlx, idle->right[1]);
	idle->right_idle[2] = mlx_texture_to_image((*data)->mlx, idle->right[2]);
	idle->right_idle[3] = mlx_texture_to_image((*data)->mlx, idle->right[3]);
	idle->right_idle[4] = mlx_texture_to_image((*data)->mlx, idle->right[4]);
	idle->right_idle[5] = mlx_texture_to_image((*data)->mlx, idle->right[5]);
	idle->right_idle[6] = mlx_texture_to_image((*data)->mlx, idle->right[6]);
	idle->right_idle[7] = mlx_texture_to_image((*data)->mlx, idle->right[7]);
	idle->right_idle[8] = NULL;
	idle->left_idle[0] = mlx_texture_to_image((*data)->mlx, idle->left[0]);
	idle->left_idle[1] = mlx_texture_to_image((*data)->mlx, idle->left[1]);
	idle->left_idle[2] = mlx_texture_to_image((*data)->mlx, idle->left[2]);
	idle->left_idle[3] = mlx_texture_to_image((*data)->mlx, idle->left[3]);
	idle->left_idle[4] = mlx_texture_to_image((*data)->mlx, idle->left[4]);
	idle->left_idle[5] = mlx_texture_to_image((*data)->mlx, idle->left[5]);
	idle->left_idle[6] = mlx_texture_to_image((*data)->mlx, idle->left[6]);
	idle->left_idle[7] = mlx_texture_to_image((*data)->mlx, idle->left[7]);
	idle->left_idle[8] = NULL;
}

void	destroy_idle_structure(t_data **data)
{
	t_idle	*image;

	image = (*data)->idle;
	free(image);
}

void	load_tile_images(t_data **data)
{
	t_texture	*tiles;

	tiles = (*data)->tiles;
	tiles->floor_img[0] = mlx_texture_to_image((*data)->mlx, tiles->floor[0]);
	tiles->floor_img[1] = mlx_texture_to_image((*data)->mlx, tiles->floor[1]);
	tiles->floor_img[2] = mlx_texture_to_image((*data)->mlx, tiles->floor[2]);
	tiles->floor_img[3] = mlx_texture_to_image((*data)->mlx, tiles->floor[3]);
	tiles->floor_img[4] = mlx_texture_to_image((*data)->mlx, tiles->floor[4]);
	tiles->floor_img[5] = mlx_texture_to_image((*data)->mlx, tiles->floor[5]);
	tiles->floor_img[6] = mlx_texture_to_image((*data)->mlx, tiles->floor[6]);
	tiles->floor_img[7] = mlx_texture_to_image((*data)->mlx, tiles->floor[7]);
	tiles->floor_img[8] = NULL;
	tiles->wall_img[0] = mlx_texture_to_image((*data)->mlx, tiles->wall[0]);
	tiles->wall_img[1] = mlx_texture_to_image((*data)->mlx, tiles->wall[1]);
	tiles->wall_img[2] = mlx_texture_to_image((*data)->mlx, tiles->wall[2]);
	tiles->wall_img[3] = mlx_texture_to_image((*data)->mlx, tiles->wall[3]);
	tiles->wall_img[4] = mlx_texture_to_image((*data)->mlx, tiles->wall[4]);
	tiles->wall_img[5] = NULL;
}

void	destroy_tile_structure(t_data **data)
{
	t_texture	*image;

	image = (*data)->tiles;
	free(image);
}

void init_tile_textures(t_data **data)
{
	t_texture	*tiles;

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
	load_tile_images(data);
	delete_tile_textures(data);
	
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
	load_run_images(data);
	delete_run_textures(data);
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
	load_idle_images(data);
	delete_idle_textures(data);
}
