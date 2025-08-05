/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:44:04 by aevstegn          #+#    #+#             */
/*   Updated: 2024/12/05 22:02:11 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	ft_putnbr(int nb, int *count)
{
	long long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		ft_putnbr((nbr / 10), count);
	ft_putchar((nbr % 10) + '0', count);
}

// #include <stdio.h>
// int main()
// {
// 	printf(" %d %d %d %d\n", INT_MAX, INT_MIN, 0, -42);
// 	ft_printf (" %d %d %d %d\n", INT_MAX, INT_MIN, 0, -42);
// }