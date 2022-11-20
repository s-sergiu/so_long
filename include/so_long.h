/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:24 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/20 20:50:18 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __APPLE__
#  include "../lib/MLX42/include/MLX42/MLX42.h"
# else
#  include "../lib/MLX42_LINUX/include/MLX42/MLX42.h"
# endif
# include <fcntl.h>
# include "libft.h"
# include <sys/errno.h>
# include <string.h>
# define WIDTH TILE * ft_strlen(*(*data)->map)
# define HEIGHT TILE * ft_arrlength((*data)->map)
# define P_SPRITE 64
# define TILE 32

enum e_bool
{
	FALSE,
	TRUE
};

struct	s_texture
{
	mlx_texture_t	*floor[10];
	mlx_texture_t	*player_runleft[10];
	mlx_texture_t	*player_runright[10];
	mlx_texture_t	*walls[10];
};

struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*tile_texture;
	mlx_image_t		*tile_floor;
	mlx_image_t		*tile_wall;
	mlx_image_t		*exit;
	mlx_image_t		*collectible;
	mlx_texture_t	*player;
	struct s_idle_texture			*idle;
	mlx_texture_t	*game_icon;
	mlx_image_t		*player_img;
	mlx_image_t		*player_box;
	int				player_dead;
	char			*map_string;
	char			**map;
};

struct	s_idle_texture
{
	mlx_texture_t	*left[9];	
	mlx_texture_t	*right[9];	
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

typedef struct s_position		t_position;
typedef struct s_map			t_map;
typedef struct s_idle_texture	t_idle;
typedef struct s_data			t_data;
typedef struct s_texture		t_texture;

void		check_map_path(t_map *map);
void		draw_map(t_data **data);
void		free_split(char **split);
void		destroy_structure(t_map *map);
void		game_loop(char *argv);
void		init_tile_textures(t_texture **tile);
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

#endif
