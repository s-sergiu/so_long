/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:53 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/29 14:21:20 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_game_data(t_data **data, char *argv)
{
	int	width;
	int	height;

	(*data)->map_string = read_map(argv);
	(*data)->map = ft_split((*data)->map_string, '\n');
	width = TILE * ft_strlen(*(*data)->map);
	height = TILE * ft_arrlength((*data)->map);
	(*data)->mlx = mlx_init(width, height, "so_long", true);
	(*data)->img = mlx_new_image((*data)->mlx, width, height);
	(*data)->collectible_list = NULL;
	(*data)->enemy_list = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	init_movements(data);
}

void	hook(void *param)
{
	t_data			*data;

	data = param;
	player_is_on_colectible(&data);
	check_if_collected_all(data);
	player_is_on_enemy(&data);
}

void	function_move(t_data *data, t_position *position)
{
	mlx_image_t		*player;
	mlx_image_t		*player_box;
	static int		move;

	player = data->idle->right_idle[0];
	player_box = data->player_box;
	data->collectible_count = ft_itoa(move + 1);
	if (is_valid_move(data, position))
	{	
		player_box->instances[0].y += position->y * TILE;
		player_box->instances[0].x += position->x * TILE;
		player->instances[0].y += position->y * TILE;
		player->instances[0].x += position->x * TILE;
		move++;
		mlx_delete_image(data->mlx, data->score);
		data->score = mlx_put_string(data->mlx,
				data->collectible_count, 6, 6);
		free(data->collectible_count);
		enemy_movement(&data);
	}
	else
		free(data->collectible_count);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data			*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		function_move(data, data->enemy_movement[1]);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		function_move(data, data->enemy_movement[3]);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		function_move(data, data->enemy_movement[0]);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		function_move(data, data->enemy_movement[2]);
	if (player_is_on_exit(&data) && !data->collectible_list)
	{
		ft_putstr_fd("Game completed!", 1);
		write(1, "\n", 1);
		mlx_close_window(data->mlx);
	}
}

void	game_loop(char *argv)
{
	t_data	*data;

	init_game_data(&data, argv);
	draw_map(&data);
	mlx_loop_hook(data->mlx, &hook, data);
	mlx_key_hook(data->mlx, keyhook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	if (data->collectible_list)
		ft_lstclear_no_free(&data->collectible_list);
	ft_lstclear_no_free(&data->enemy_list);
	destroy_and_free(&data);
}
