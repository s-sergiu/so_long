/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:10:41 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/18 14:36:11 by ssergiu          ###   ########.fr       */
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

int	is_missing_components(char *map)
{
	int	player;
	int	exit;
	int	collectible;

	player = get_count(map, 'P');
	exit = get_count(map, 'E');
	collectible = get_count(map, 'C');
	if (player == 1 && exit == 1 && collectible > 0)
		return (0);
	return (1);
}
