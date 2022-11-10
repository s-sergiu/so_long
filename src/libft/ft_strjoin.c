/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:00:10 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/31 05:06:13 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	s1_length;
	size_t	s2_length;

	s1_length = 1;
	if (!s2 || !s1)
		return (NULL);
	s2_length = ft_strlen(s2);
	s1_length = ft_strlen(s1);
	i = -1;
	str = malloc(s1_length + s2_length + 1);
	if (!str)
		return (NULL);
	while (++i < (int)s2_length)
		str[i] = s2[i];
	i = -1;
	while (++i < (int)s1_length)
		str[i + s2_length] = s1[i];
	str[i + s2_length] = 0;
	return (str);
}
