/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:37:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/28 04:25:07 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	add_player_box(t_data **data)
{
	int			posx;
	int			posy;
	t_position	*player_pos;

	player_pos = get_component((*data)->map, 'P');
	posx = player_pos->x * TILE;
	posy = player_pos->y * TILE;
	(*data)->player_box = mlx_new_image((*data)->mlx, TILE, TILE);
	ft_memset((*data)->player_box->pixels, 0, TILE * TILE * 4);
	mlx_image_to_window((*data)->mlx, (*data)->player_box, posx, posy);
}

void	draw_enemies(t_data **data)
{
	int	y;
	int	x;

	y = -1;
	while ((*data)->map[++y])
	{
		x = -1;
		while ((*data)->map[y][++x])
			put_enemy(data, x, y);
	}
}

void	draw_collectables(t_data **data)
{
	int	y;
	int	x;

	y = -1;
	while ((*data)->map[++y])
	{
		x = -1;
		while ((*data)->map[y][++x])
			put_collectable(data, x, y);
	}
}

void	draw_tiles(t_data **data)
{
	int	y;
	int	x;

	y = -1;
	while ((*data)->map[++y])
	{
		x = -1;
		while ((*data)->map[y][++x])
			put_floor(data, (*data)->map[y][x], x * TILE, y * TILE);
	}
}

void	draw_map(t_data **data)
{
	int	width;
	int	height;

	width = TILE * ft_strlen(*(*data)->map);
	height = TILE * ft_arrlength((*data)->map);
	init_idle_texture(data);
	init_tile_textures(data);
	ft_memset((*data)->img->pixels, 255, width * height * 4);
	mlx_image_to_window((*data)->mlx, (*data)->img, 0, 0);
	draw_tiles(data);
	draw_collectables(data);
	put_door(data);
	//draw_enemies(data);
	add_player_box(data);
	add_player(data);
}
