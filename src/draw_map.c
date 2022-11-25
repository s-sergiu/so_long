/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:37:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/26 00:04:02 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_list(t_data **data)
{
	t_list *current;
	int	i;

	i = 0;
	current = (*data)->collectible_list;
	while (current)
	{
		if (current->position)
			i++;
		current = current->next;
	}
}
void	put_collectable(t_data **data, int width, int height)
{
	mlx_texture_t	*tiles;
	mlx_image_t		*image;

	tiles = mlx_load_png("assets/tiles/other/35.png");
	image = mlx_texture_to_image((*data)->mlx, tiles);
	if ((*data)->map[height][width] == 'C')
	{
		ft_lstadd_front(&((*data)->collectible_list), ft_lstnew(image));
		((*data)->collectible_list)->x = width;
		((*data)->collectible_list)->y = height;
		mlx_image_to_window((*data)->mlx, ((*data)->collectible_list)->position, width * TILE, height * TILE);
	}
	mlx_delete_texture(tiles);
}

void	put_enemy(t_data **data, int width, int height)
{
	mlx_texture_t	*tiles;
	mlx_image_t		*image;

	tiles = mlx_load_png("assets/enemy/idle/1.png");
	image = mlx_texture_to_image((*data)->mlx, tiles);
	if ((*data)->map[height][width] == 'G')
	{
		ft_lstadd_front(&((*data)->enemy_list), ft_lstnew(image));
		((*data)->enemy_list)->x = width;
		((*data)->enemy_list)->y = height;
		mlx_image_to_window((*data)->mlx, ((*data)->enemy_list)->position, width * TILE - 14, height * TILE - 16);
	}
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
	ft_memset((*data)->player_box->pixels, 0, TILE * TILE * 4);
	mlx_image_to_window((*data)->mlx, (*data)->player_box, posx, posy);
}

void	put_door(t_data **data)
{
	mlx_texture_t	*tiles;
	t_position	*exit;

	exit = get_component((*data)->map, 'E');
	tiles = mlx_load_png("assets/tiles/other/33.png");
	(*data)->exit = mlx_texture_to_image((*data)->mlx, tiles);
	mlx_image_to_window((*data)->mlx, (*data)->exit, exit->x * 32, exit->y * 32);
	free(exit);
	mlx_delete_texture(tiles);
}

void	draw_enemies(t_data **data)
{
	int y;
	int x;

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
	draw_enemies(data);
	put_door(data);
	add_player_box(data);
	add_player(data);
}
