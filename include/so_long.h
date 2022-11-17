/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:13:15 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/17 15:55:38 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include <sys/errno.h>
# include <string.h>
# define WIDTH ft_strlen((*data)->map[0]) * 32
# define HEIGHT ft_arrlength((*data)->map) * 32 

struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*tile_texture;
	mlx_image_t		*tile_img;
	mlx_texture_t	*player;
	mlx_image_t		*player_img;
	int				player_dead;
	char			*map_string;
	char			**map;
};

struct s_map 
{
	char				**map;
	struct s_position	*player;
	struct s_position	*exit;
	struct s_visited	*visited_list;
	struct s_visited	*double_visited;
	struct s_position	*movements[5];
	char				move_flag;
	int					map_loop;
};

struct s_position
{
	int x;
	int y;
};

typedef struct s_position t_position;
typedef struct s_map t_map;
typedef struct s_data t_data;

void		print_map(char **map);
void		has_valid_path(t_map *map);
char		*read_map(char *map);
size_t		ft_arrlength(char **string);
int			not_valid_map_name(char *filename);
int			not_valid_map(char **map);
int			error_handling(char errnum);
int			not_valid_map_structure(char **map, size_t array_length);
int			is_missing_components(char *map);
t_map		*init_structure(char *map_string);
t_position	*get_player_position(char **map);
int			print_usage(void);
int			components_error(char *map_string);
int			structure_error(t_map *map);
void		destroy_structure(t_map *map);
int			empty_map(char *map_string);
t_position	calculate_coords(t_position *player, t_position *movement);
void		free_split(char **split);
char		map_has_no_errors(char *argv);
int			no_valid_path(t_map *map);
int			is_valid_coord(t_position position, 
			char **map, t_list *head, t_list *head2);
void		init_game(char *argv);
void		idle_animation(void *param);
void		run_animation(void *param);
void		left_run_animation(void *param);
void		right_run_animation(void *param);
void		attack_left(void *param);
void		attack_right(void *param);
void		death_animation(void *param);
int			init_game_data(t_data **data, char *argv);
void		init_game(char *argv);
void		put_tile(t_data **data);
void		draw_map(t_data **data);
void		add_player(t_data **data);

#endif
