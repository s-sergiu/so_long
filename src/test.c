/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:31:02 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/13 18:22:34 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_handling(char errnum)
{
	if (errnum == 1)
		write(2, "Invalid map name..\n", 19);
	else
		printf("%s\n", strerror(errnum));
}

int	valid_map_name(char *filename)
{
	int	len;
	int	file;

	len = ft_strlen(filename);
	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		error_handling(errno);
		return (1);
	}
	close(file);
	if (!ft_strncmp(filename + (len - 4), ".ber\0", 5))
		return (0);
	return (1);
}

int valid_map_structure(char **map)
{
	size_t	guide;
	size_t	i;
	
	if (!*map)
		return (1);
	guide = ft_strlen(*map);
	i = 1;
	while (i < ft_arrlength(map))
	{
		if (ft_strlen(map[i++]) != guide)
			return (1);
	}
	return (0);
}
