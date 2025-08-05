/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:05:54 by aevstegn          #+#    #+#             */
/*   Updated: 2025/04/30 19:14:51 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, int format, int *count)
{
	char	*upper;
	char	*lower;
	char	*hex_case;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	hex_case = lower;
	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (format == 1)
		hex_case = upper;
	if (n >= 16)
		ft_puthex(n / 16, format, count);
	ft_putchar(hex_case[n % 16], count);
}

// #include <stdio.h>
// int main()
// {
// 	int i = 0;
// 	ft_puthex((unsigned int)-99, 1, &i);
// 	printf("\n%X\n", -99);
// }
