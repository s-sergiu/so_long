/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:24 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/25 21:50:27 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include "libft.h"
# include <sys/errno.h>
# include <stdio.h>
# include <string.h>
# define WIDTH TILE * ft_strlen(*(*data)->map)
# define HEIGHT TILE * ft_arrlength((*data)->map)
# define P_SPRITE 64
# define TILE 32

typedef struct s_position		t_position;
typedef struct s_map			t_map;
typedef struct s_texture		t_texture;
typedef struct s_idle_texture	t_idle;
typedef struct s_run_texture	t_run;
typedef struct s_data			t_data;

enum e_bool
{
	FALSE,
	TRUE
};

struct	s_texture
{
	mlx_texture_t	*floor[9];
	mlx_texture_t	*wall[6];
	mlx_image_t		*floor_img[9];
	mlx_image_t		*wall_img[6];
};

struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*tile_texture;
	mlx_image_t		*tile_floor;
	mlx_image_t		*tile_wall;
	mlx_image_t		*exit;
	mlx_image_t		**collectibles;
	char			*collectible_count;;
	mlx_texture_t	*player;
	t_idle			*idle;
	t_run			*run;
	t_texture		*tiles;
	t_list			*collectible_list;
	t_list			*enemy_list;
	mlx_texture_t	*game_icon;
	mlx_image_t		*player_img;
	mlx_image_t		*player_box;
	char			*map_string;
	char			**map;
};

struct	s_run_texture
{
	mlx_texture_t	*left[9];	
	mlx_texture_t	*right[9];	
	mlx_image_t		*right_run[9];	
	mlx_image_t		*left_run[9];	
};

struct	s_idle_texture
{
	mlx_texture_t	*left[9];	
	mlx_texture_t	*right[9];	
	mlx_image_t		*right_idle[9];	
	mlx_image_t		*left_idle[9];	
	mlx_image_t		*idle;
};

struct s_map
{
	char				**map;
	struct s_position	*player;
	struct s_position	*exit;
	struct s_visited	*visited_list;
	struct s_visited	*double_visited;
	struct s_position	*movements[5];
	char				player_moved;
	int					map_loop;
};

struct s_position
{
	int	x;
	int	y;
};

int			same_coords(t_position *player, t_position *exit);
void		check_map_path(t_map *map);
void		draw_map(t_data **data);
void		free_split(char **split);
void		destroy_structure(t_map *map);
void		game_loop(char *argv);
void		init_tile_textures(t_data **data);
void		init_run_texture(t_data **data);
void		init_idle_texture(t_data **data);
void		destroy_run_structure(t_data **data);
void		destroy_idle_structure(t_data **data);
void		destroy_tile_structure(t_data **data);
char		*read_map(char *map);
int			map_has_errors(char *argv);
int			not_valid_map_name(char *filename);
int			not_valid_map(char **map);
int			not_valid_map_structure(char **map, size_t array_length);
int			not_wall(char c);
int			is_missing_components(char *map);
int			print_usage(void);
int			components_error(char *map_string);
int			structure_error(t_map *map);
int			empty_map(char *map_string);
int			no_valid_path(t_map *map);
int			is_valid_coord(t_position position, t_map **map);
size_t		ft_arrlength(char **string);
t_position	*get_player_position(char **map);
t_position	calculate_coords(t_position *player, t_position *movement);
t_map		*init_structure(char *map_string);
void		print_list(t_data **data);

#endif
