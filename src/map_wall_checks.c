/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:16:47 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/14 06:07:57 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_arrlength(char **string)
{
	size_t	i;	
	
	i = 0;
	while (string[i])
	{
		printf("index %zu: %s\n", i, string[i]);
		i++;
	}
	return (i);
}

int upper_wall_closed(char *upper_wall)
{
	int	i;

	i = 0;
	while (upper_wall[i] != 0)
		if (upper_wall[i++] != '1')
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
		if (map[i][0] != '1' || map[i][string_length - 1] != '1')
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
	{
		printf("Not valid map structure\n");
		return (1);
	}
	if (upper_wall_closed(*map))
	{
		printf("Upper wall leak\n");
		return (1);
	}
	if (sidewalls_closed(map, array_length))
	{
		printf("Side wall leak\n");
		return (1);
	}
		printf("yes\n");
	if (lower_wall_closed(map[array_length - 1]))
	{
		printf("Lower wall leak %zu\n", array_length);
		return (1);
	}
	return (0);
}

