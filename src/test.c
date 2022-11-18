/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:31:02 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/18 15:27:16 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_handling(char errnum)
{
	if (!errnum)
		write(2, "Invalid map name.", 17);
	else
		ft_putstr_fd(strerror(errnum), 2);
	write(2, "\n", 1);
	return (1);
}

int	not_valid_map_name(char *filename)
{
	int	len;
	int	file;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (error_handling(errno));
	close(file);
	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".ber\0", 5))
		return (error_handling(0));
	return (0);
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
			return (1);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != 0)
		free(split[i]);
	free(split);
}
