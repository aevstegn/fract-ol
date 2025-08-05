/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:01:45 by aevstegn          #+#    #+#             */
/*   Updated: 2024/11/15 18:41:04 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*ptr;
	unsigned char	b;

	i = 0;
	ptr = (unsigned char *)s;
	b = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == b)
			return (&ptr[i]);
		else
			i++;
	}
	return (0);
}
