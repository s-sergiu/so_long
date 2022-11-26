/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:53 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/26 04:19:29 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_collectible_count(char *map)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (map[++i])
		if (map[i] == 'C')
			count++;
	return (count);
}

void	init_game_data(t_data **data, char *argv)
{
	int	count;

	(*data)->map_string = read_map(argv);
	count = get_collectible_count((*data)->map_string);
	(*data)->collectibles = (mlx_image_t **)malloc
		(sizeof(mlx_image_t *) * count);
	(*data)->collectible_count = (char *)malloc(sizeof(char) * count);
	(*data)->map = ft_split((*data)->map_string, '\n');
	(*data)->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	(*data)->img = mlx_new_image((*data)->mlx, WIDTH, HEIGHT);
	(*data)->collectible_list = NULL;
	(*data)->enemy_list = NULL;
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
	draw_map(data);
}

void	destroy_and_free(t_data **data)
{
	free_split((*data)->map);
	destroy_run_structure(data);
	destroy_idle_structure(data);
	destroy_tile_structure(data);
}

int	is_valid_move(t_data *data, int x, int y)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	player = data->player_box->instances;
	posx = (x + player->x / TILE);
	posy = (y + player->y / TILE);
	if (data->map[posy][posx] != '1')
		return (1);
	return (0);
}

void	delete_collectible(t_data **data)
{
	t_list	*current;
	t_list	*head;
	int		posy;
	int		posx;

	posx = (*data)->player_box->instances[0].x / 32;
	posy = (*data)->player_box->instances[0].y / 32;
	head = (*data)->collectible_list;
	current = head;
	if (head->x == posx && head->y == posy)
	{
		(*data)->collectible_list = (*data)->collectible_list->next;
		mlx_delete_image((*data)->mlx, current->position);
	}
	while (current->next)
	{
		if (current->next->x == posx && current->next->y == posy)
		{
			mlx_delete_image((*data)->mlx, current->next->position);
			current->next = current->next->next;
			break ;
		}
		current = current->next;
	}
}

void	player_is_on_colectible(t_data **data)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	player = (*data)->player_box->instances;
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

int	is_valid_enemy_move(t_data *data, mlx_image_t *enemy, int index)
{
	mlx_instance_t	*player;
	t_position		*direction;
	int posx;
	int posy;

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
	t_list	*current;	
	mlx_image_t *enemy;
	t_position		*direction;
	int		i;
	int		index;

	current = (*data)->enemy_list;
	i = 0;
	while(current)
	{
		enemy = current->position;
		index = (rand() % (3 + 1 - 0) + 0);
		direction = (*data)->enemy_movement[index];
		if(is_valid_enemy_move((*data), enemy, index) == 0)
		{
			enemy->instances[0].x += direction->x * TILE;
			enemy->instances[0].y += direction->y * TILE;
		}
		current = current->next;
	}
}

void	hook(void *param)
{
	t_data			*data;

	data = param;
	idle_animation(data);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data			*data;
	mlx_image_t		*player;
	mlx_image_t		*player_box;
	static int		move;
	mlx_image_t		*exit_img;
	mlx_image_t		*exit_image;
	mlx_texture_t	*tiles;
	mlx_image_t		*enemy;

	data = param;
	player = data->idle->right_idle[0];
	player_box = data->player_box;
	enemy = data->enemy_list->position;
	data->collectible_count = ft_itoa(move + 1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (is_valid_move(data, 0, 1))
		{
			player_box->instances[0].y += 1 * TILE;
			player->instances[0].y += 1 * TILE;
			move++;
			printf("Player moves: %d.\n", move);
			mlx_delete_image(data->mlx, data->tile_floor);
			data->tile_floor = mlx_put_string(data->mlx,
					data->collectible_count, 6, 6);
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (is_valid_move(data, -1, 0))
		{
			player_box->instances[0].x -= 1 * TILE;
			player->instances[0].x -= 1 * TILE;
			move++;
			printf("Player moves: %d.\n", move);
			mlx_delete_image(data->mlx, data->tile_floor);
			data->tile_floor = mlx_put_string(data->mlx,
					data->collectible_count, 6, 6);
		}
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (is_valid_move(data, 0, -1))
		{
			player_box->instances[0].y -= 1 * TILE;
			player->instances[0].y -= 1 * TILE;
			move++;
			printf("Player moves: %d.\n", move);
			mlx_delete_image(data->mlx, data->tile_floor);
			data->tile_floor = mlx_put_string(data->mlx,
					data->collectible_count, 6, 6);
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (is_valid_move(data, 1, 0))
		{
			player_box->instances[0].x += 1 * TILE;
			player->instances[0].x += 1 * TILE;
			move++;
			printf("Player moves: %d.\n", move);
			mlx_delete_image(data->mlx, data->tile_floor);
			data->tile_floor = mlx_put_string(data->mlx,
					data->collectible_count, 6, 6);
		}
	}
	player_is_on_colectible(&data);
	if (ft_lstsize(data->collectible_list) == 0)
	{
		tiles = mlx_load_png("assets/tiles/other/34.png");
		exit_img = mlx_texture_to_image(data->mlx, tiles);
		exit_image = data->exit;
		ft_memcpy(exit_image->pixels, exit_img->pixels, 32 * 32 * 4);
	}
	if (player_is_on_exit(&data) && ft_lstsize(data->collectible_list) == 0)
		exit(1);
	enemy_movement(&data);
}

void	game_loop(char *argv)
{
	t_data	*data;

	init_game_data(&data, argv);
	mlx_loop_hook(data->mlx, &hook, data);
	mlx_key_hook(data->mlx, keyhook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
