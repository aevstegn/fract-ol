/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:26:45 by aevstegn          #+#    #+#             */
/*   Updated: 2024/12/05 22:07:38 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, count);
		str++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	printf("NULL %s NULL ", NULL);
// 	ft_printf("NULL %s NULL ", NULL);
// }