/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:01:03 by aevstegn          #+#    #+#             */
/*   Updated: 2024/12/05 19:30:37 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putnbr_u(n / 10, count);
	ft_putchar((n % 10) + '0', count);
}
