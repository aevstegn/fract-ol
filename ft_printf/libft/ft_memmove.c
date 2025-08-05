/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:29:20 by aevstegn          #+#    #+#             */
/*   Updated: 2024/11/15 20:25:53 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d2;
	unsigned char		*s2;
	size_t				i;

	d2 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = -1;
	if (n == 0 || d2 == s2)
		return (dest);
	if (d2 > s2 && d2 < s2 + n)
	{
		while (n > 0)
		{
			n--;
			d2[n] = s2[n];
		}
	}
	else
	{
		while (++i < n)
		{
			d2[i] = s2[i];
		}
	}
	return (dest);
}
