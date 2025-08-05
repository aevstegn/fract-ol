/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:17:25 by aevstegn          #+#    #+#             */
/*   Updated: 2025/04/30 19:53:41 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	psychedelic_color(int iter, int color_shift)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * (0.5 + 0.5 * sin(iter * 0.1 + color_shift)));
	g = (int)(255 * (0.5 + 0.5 * sin(iter * 0.2 + color_shift + 2)));
	b = (int)(255 * (0.5 + 0.5 * sin(iter * 0.3 + color_shift + 4)));
	return ((r << 16) | (g << 8) | b);
}

void	color_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	index;
	int	*pixel;

	index = 0;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		index = (y * mlx->size_line) + (x * (mlx->bpp / 8));
	pixel = (int *)(mlx->buffer + index);
	*pixel = color;
}

void	render_mandel_pixel(t_fractal *fractal, t_mlx *mlx, int x, int y)
{
	t_mandel	m;
	int			iter;
	int			color;
	t_complex	c;

	c = calculate_complex(fractal, x, y);
	m.cr = c.r;
	m.ci = c.i;
	m.zr = 0;
	m.zi = 0;
	iter = 0;
	while (m.zr * m.zr + m.zi * m.zi < 4 && iter < fractal->max_iter)
	{
		m.temp = m.zr * m.zr - m.zi * m.zi + m.cr;
		m.zi = 2.0 * m.zr * m.zi + m.ci;
		m.zr = m.temp;
		iter++;
	}
	if (iter == fractal->max_iter)
		color_pixel(mlx, x, y, 0x000000);
	else
	{
		color = psychedelic_color(iter, fractal->color_shift);
		color_pixel(mlx, x, y, color);
	}
}

void	render_julia_pixel(t_fractal *fractal, t_mlx *mlx, int x, int y)
{
	t_mandel	m;
	int			iter;
	int			color;
	t_complex	z;

	z = calculate_complex(fractal, x, y);
	m.zr = z.r;
	m.zi = z.i;
	m.cr = fractal->julia_cr;
	m.ci = fractal->julia_ci;
	iter = 0;
	while (m.zr * m.zr + m.zi * m.zi < 4 && iter < fractal->max_iter)
	{
		m.temp = m.zr * m.zr - m.zi * m.zi + m.cr;
		m.zi = 2.0 * m.zr * m.zi + m.ci;
		m.zr = m.temp;
		iter++;
	}
	if (iter == fractal->max_iter)
		color_pixel(mlx, x, y, 0x000000);
	else
	{
		color = psychedelic_color(iter, fractal->color_shift);
		color_pixel(mlx, x, y, color);
	}
}
