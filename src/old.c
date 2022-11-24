/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:53 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/24 16:08:57 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_collectible_count(char *map)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while(map[++i])
		if(map[i] == 'C')
			count++;
	return (count);		
}

void	init_game_data(t_data **data, char *argv)
{
	(*data)->map_string = read_map(argv);
	(*data)->coll_count = get_collectible_count((*data)->map_string);
	(*data)->map = ft_split((*data)->map_string, '\n');
	(*data)->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	(*data)->img = mlx_new_image((*data)->mlx, WIDTH, HEIGHT);
	free((*data)->map_string);
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
	int posx;
	int posy;

	player = data->player_box->instances;
	posx = (x + player->x / TILE);
	posy = (y + player->y / TILE);
	if (data->map[posy][posx] != '1')
		return (1);
	return (0);
}

//int	same_images(mlx_image_t *player, mlx_image_t *exit)
//{
//	if (player->instances[0].x == exit->instances[0].x && 
//		player->instances[0].y == exit->instances[0].y)
//		return (TRUE);
//	return (FALSE);
//}
//
//void	check_for_collectibles(t_data **data)
//{
//	
//	if(same_images((*data)->player_box, (*data)->collectibles[i]))
//	{
//		mlx_delete_image((*data)->mlx, (*data)->collectibles[number]);	
//		mark_position_as_zero;
//	}
//}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	mlx_image_t	*player;
	mlx_image_t	*player_box;

	data = param;
	player = data->idle->right_idle[0];
	player_box = data->player_box;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (is_valid_move(data, 0, 1))
		{
			player_box->instances[0].y += 1 * TILE;
			player->instances[0].y += 1 * TILE;
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (is_valid_move(data, -1, 0))
		{
			player_box->instances[0].x -= 1 * TILE;
			player->instances[0].x -= 1 * TILE;
		}
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (is_valid_move(data, 0, -1))
		{
			player_box->instances[0].y -= 1 * TILE;
			player->instances[0].y -= 1 * TILE;
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (is_valid_move(data, 1, 0))
		{
			player_box->instances[0].x += 1 * TILE;
			player->instances[0].x += 1 * TILE;
		}
	}
//	check_for_collectibles(&data);
}

void	game_loop(char *argv)
{
	t_data *data;
	
	init_game_data(&data, argv);
	data->collectibles = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * data->coll_count);
//	mlx_loop_hook(data->mlx, &hook, data);
	mlx_key_hook(data->mlx, keyhook, data);
	draw_map(&data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
