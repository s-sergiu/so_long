/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:13:15 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/13 19:35:08 by ssergiu          ###   ########.fr       */
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
int		valid_map_name(char *filename);
int		not_valid_map(char **map);
void	error_handling(char errnum);
int		valid_map_structure(char **map);
size_t	ft_arrlength(char **string);
int		has_map_components(char *map);

#endif
