/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:56:43 by aevstegn          #+#    #+#             */
/*   Updated: 2024/11/20 19:36:52 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, unsigned int len)
{
	char	*arr;

	arr = ptr;
	while (len > 0)
	{
		*arr = value;
		arr++;
		len--;
	}
	return (ptr);
}
