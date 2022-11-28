/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:46:57 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/28 04:10:35 by ssergiu          ###   ########.fr       */
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

void	destroy_idle_structure(t_data **data)
{
	t_idle	*image;

	image = (*data)->idle;
	free(image);
}

void	destroy_tile_structure(t_data **data)
{
	t_texture	*image;

	image = (*data)->tiles;
	free(image);
}

void	destroy_and_free(t_data **data)
{
	free_split((*data)->map);
	destroy_idle_structure(data);
	destroy_tile_structure(data);
}
