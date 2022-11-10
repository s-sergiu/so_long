/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:13:15 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/10 23:27:18 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <sys/errno.h>
# include <string.h>
# include <math.h>
# define WIDTH 1920
# define HEIGHT 1080


typedef struct data 
{
	mlx_t *mlx;
	mlx_image_t *img;
	mlx_texture_t *player;
	mlx_image_t *player_img;
	int			player_dead;
	char		**map;
}		t_data;

typedef struct player
{
	int	direction;
	int	is_alive;
	mlx_image_t	*idle_sprite[8];
}	t_player;

char	*read_map(char *map);
int		is_valid_map_name(char *filename);

#endif
