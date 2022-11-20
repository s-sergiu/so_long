/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:44:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/19 21:11:12 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
void init_tile_textures(t_texture **texture)
{
	(*texture) = (t_texture *)malloc(sizeof(t_texture));
	(*texture)->floor[0] = mlx_load_png("assets/tiles/floor/1.png");
	(*texture)->floor[1] = mlx_load_png("assets/tiles/floor/2.png");
	(*texture)->floor[2] = mlx_load_png("assets/tiles/floor/3.png");
	(*texture)->floor[3] = mlx_load_png("assets/tiles/floor/4.png");
	(*texture)->floor[4] = mlx_load_png("assets/tiles/floor/5.png");
	(*texture)->floor[5] = mlx_load_png("assets/tiles/other/33.png");
	(*texture)->floor[6] = mlx_load_png("assets/tiles/other/35.png");
	(*texture)->floor[7] = mlx_load_png("assets/tiles/wall/0.png");
	(*texture)->floor[8] = NULL;
}
