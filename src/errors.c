/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 04:41:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/18 15:42:42 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	print_usage(void)
{
	write(1, "Usage: ./so_long <name>.ber\n", 28);
	return (TRUE);
}

int	components_error(char *map_string)
{
	write(2, "Missing map components.\n", 24);
	free(map_string);
	return (TRUE);
}

int	structure_error(t_map *map)
{
	write(2, "Map is leaking or structure is incorrect.\n", 42);
	free(map->player);
	destroy_structure(map);
	return (TRUE);
}

int	no_valid_path(t_map *map)
{
	write(2, "Map has no valid path.\n", 23);
	destroy_structure(map);
	return (TRUE);
}

int	empty_map(char *map_string)
{
	write(2, "Empty map..\n", 12);
	free(map_string);
	return (TRUE);
}
