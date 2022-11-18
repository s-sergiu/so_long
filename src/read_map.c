/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:50:45 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/18 14:16:34 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_and_return(void *memory)
{
	free(memory);
	return (1);
}

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
		return (free_and_return(buffer));
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

	bytes = get_map_bytes(map) + 1;
	map_b = ft_calloc(sizeof(char), bytes);
	file = open(map, O_RDONLY);
	read(file, map_b, bytes);
	close(file);
	return (map_b);
}
