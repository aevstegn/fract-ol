/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:09:50 by aevstegn          #+#    #+#             */
/*   Updated: 2024/11/20 16:41:29 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	smb;

	i = 0;
	num = 0;
	smb = 1;
	while (ft_isspace((unsigned char)str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			smb = -1;
		i++;
	}
	while (ft_isdigit((unsigned char)str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * smb);
}
