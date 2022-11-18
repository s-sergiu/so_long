/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:13:46 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/18 12:26:11 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_position *player, char **map)
{
	map[player->x][player->y] = 'X';
}

void	move_player_to_new_pos(t_position new_pos, t_map **map)
{
	t_position	*node;

	node = (t_position *)malloc(sizeof(t_position));
	node->x = (*map)->player->x;
	node->y = (*map)->player->y;
	ft_lstadd_front(&(*map)->visited_list, ft_lstnew(node));
	(*map)->player->x = new_pos.x;
	(*map)->player->y = new_pos.y;
	move_player((*map)->player, (*map)->map);
	(*map)->move_flag = 1;
}

void	step_back(t_map **map)
{
	t_list		*temp;

	ft_lstadd_front(&(*map)->double_visited, ft_lstnew((*map)->player));
	if ((*map)->visited_list == NULL)
	{
		(*map)->map_loop = 1;
		return ;
	}
	temp = (*map)->visited_list;
	(*map)->player = (*map)->visited_list->position;
	(*map)->visited_list = (*map)->visited_list->next;
	free(temp);
	temp = NULL;
}

void	check_map_path(t_map *map)
{
	int			i;
	t_position	new_pos;

	i = 0;
	move_player(map->player, map->map);
	while (map->map_loop == 0)
	{
		while (map->movements[i])
		{
			map->move_flag = 0;
			new_pos = calculate_coords(map->player, map->movements[i++]);
			if (is_valid_coord(new_pos, map->map, map->visited_list,
					map->double_visited) == 0)
			{
				move_player_to_new_pos(new_pos, &map);
				break ;
			}
		}
		if (map->move_flag == 0)
			step_back(&map);
		i = 0;
	}
}
