/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:25:06 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/28 02:51:57 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_position	*get_exit_position(char **map)
{
	t_position	*position;

	position = (t_position *)malloc(sizeof(t_position));
	position->x = -1;
	position->y = 0;
	while (map[++position->x][position->y] != 0)
	{
		while (map[position->x][position->y] != 0)
			if (map[position->x][position->y++] == 'E')
				return (position);
		position->y = 0;
	}
	return (NULL);
}

t_position	*get_player_position(char **map)
{
	t_position	*position;

	position = (t_position *)malloc(sizeof(t_position));
	position->x = -1;
	position->y = 0;
	while (map[++position->x][position->y] != 0)
	{
		while (map[position->x][position->y] != 0)
			if (map[position->x][position->y++] == 'P')
				return (position);
		position->y = 0;
	}
	return (NULL);
}

void	destroy_structure(t_map *map)
{
	free(map->movements[0]);
	free(map->movements[1]);
	free(map->movements[2]);
	free(map->movements[3]);
	free_split(map->map);
	free(map->exit);
	free(map);
}

t_map	*init_structure(char *map_string)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->movements[0] = (t_position *)malloc(sizeof(t_position));
	map->movements[1] = (t_position *)malloc(sizeof(t_position));
	map->movements[2] = (t_position *)malloc(sizeof(t_position));
	map->movements[3] = (t_position *)malloc(sizeof(t_position));
	map->movements[4] = NULL;
	map->visited_list = NULL;
	map->double_visited = NULL;
	map->movements[0]->x = 0;
	map->movements[0]->y = -1;
	map->movements[1]->x = 0;
	map->movements[1]->y = 1;
	map->movements[2]->x = 1;
	map->movements[2]->y = 0;
	map->movements[3]->x = -1;
	map->movements[3]->y = 0;
	map->map = ft_split(map_string, '\n');
	map->player = get_player_position(map->map);
	map->exit = get_exit_position(map->map);
	map->map_loop = 0;
	return (map);
}

t_position	*get_component(char **map, char type)
{
	int			x;
	int			y;
	t_position	*exit;

	y = -1;
	exit = (t_position *)malloc(sizeof(t_position));
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
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
