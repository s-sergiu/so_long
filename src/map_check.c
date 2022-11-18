/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:32:51 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/18 19:13:11 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_component(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((str[i] == 'E' || str[i] == 'P') || str[i] == 'C')
			return (TRUE);
	return (FALSE);
}

int	contains_component(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		if (is_component(map[i]))
			return (TRUE);
	return (FALSE);
}

int	has_no_valid_path(t_map *map)
{
	check_map_path(map);
	ft_lstclear(&map->double_visited, free);
	if (contains_component(map->map))
		return (TRUE);
	return (FALSE);
}

int	empty(char *map_string)
{
	if (map_string[0] == 0)
		return (TRUE);
	return (FALSE);
}

int	map_has_errors(char *argv)
{
	char	*map_string;
	t_map	*map;

	if (not_valid_map_name(argv))
		return (TRUE);
	map_string = read_map(argv);
	if (empty(map_string))
		return (empty_map(map_string));
	if (is_missing_components(map_string))
		return (components_error(map_string));
	map = init_structure(map_string);
	free(map_string);
	if (not_valid_map(map->map))
		return (structure_error(map));
	if (has_no_valid_path(map))
		return (no_valid_path(map));
	destroy_structure(map);
	return (FALSE);
}
