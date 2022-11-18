/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:16:47 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/18 15:56:42 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	not_wall(char c)
{
	if (c != '1')
		return (TRUE);
	return (FALSE);
}

int	upper_wall_not_closed(char *upper_wall)
{
	int	i;

	i = 0;
	while (upper_wall[i] != 0)
		if (not_wall(upper_wall[i++]))
			return (TRUE);
	return (FALSE);
}

int	lower_wall_not_closed(char *lower_wall)
{
	int	i;

	i = 0;
	while (lower_wall[i] != 0)
		if (lower_wall[i++] != '1')
			return (TRUE);
	return (FALSE);
}

int	sidewalls_not_closed(char **map, size_t array_length)
{
	size_t	i;
	size_t	string_length;

	i = 0;
	string_length = ft_strlen(*map);
	while (i < array_length)
	{
		if (not_wall(map[i][0]) || not_wall(map[i][string_length - 1]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	not_valid_map(char **map)
{
	size_t	array_length;

	array_length = ft_arrlength(map);
	if (not_valid_map_structure(map, array_length))
		return (TRUE);
	if (upper_wall_not_closed(*map))
		return (TRUE);
	if (sidewalls_not_closed(map, array_length))
		return (TRUE);
	if (lower_wall_not_closed(map[array_length - 1]))
		return (TRUE);
	return (FALSE);
}
