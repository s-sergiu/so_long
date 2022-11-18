/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:44:30 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/18 11:24:18 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*trim_string(char *s, char c)
{
	while (s[0] == c && c)
		s++;
	return (s);
}

static int	get_words(char const *s, char c)
{
	int	i;
	int	wc;

	i = -1;
	wc = 0;
	if (!s || !s[0])
		return (0);
	while (s[++i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
		wc++;
		i--;
		}
	}
	return (wc);
}

static int	get_letters(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**free_rest(char **str, int index)
{
	if (!index)
		free(str);
	else
		while (index >= 0)
			free(str[index--]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		index;
	int		lc;

	if (!s)
	{
		return (NULL);
	}
	str = (char **)malloc((get_words((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (free_rest(str, 0));
	if (s[0])
		s = trim_string((char *)s, c);
	index = 0;
	while (ft_strlen(s))
	{
		lc = get_letters((char *)s, c);
		str[index] = (char *)malloc((lc + 1) * sizeof(char));
		if (!str[index])
			return (free_rest(str, index));
		ft_strlcpy(str[index++], s, lc + 1);
		s = trim_string((char *)s + lc, c);
	}
	str[index] = NULL;
	return (str);
}
