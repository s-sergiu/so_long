/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:52:40 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/29 14:20:34 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_valid_enemy_move(t_data *data, mlx_image_t *enemy, int index)
{
	mlx_instance_t	*player;
	t_position		*direction;
	int				posx;
	int				posy;

	direction = (*data).enemy_movement[index];
	player = enemy->instances;
	posy = player[0].y / TILE + direction->y + 1;
	posx = player[0].x / TILE + direction->x + 1;
	if (data->map[posy][posx] != '1')
		return (0);
	return (1);
}

void	enemy_movement(t_data **data)
{
	t_list			*current;	
	mlx_image_t		*enemy;
	t_position		*direction;
	int				index;

	current = (*data)->enemy_list;
	while (current)
	{
		enemy = current->position;
		index = (rand() % (3 + 1 - 0) + 0);
		direction = (*data)->enemy_movement[index];
		if (is_valid_enemy_move((*data), enemy, index) == 0)
		{
			enemy->instances[0].x += direction->x * TILE;
			enemy->instances[0].y += direction->y * TILE;
		}
		current = current->next;
	}
}
