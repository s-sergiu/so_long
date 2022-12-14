/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:24 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/29 14:22:48 by ssergiu          ###   ########.fr       */
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
# define SPRITE 64
# define TILE 32

typedef struct s_position		t_position;
typedef struct s_map			t_map;
typedef struct s_texture		t_texture;
typedef struct s_idle_texture	t_idle;
typedef struct s_data			t_data;

enum e_bool
{
	FALSE,
	TRUE
};

struct	s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*enemy[3];
	mlx_texture_t	*exit[3];
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*enemy_img[3];
	mlx_image_t		*exit_img[3];

};

struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	char			*collectible_count;
	mlx_texture_t	*player;
	mlx_image_t		*score;
	t_idle			*idle;
	t_texture		*tiles;
	t_list			*collectible_list;
	t_list			*enemy_list;
	mlx_texture_t	*game_icon;
	mlx_image_t		*player_img;
	mlx_image_t		*player_box;
	t_position		*enemy_movement[5];
	char			*map_string;
	char			**map;
	int				width;
	int				height;
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
void		delete_tile_textures(t_data **data);
void		delete_idle_textures(t_data **data);
t_position	*get_component(char **map, char type);
void		put_enemy(t_data **data, int width, int height);
void		put_collectable(t_data **data, int width, int height);
void		delete_collectible(t_data **data);
void		put_floor(t_data **data, char c, int width, int height);
void		put_door(t_data **data);
void		add_player(t_data **data);
void		enemy_movement(t_data **data);
int			is_valid_move(t_data *data, t_position *position);
void		check_if_collected_all(t_data *data);
void		init_movements(t_data **data);
int			get_collectible_count(char *map);
void		idle_animation(void *param);
void		player_is_on_colectible(t_data **data);
void		player_is_on_enemy(t_data **data);
int			player_is_on_exit(t_data **data);
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
void		ft_lstclear_no_free(t_list **lst);
void		destroy_movements(t_data **data);
void		destroy_and_free(t_data **data);

#endif
