/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:44:25 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/21 16:27:00 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	factor;
	int		i;

	result = 0.0;
	sign = 1.0;
	factor = 1.0;
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i++] == '-')
		sign = -1.0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			factor *= 0.1;
			result += (str[i++] - '0') * factor;
		}
	}
	return (result * sign);
}

int	is_valid_number(const char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dot_count == 1)
				return (0);
			dot_count++;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
