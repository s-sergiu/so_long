/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:57:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/16 13:02:57 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_component(char c)
{
	if ((c == 'E' || c == 'P') || c == 'C')
		return (0);
	return (1);
}
int	contains_component(char **map)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		while (map[i][j])
			if (is_component(map[i][j++]) == 0)
				return (1);
		j = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char *map_string;
	t_map	*map;

	map = NULL;
	if (argc != 2)
	{
		write(1, "Usage: ./so_long <name>.ber\n", 28);
		return (1);
	} else
	{
		if (not_valid_map_name(argv[1]))
			return (1);
		map_string = read_map(argv[1]);
		if (is_missing_components(map_string))
		{	
			write(2, "Missing map components.\n", 24);
			return (1);
		}
		map = init_structure(map_string);
		if (not_valid_map(map->map))
		{
			write(2, "Map is leaking or structure is incorrect.\n", 42);
			return (1);
		}
		has_valid_path(map);
		if (contains_component(map->map))
			write(2, "Map has no valid path.\n", 23);
		free(map_string);
	}
	return (0);
}
