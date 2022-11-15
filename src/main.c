/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:57:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/15 07:38:04 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		{	
			printf("Invalid map name\n");
			return (1);
		}
		map_string = read_map(argv[1]);
		if (is_missing_components(map_string))
		{	
			printf("Missing components\n");
			return (1);
		}
		map = init_structure(map_string);
		if (has_valid_path(map))
			printf("yes\n");
		free(map_string);
		if (not_valid_map(map->map))
			return (1);
	}
	return (0);
}
