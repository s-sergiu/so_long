/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:10:41 by ssergiu           #+#    #+#             */
/*   Updated: 2022/12/06 14:06:08 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_count(char *map, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
		if (map[i] == c)
			count++;
	return (count);
}

int	is_invalid_component(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E' || c == '\n')
		return (TRUE);
	return (FALSE);
}

int	is_missing_components(char *map)
{
	int	player;
	int	exit;
	int	collectible;
	int	i;

	player = get_count(map, 'P');
	exit = get_count(map, 'E');
	collectible = get_count(map, 'C');
	i = -1;
	while (map[++i])
		if (is_invalid_component(map[i]) == FALSE)
			return (TRUE);
	if (player == 1 && exit == 1 && collectible > 0)
		return (FALSE);
	return (TRUE);
}

int	not_valid_map_structure(char **map, size_t array_length)
{
	size_t	guide;
	size_t	i;

	if (!*map)
		return (1);
	guide = ft_strlen(*map);
	i = 1;
	while (i < array_length)
		if (ft_strlen(map[i++]) != guide)
			return (TRUE);
	return (FALSE);
}
