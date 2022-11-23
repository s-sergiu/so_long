/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:57:53 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/23 20:21:46 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game_data(t_data **data, char *argv)
{
	(*data)->map_string = read_map(argv);
	(*data)->map = ft_split((*data)->map_string, '\n');
	free((*data)->map_string);
	(*data)->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	(*data)->img = mlx_new_image((*data)->mlx, WIDTH, HEIGHT);
	init_tile_textures(data);
}

void	game_loop(char *argv)
{
	t_data *data;

	init_game_data(&data, argv);
//	mlx_loop_hook(data->mlx, &hook, data);
	draw_map(&data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
