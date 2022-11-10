/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:57:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/11 00:21:41 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_handling(char errnum)
{
	if (errnum == 1)
		write(2, "Invalid map name..\n", 19);
	else
		printf("%s\n", strerror(errnum));
}

int	is_valid_map_name(char *filename)
{
	int	len;
	int	file;

	len = ft_strlen(filename);
	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		error_handling(errno);
		return (0);
	}
	close(file);
	if (!ft_strncmp(filename + (len - 4), ".ber\0", 5))
		return (1);
	error_handling(1);
	return (0);
}

char	*read_map(char *map)
{
	int		file;
	int		read_bytes;
	int		total_bytes;
	char	*buffer;
	char	*map_b;

	file = open(map, O_RDONLY);
	buffer = malloc(4000);
	read_bytes = read(file, buffer, 4000);
	total_bytes = 0;
	total_bytes += read_bytes;
	while (read_bytes != 0)
	{
		read_bytes = read(file, buffer, 4000);
		total_bytes += read_bytes;
	}
	close(file);
	free(buffer);
	map_b = ft_calloc(sizeof(char), total_bytes);
	file = open(map, O_RDONLY);
	read(file, map_b, total_bytes);
	map_b[total_bytes] = 0;
	return(map_b);
}

void	attack_left(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*new_player;
	static int		frames;

	data = param;
		if (frames == 0)
		{
			new_image = mlx_load_png("assets/Attack1_1.png");
			new_player = mlx_texture_to_image(data->mlx, new_image);
			memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
		}
		if (frames == 7)
		{
			new_image = mlx_load_png("assets/Attack1_2.png");
			new_player = mlx_texture_to_image(data->mlx, new_image);
			memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
		}
		if (frames == 14)
		{
			new_image = mlx_load_png("assets/Attack1_3.png");
			new_player = mlx_texture_to_image(data->mlx, new_image);
			memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
		}
		if (frames == 40)
		{
			new_image = mlx_load_png("assets/Attack1_4.png");
			new_player = mlx_texture_to_image(data->mlx, new_image);
			memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
			frames = -1;
		}
		frames++;
}

void	attack_right(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*new_player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/RAttack1_1.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/RAttack1_2.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/RAttack1_3.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/RAttack1_4.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
		frames = -1;
	}
	frames++;
}

void	death_animation(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*new_player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/Death_1.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/Death_2.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/Death_3.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/Death_4.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 28)
	{
		new_image = mlx_load_png("assets/Death_5.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 35)
	{
		new_image = mlx_load_png("assets/Death_6.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
		data->player_dead = 1;
		frames = -1;
	}
	frames++;
}

void	left_run_animation(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*new_player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/Run_back_1.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/Run_back_2.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/Run_back_3.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/Run_back_4.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 28)
	{
		new_image = mlx_load_png("assets/Run_back_5.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 35)
	{
		new_image = mlx_load_png("assets/Run_back_6.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 42)
	{
		new_image = mlx_load_png("assets/Run_back_7.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	if (frames == 49)
	{
		new_image = mlx_load_png("assets/Run_back_8.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
		frames = -1;
	}
	frames++;
}

void	run_animation(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*new_player;
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/Run_1.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	else if (frames == 7)
	{
		new_image = mlx_load_png("assets/Run_2.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	else if (frames == 14)
	{
		new_image = mlx_load_png("assets/Run_3.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	else if (frames == 21)
	{
		new_image = mlx_load_png("assets/Run_4.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	else if (frames == 28)
	{
		new_image = mlx_load_png("assets/Run_5.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	else if (frames == 35)
	{
		new_image = mlx_load_png("assets/Run_6.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	else if (frames == 42)
	{
		new_image = mlx_load_png("assets/Run_7.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
	}
	else if (frames == 49)
	{
		new_image = mlx_load_png("assets/Run_8.png");
		new_player = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
		frames = -1;
	}
	frames++;
}

void	idle_animation(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*new_player[8];
	static int		frames;

	data = param;
	if (frames == 0)
	{
		new_image = mlx_load_png("assets/Idle_1.png");
		new_player[0] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player[0]->pixels, 150 * 150 * 4);
	}
	if (frames == 7)
	{
		new_image = mlx_load_png("assets/Idle_2.png");
		new_player[1] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player[1]->pixels, 150 * 150 * 4);
	}
	if (frames == 14)
	{
		new_image = mlx_load_png("assets/Idle_3.png");
		new_player[2] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player[2]->pixels, 150 * 150 * 4);
	}
	if (frames == 21)
	{
		new_image = mlx_load_png("assets/Idle_4.png");
		new_player[3] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player[3]->pixels, 150 * 150 * 4);
	}
	if (frames == 28)
	{
		new_image = mlx_load_png("assets/Idle_5.png");
		new_player[4] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player[4]->pixels, 150 * 150 * 4);
	}
	if (frames == 35)
	{
		new_image = mlx_load_png("assets/Idle_6.png");
		new_player[5] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player[5]->pixels, 150 * 150 * 4);
	}
	if (frames == 42)
	{
		new_image = mlx_load_png("assets/Idle_7.png");
		new_player[6] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player[6]->pixels, 150 * 150 * 4);
	}
	if (frames == 49)
	{
		new_image = mlx_load_png("assets/Idle_8.png");
		new_player[7] = mlx_texture_to_image(data->mlx, new_image);
		memcpy(data->player_img->pixels, new_player[7]->pixels, 150 * 150 * 4);
		frames = -1;
	}
	frames++;
}

void	hook(void *param)
{
	t_data			*data;
	mlx_texture_t	*new_image;
	mlx_image_t		*new_player;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->player_img->instances[0].y -= 4;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->player_img->instances[0].y += 4;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) || mlx_is_key_down(data->mlx, 
		MLX_KEY_D))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		{
			run_animation(data);
			data->player_img->instances[0].x += 4;
		}
		else		
		{
		left_run_animation(data);
		data->player_img->instances[0].x -= 4;
		}
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		attack_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_X))
		printf("%s\n", data->map[0]);
	else 
	{
		idle_animation(data);
		printf("player dead %d\n", data->player_dead);
		while (data->player_dead == 1)
		{
			new_image = mlx_load_png("assets/Death_6.png");
			new_player = mlx_texture_to_image(data->mlx, new_image);
			memcpy(data->player_img->pixels, new_player->pixels, 150 * 150 * 4);
			break ;
		}
			
	}
}

void	draw_map(char **map, t_data *data)
{		
	int	i;
	int delim;
	mlx_image_t *new_player;
	mlx_texture_t *new_image;

	i = 0;
	delim = 74;
	printf("%s\n", map[1]);
	new_image = mlx_load_png("assets/terrain/Dungeon_Tileset1.png");
	new_player = mlx_texture_to_image(data->mlx, new_image);
	while (i < 8)
	{
		mlx_image_to_window(data->mlx, data->img, delim, 20);
		delim += 74;
		i++;
	}
		mlx_image_to_window(data->mlx, data->img, 20, 88);
}

int32_t	main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	data = (t_data*)malloc(sizeof(t_data));
	if (argc != 2)
	{
		write(1, "Usage: ./so_long <name>.ber\n", 28);
		return (0);
	}
	if (is_valid_map_name(argv[1]))
		data->map = ft_split(read_map(argv[1]), '\n');
	else
		return (1);
	mlx_set_setting(MLX_MAXIMIZED, false);
	data->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!data->mlx)
		return(1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	/* Do stuff */
	data->player = mlx_load_png("assets/terrain/Dungeon_Tileset2.png");
	data-> img = mlx_texture_to_image(data->mlx, data->player);
	mlx_delete_texture(data->player);
	draw_map(data->map, data);

	data->player = mlx_load_png("assets/Idle_1.png");
	data->player_img = mlx_texture_to_image(data->mlx, data->player);
	mlx_delete_texture(data->player);
	mlx_image_to_window(data->mlx, data->img, 20, 20);
	mlx_image_to_window(data->mlx, data->player_img, 0, 0);
	mlx_loop_hook(data->mlx, &hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
