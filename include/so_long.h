/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:13:15 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/15 11:54:04 by ssergiu          ###   ########.fr       */
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


struct s_map 
{
	char				**map;
	struct s_position	*player;
	struct s_position	*exit;
	struct s_visited	*visited_list;
	struct s_visited	*double_visited;
	struct s_position	*movements[4];
	char				move_flag;
};

struct s_position
{
	int x;
	int y;
};

typedef struct s_position t_position;
typedef struct s_map t_map;

char		*read_map(char *map);
int			not_valid_map_name(char *filename);
int			not_valid_map(char **map);
void		error_handling(char errnum);
int			not_valid_map_structure(char **map, size_t array_length);
size_t		ft_arrlength(char **string);
int			is_missing_components(char *map);
t_map		*init_structure(char *map_string);
t_position	*get_player_position(char **map);
int			has_valid_path(t_map *map);

#endif
