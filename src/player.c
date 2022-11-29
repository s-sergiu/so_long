/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:53:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/29 06:22:25 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_is_on_enemy(t_data **data)
{
	mlx_instance_t	*player;
	mlx_image_t		*enemy;
	t_list			*current;
	int				posx;
	int				posy;

	current = (*data)->enemy_list;
	player = (*data)->player_box->instances;
	while (current)
	{
		enemy = current->position;
		if ((enemy->instances[0].x / 32 + 1)
			== (player[0].x / 32) && (enemy->instances[0].y / 32 + 1)
			== (player[0].y / 32))
			mlx_close_window((*data)->mlx);
		current = current->next;
	}
	posx = player[0].x / 32;
	posy = player[0].y / 32;
	if ((*data)->map[posy][posx] == 'C')
	{
		(*data)->map[posy][posx] = '0';
		delete_collectible(data);
	}
}

int	player_is_on_exit(t_data **data)
{
	mlx_instance_t	*player;
	mlx_instance_t	*exit;

	player = &(*data)->player_box->instances[0];
	exit = &(*data)->exit->instances[0];
	if (player->x == exit->x && player->y == exit->y)
		return (1);
	return (0);
}

void	idle_animation(void *param)
{
	t_data			*data;
	mlx_image_t		**player;
	static int		frames;
	static int		i;

	data = param;
	player = data->idle->right_idle;
	if (frames == 0 || frames % 7 == 0)
	{
		ft_memcpy(player[0]->pixels, player[i]->pixels, 64 * 64 * 4);
		if (i == 7)
		{
			frames = -1;
			i = -1;
		}
		i++;
	}
	frames++;
}

int	is_valid_move(t_data *data, t_position *position)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	posx = position->x;
	posy = position->y;
	player = data->player_box->instances;
	posx = posx + player->x / TILE;
	posy = posy + player->y / TILE;
	if (data->map[posy][posx] != '1')
		return (1);
	return (0);
}

void	init_movements(t_data **data)
{
	(*data)->enemy_movement[0] = (t_position *)malloc(sizeof(t_position));
	(*data)->enemy_movement[1] = (t_position *)malloc(sizeof(t_position));
	(*data)->enemy_movement[2] = (t_position *)malloc(sizeof(t_position));
	(*data)->enemy_movement[3] = (t_position *)malloc(sizeof(t_position));
	(*data)->enemy_movement[4] = NULL;
	(*data)->enemy_movement[0]->x = 0;
	(*data)->enemy_movement[0]->y = -1;
	(*data)->enemy_movement[1]->x = 0;
	(*data)->enemy_movement[1]->y = 1;
	(*data)->enemy_movement[2]->x = 1;
	(*data)->enemy_movement[2]->y = 0;
	(*data)->enemy_movement[3]->x = -1;
	(*data)->enemy_movement[3]->y = 0;
}
