/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:13:46 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/17 06:57:50 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	same_coords(t_position *player, t_position *exit)
{
	if (player->x == exit->x && player->y == exit->y)
		return (0);
	return (1);
}

int	not_visited(t_position *position, t_list *head)
{
	t_list	*cursor;

	cursor = head;
	while (cursor)
	{
		if (same_coords(cursor->position, position) == 0)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

int	is_valid_coord(t_position position, char **map, t_list *head, t_list *head2)
{
	if ((not_visited(&position, head2) == 1
			|| not_visited(&position, head)) == 0
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
	int			i;
	t_position	*node;
	t_position	new_pos;
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
