/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:57:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/14 22:09:39 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char *map_string;
	char **map_matrix;

	if (argc != 2)
	{
		write(1, "Usage: ./so_long <name>.ber\n", 28);
		return (1);
	}
	else
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
		printf("%s", map_string);
		map_matrix = ft_split(map_string, '\n');
		int i = 0;
		while (map_matrix[i])
			printf("%s.\n", map_matrix[i++]);
		free(map_string);
		if (not_valid_map(map_matrix))
			return (1);
	}
	return (0);
}
