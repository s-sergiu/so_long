/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:56:00 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/29 08:56:10 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_collectible_count(char *map)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (map[++i])
		if (map[i] == 'C')
			count++;
	return (count);
}

void	free_and_delete_image(t_data **data, mlx_image_t *image, t_list *head)
{
	t_list	*temp;

	temp = head->next;
	mlx_delete_image((*data)->mlx, image);
	free(temp);
}

void	delete_collectible(t_data **data)
{
	t_list	*head;
	int		posy;
	int		posx;

	posx = (*data)->player_box->instances[0].x / 32;
	posy = (*data)->player_box->instances[0].y / 32;
	head = (*data)->collectible_list;
	if (head->x == posx && head->y == posy)
	{
		(*data)->collectible_list = (*data)->collectible_list->next;
		mlx_delete_image((*data)->mlx, head->position);
		free(head);
		return ;
	}
	while (head->next)
	{
		if (head->next->x == posx && head->next->y == posy)
		{
			free_and_delete_image(data, head->next->position, head);
			head->next = head->next->next;
			return ;
		}
		head = head->next;
	}
}

void	player_is_on_colectible(t_data **data)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	player = (*data)->player_box->instances;
	posx = player[0].x / 32;
	posy = player[0].y / 32;
	if ((*data)->map[posy][posx] == 'C')
	{
		(*data)->map[posy][posx] = '0';
		delete_collectible(data);
	}
}

void	check_if_collected_all(t_data *data)
{
	mlx_image_t		*exit_img;
	mlx_image_t		*exit_image;
	mlx_texture_t	*tiles;

	if (!data->collectible_list)
	{
		tiles = mlx_load_png("assets/tiles/other/34.png");
		exit_img = mlx_texture_to_image(data->mlx, tiles);
		exit_image = data->exit;
		ft_memcpy(exit_image->pixels, exit_img->pixels, 32 * 32 * 4);
		mlx_delete_texture(tiles);
	}
}
