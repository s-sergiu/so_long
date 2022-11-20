/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:37:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/20 17:25:55 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	add_player_box(t_data **data, int posx, int posy)
{
	(*data)->player_box = mlx_new_image((*data)->mlx, 32, 32);
	ft_memset((*data)->player_box->pixels, 200, 32 * 32 * 4);
	mlx_image_to_window((*data)->mlx, (*data)->player_box, posx, posy);
}

void	add_player(t_data **data, int posx, int posy)
{
	(*data)->player = mlx_load_png("assets/player/idle/right/1.png");
	(*data)->player_img = mlx_texture_to_image((*data)->mlx, (*data)->player);
	mlx_delete_texture((*data)->player);
	mlx_image_to_window((*data)->mlx, (*data)->player_img, posx, posy);
}

void	put_floor_type(t_data **data, char c, int width, int height)
{
	if (c == '1')
		mlx_image_to_window((*data)->mlx, (*data)->tile_wall, width, height);
	else 
		mlx_image_to_window((*data)->mlx, (*data)->tile_floor, width, height);
}
void	put_tile(t_data **data)
{
	t_texture *tiles;
	int	chunk = 0;
	int	chunk_h = 0;
	int i;
	int j;
	int	width;
	int	height;

	i = -1;
	j = -1;
	tiles = NULL;
	init_tile_textures(&tiles);
	(*data)->tile_wall = mlx_texture_to_image((*data)->mlx, tiles->floor[7]);
	(*data)->tile_floor = mlx_texture_to_image((*data)->mlx, tiles->floor[3]);
	(*data)->collectible = mlx_texture_to_image((*data)->mlx, tiles->floor[6]);
	(*data)->exit = mlx_texture_to_image((*data)->mlx, tiles->floor[5]);
	width = ft_strlen(*(*data)->map);
	height = ft_arrlength((*data)->map);
	mlx_image_to_window((*data)->mlx, (*data)->tile_wall, 0, 0);
	while (++i < height)
	{
		while (++j < width)
		{
			if ((*data)->map[i][j] == 'P')
			{
				mlx_image_to_window((*data)->mlx, (*data)->tile_floor, chunk, chunk_h);
				add_player_box(data, chunk, chunk_h);
				add_player(data, chunk - 16, chunk_h - 20);
			}
			else if ((*data)->map[i][j] == '1')
				mlx_image_to_window((*data)->mlx, (*data)->tile_wall, chunk, chunk_h);
			else if ((*data)->map[i][j] == 'E')
			{
				mlx_image_to_window((*data)->mlx, (*data)->tile_floor, chunk, chunk_h);
				mlx_image_to_window((*data)->mlx, (*data)->exit, chunk, chunk_h);
			}
			else if ((*data)->map[i][j] == 'C')
			{
				mlx_image_to_window((*data)->mlx, (*data)->tile_floor, chunk, chunk_h);
				mlx_image_to_window((*data)->mlx, (*data)->collectible, chunk, chunk_h);
			}
			else
				mlx_image_to_window((*data)->mlx, (*data)->tile_floor, chunk, chunk_h);
			chunk += TILE;
		}
		chunk_h += TILE;
		chunk = 0;
		j = -1;
	}
}


void	draw_map(t_data **data)
{
	ft_memset((*data)->img->pixels, 255, WIDTH * HEIGHT * 4);
	mlx_image_to_window((*data)->mlx, (*data)->img, 0, 0);
	put_tile(data);
}

