/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:16:47 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/17 04:32:40 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	not_wall(char c)
{
	if (c != '1')
		return (1);
	return (0);
}

size_t	ft_arrlength(char **string)
{
	size_t	i;	
	
	i = 0;
	while (string[i])
		i++;
	return (i);
}

int upper_wall_closed(char *upper_wall)
{
	int	i;

	i = 0;
	while (upper_wall[i] != 0)
		if (not_wall(upper_wall[i++]))
			return(1);
	return (0);
}

int sidewalls_closed(char **map, size_t array_length)
{
	size_t i;
	size_t string_length;

	i = 0;
	string_length = ft_strlen(*map);
	while (i < array_length)
	{
		if (not_wall(map[i][0]) || not_wall(map[i][string_length - 1]))
			return(1);
		i++;
	}
	return (0);
}

int lower_wall_closed(char *lower_wall)
{
	int	i;

	i = 0;
	while (lower_wall[i] != 0)
		if (lower_wall[i++] != '1')
			return(1);
	return (0);
}

int	not_valid_map(char **map)
{
	size_t	array_length;

	array_length = ft_arrlength(map);
	if (not_valid_map_structure(map, array_length))
		return (1);
	if (upper_wall_closed(*map))
		return (1);
	if (sidewalls_closed(map, array_length))
		return (1);
	if (lower_wall_closed(map[array_length - 1]))
		return (1);
	return (0);
}

