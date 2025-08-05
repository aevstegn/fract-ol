/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:26:41 by aevstegn          #+#    #+#             */
/*   Updated: 2025/04/30 19:15:46 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthex(size_t n, int format, int *count)
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
		puthex(n / 16, format, count);
	ft_putchar(hex_case[n % 16], count);
}

void	ft_putptr(void *ptr, int *count)
{
	size_t	address;

	address = (size_t)ptr;
	if (ptr == NULL)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	puthex(address, 0, count);
}

// #include <stdio.h>
// #include <limits.h>
// int main()
// {
// 	printf (" %p %p \n", ULONG_MAX, -ULONG_MAX);
// 	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// }
