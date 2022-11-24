/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:37:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/24 14:41:11 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_collectable(t_data **data, int width, int height)
{
	mlx_texture_t	*tiles;
	static int		i;

	tiles = mlx_load_png("assets/tiles/other/35.png");
	(*data)->collectibles[i] = mlx_texture_to_image((*data)->mlx, tiles);
	if ((*data)->map[height][width] == 'C')
		mlx_image_to_window((*data)->mlx, ((*data)->collectibles)[i], width * TILE, height * TILE);
	mlx_delete_texture(tiles);
}

void	put_floor(t_data **data, char c, int width, int height)
{
	t_texture *tiles;

	tiles = (*data)->tiles;
	if (c == '1')
		mlx_image_to_window((*data)->mlx, tiles->wall_img[0], width, height);
	else 
		mlx_image_to_window((*data)->mlx, tiles->floor_img[0], width, height);
}

t_position	*get_component(char **map, char type)
{
	int x;
	int y;
	t_position	*exit;

	y = -1;
	exit = (t_position *)malloc(sizeof(t_position));
	while(map[++y])
	{
		x = -1;
		while(map[y][++x])
		{
			if (map[y][x] == type)
			{
				exit->x = x;
				exit->y = y;
				return (exit);
			}
		}
	}
	return (NULL);
}

void	add_player(t_data **data)
{
	int		posx;
	int		posy;
	t_idle	*player;
	t_position *player_pos;

	player_pos = get_component((*data)->map, 'P');
	posx = player_pos->x * TILE;
	posy = player_pos->y * TILE;
	player = (*data)->idle;
	mlx_image_to_window((*data)->mlx, player->right_idle[0], posx - 16, posy - 24);
}

void	add_player_box(t_data **data)
{
	int		posx;
	int		posy;
	t_position *player_pos;

	player_pos = get_component((*data)->map, 'P');
	posx = player_pos->x * TILE;
	posy = player_pos->y * TILE;
	(*data)->player_box = mlx_new_image((*data)->mlx, TILE, TILE);
	ft_memset((*data)->player_box->pixels, 200, TILE * TILE * 4);
	mlx_image_to_window((*data)->mlx, (*data)->player_box, posx, posy);
}

void	put_door(t_data **data)
{
	mlx_texture_t	*tiles;
	mlx_image_t		*exit_img;
	t_position	*exit;

	exit = get_component((*data)->map, 'E');
	tiles = mlx_load_png("assets/tiles/other/33.png");
	exit_img = mlx_texture_to_image((*data)->mlx, tiles);
	mlx_image_to_window((*data)->mlx, exit_img, exit->x * 32, exit->y * 32);
	free(exit);
	mlx_delete_texture(tiles);
}

void	draw_collectables(t_data **data)
{
	int y;
	int x;

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
	int y;
	int x;

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
	init_idle_texture(data);
	init_run_texture(data);
	init_tile_textures(data);
	ft_memset((*data)->img->pixels, 255, WIDTH * HEIGHT * 4);
	mlx_image_to_window((*data)->mlx, (*data)->img, 0, 0);
	draw_tiles(data);
	draw_collectables(data);
	put_door(data);
	add_player_box(data);
	add_player(data);
}
