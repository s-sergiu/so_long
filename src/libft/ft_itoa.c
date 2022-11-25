/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:48:33 by ssergiu           #+#    #+#             */
/*   Updated: 2022/11/25 18:11:35 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	nlen(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (!n)
		return (1);
	if (n < 0)
		sign = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i + sign);
}

static void	logic(int n, char *result, int len)
{
	char	temp;

	if (n < 0)
	{
		n = n * -1;
		result[0] = '-';
	}
	while (n > 0)
	{
		temp = (char )(n % 10) + '0';
		result[(len--) - 1] = temp;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = nlen(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	else if (n == -2147483648)
	{
		n = n + 1;
		logic(n, result, len);
		result[len - 1] = '8';
	}
	else if (n < 0)
		logic(n, result, len);
	else
		logic(n, result, len);
	result[len] = '\0';
	return (result);
}
