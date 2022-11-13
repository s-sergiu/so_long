/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_components_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:10:41 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/13 19:35:49 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int has_map_components(char *map)
{
	int	i;
	int player_flag;
	int	exit_flag;
	int	collectible_flag;

	i = -1;
	player_flag = 0;
	exit_flag = 0;
	collectible_flag = 0;
	while (map[++i] != 0)
	{
		if (map[i] == 'P')
			player_flag++;
		if (map[i] == 'E')		
			exit_flag++;
		if (map[i] == 'C')		
			collectible_flag++;
	}
	if (player_flag == 1 && exit_flag == 1 && collectible_flag > 0)
		return (0);
	printf("collectible %d\nexit %d\nplayer %d\n", collectible_flag,
		exit_flag, player_flag);
	return (1);
}
