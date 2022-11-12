/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:16:47 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/12 05:48:49 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_arrlength(char **string)
{
	size_t	i;	
	
	i = 0;
	while (string[i] != 0)
		i++;
	
	return (i);
}

int	is_valid_map_name(char *filename)
{
	int	len;
	int	file;

	len = ft_strlen(filename);
	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		error_handling(errno);
		return (0);
	}
	close(file);
	if (!ft_strncmp(filename + (len - 4), ".ber\0", 5))
		return (1);
	error_handling(1);
	return (0);
}

int is_valid_map_structure(char **map)
{
	size_t	reper;
	size_t	i;
	
	reper = ft_strlen(*map);
	printf("checking map structure\n");
	i = 0;
	while (i < ft_arrlength(map))
		if (ft_strlen(map[i++]) != reper)
			return (0);
	printf("map is good\n");
	return (1);
}

int	is_valid_map(char **map)
{
	size_t	i;
	size_t	len;
	size_t	arrlen;

	if (!is_valid_map_structure(map))
		return(0);
	i = 0;
	printf("yesss\n");
	arrlen = ft_arrlength(map);
	len = ft_strlen(*map);
	while (map[0][i] != 0)
	{
		if (map[0][i++] != '1')
			return(0);
	}
	i = 0;
	while (i < arrlen)
	{
		if (map[i++][0] != '1')
			return(0);
	}
	i = 0;
	while (i < arrlen)
	{
		if (map[i++][len - 1] != '1')
			return(0);
	}
	i = 0;
	while (map[arrlen - 1][i] != 0)
	{
		if (map[arrlen - 1][i++] != '1')
			return(0);
	}
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
		return (0);
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
	printf("yes\n");
	return(map_b);
}
