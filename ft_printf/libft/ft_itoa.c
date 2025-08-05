/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:01:37 by aevstegn          #+#    #+#             */
/*   Updated: 2024/11/26 15:28:29 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_negative;
	int		i;

	is_negative = (n < 0);
	i = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (ft_numlen(n) + is_negative + 1));
	if (!str)
		return (NULL);
	if (is_negative)
		n = -n;
	while (n > 0 || i == 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
