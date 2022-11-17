/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:10:41 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/17 09:05:43 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_missing_components(char *map)
{
	int	i;
	int	player_flag;
	int	exit_flag;
	int	collectible_flag;

	i = -1;
	player_flag = 0;
	exit_flag = 0;
	collectible_flag = 0;
	while (map[++i] != 0)
	{
		if ((map[i] != '1' && map[i] != '0') && (map[i] != 'C' && map[i] != 'E')
			&& (map[i] != 'P' && map[i] != '\n'))
			return (1);
		if (map[i] == 'P')
			player_flag++;
		if (map[i] == 'E')
			exit_flag++;
		if (map[i] == 'C')
			collectible_flag++;
	}
	if (player_flag == 1 && exit_flag == 1 && collectible_flag > 0)
		return (0);
	return (1);
}
