/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:57:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/17 10:19:10 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_arrlength(char **string)
{
	size_t	i;	

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (print_usage());
	else
		if (map_has_no_errors(argv[1]))
			init_game(argv[1]);
	return (0);
}
