/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:39:30 by aevstegn          #+#    #+#             */
/*   Updated: 2024/12/05 20:55:43 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_search(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg (args, int), count);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex(va_arg(args, int), 0, count);
	else if (c == 'X')
		ft_puthex(va_arg(args, int), 1, count);
	else if (c == '%')
		ft_putchar('%', count);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	const char	*ptr;
	int			count;
	va_list		args;

	va_start(args, format);
	count = 0;
	ptr = format;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (format_search(*ptr, args, &count) == 0)
			{
				ft_putchar('%', &count);
				ft_putchar(*ptr, &count);
			}
		}
		else
			ft_putchar(*ptr, &count);
		ptr++;
	}
	va_end(args);
	return (count);
}
