/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:50:45 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/13 03:56:07 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_bytes(char *map)
{
	int		file;
	char	*buffer;
	int		read_bytes;
	int		total_bytes;

	file = open(map, O_RDONLY);
	buffer = malloc(100);
	read_bytes = read(file, buffer, 100);
	if (read_bytes == 0)
		return (1);
	total_bytes = 0;
	total_bytes += read_bytes;
	while (read_bytes != 0)
	{
		read_bytes = read(file, buffer, 100);
		total_bytes += read_bytes;
	}
	close(file);
	free(buffer);
	return (total_bytes);
}

char	*read_map(char *map)
{
	int		file;
	int		bytes;
	char	*map_b;

	bytes = get_map_bytes(map);	
	map_b = ft_calloc(sizeof(char), bytes);
	file = open(map, O_RDONLY);
	read(file, map_b, bytes);
	close(file);
	map_b[bytes] = 0;
	return(map_b);
}
