/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:13:46 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/17 04:00:08 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n",map[i++]);
}

void	print_list(t_list *head)
{
	t_list *cursor;
	int		i;

	cursor = head;
	i = 0;
	while(cursor)
	{
		printf("item %d is: %d,%d.\n", i++, cursor->position->x, cursor->position->y);
		cursor = cursor->next;
	}
}

t_position	*get_exit_position(char **map)
{
	t_position *position;

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
	t_position *position;

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

t_position	calculate_coords(t_position *player, t_position *movement)
{
	t_position position;		

	position.x = player->x + movement->x;
	position.y = player->y + movement->y;

	return (position);
}

int	same_coords(t_position *player, t_position *exit)
{
	if (player->x == exit->x && player->y == exit->y)
		return (0);
	return (1);
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
	return (map);
}

int	not_visited(t_position *position, t_list *head)
{
	t_list *cursor;
	
	cursor = head;
	while(cursor)
	{
		if (same_coords(cursor->position, position) == 0)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

int	is_valid_coord(t_position position, char **map, t_list *head, t_list *head2)
{
	if ((not_visited(&position, head2) == 1 || not_visited(&position, head)) == 0 
			&& map[position.x][position.y] != '1' && map[position.x][position.y])
		return (0);
	return (1);
}

void	travel_map(t_position *player, char **map)
{
	map[player->x][player->y] = 'X';	
}

void	has_valid_path(t_map *map)
{
	int		i;
	t_position *node;
	t_position new_pos;
	t_list		*temp;

	i = 0;
	travel_map(map->player, map->map);
	while (1)
	{
		while (map->movements[i])
		{
			map->move_flag = 0;
			new_pos = calculate_coords(map->player, map->movements[i++]);
			if (is_valid_coord(new_pos, map->map, map->visited_list,
				map->double_visited) == 0)
			{
				node = (t_position *)malloc(sizeof(t_position));
				node->x = map->player->x;
				node->y = map->player->y;
				ft_lstadd_front(&map->visited_list, ft_lstnew(node));
				map->player->x = new_pos.x;
				map->player->y = new_pos.y;
				travel_map(map->player, map->map);
				map->move_flag = 1;
				break ;
			}
		}
		if (map->move_flag == 0)
		{
				ft_lstadd_front(&map->double_visited, ft_lstnew(map->player));	
				if (map->visited_list == NULL)
					return ;
				temp = map->visited_list;
				map->player = map->visited_list->position;
				map->visited_list = map->visited_list->next;
				free(temp);
				temp = NULL;
		}
		i = 0;
	}
}
