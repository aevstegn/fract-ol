/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:23:33 by aevstegn          #+#    #+#             */
/*   Updated: 2024/11/20 15:52:25 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen((char *)needle);
	while (i < len && haystack[i])
	{
		if (i + n_len > len)
			return (0);
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, n_len) == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
