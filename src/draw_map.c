/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:37:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/23 20:17:17 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	add_player_box(t_data **data, int posx, int posy)
{
	(*data)->player_box = mlx_new_image((*data)->mlx, TILE, TILE);
	ft_memset((*data)->player_box->pixels, 200, TILE * TILE * 4);
	mlx_image_to_window((*data)->mlx, (*data)->player_box, posx, posy);
}

void	add_player(t_data **data, int posx, int posy)
{
	(*data)->player = mlx_load_png("assets/player/idle/right/0.png");
	(*data)->player_img = mlx_texture_to_image((*data)->mlx, (*data)->player);
	mlx_delete_texture((*data)->player);
	mlx_image_to_window((*data)->mlx, (*data)->player_img, posx, posy);
}

void	put_floor_type(t_data **data, char c, int width, int height)
{
	if (c == '1')
		mlx_image_to_window((*data)->mlx, (*data)->tiles->wall_img[0], width, height);
	else 
		mlx_image_to_window((*data)->mlx, (*data)->tiles->floor_img[0], width, height);
}

void	put_tile(t_data **data)
{
	t_texture *tiles;
	int	chunk = 0;
	int	chunk_h = 0;
	int i;
	int j;

	i = -1;
	j = -1;
	tiles = (*data)->tiles;
	mlx_image_to_window((*data)->mlx, tiles->wall_img[0], 0, 0);
	while ((*data)->map[++i])
	{
		while ((*data)->map[i][++j])
		{
			put_floor_type(data, (*data)->map[i][j], chunk, chunk_h);
			chunk += TILE;
		}
		chunk_h += TILE;
		chunk = 0;
		j = -1;
	}
}


void	draw_map(t_data **data)
{
	init_idle_texture(data);
	init_run_texture(data);
	ft_memset((*data)->img->pixels, 255, WIDTH * HEIGHT * 4);
	mlx_image_to_window((*data)->mlx, (*data)->img, 0, 0);
	put_tile(data);
}

