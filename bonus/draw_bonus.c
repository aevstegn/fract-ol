/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:59:13 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/21 16:29:51 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/fractol.h"
#include "fractol_bonus.h"

void	draw_fractal_bonus(t_fractal *fractal, t_mlx *mlx)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		draw_mandelbrot(fractal, mlx);
	else if (!ft_strncmp(fractal->name, "celtic", 6))
		draw_celtic(fractal, mlx);
	else if (!ft_strncmp(fractal->name, "julia", 5))
		draw_julia(fractal, mlx);
	else if (!ft_strncmp(fractal->name, "burning_ship", 12))
		draw_burning_ship(fractal, mlx);
}

void	draw_celtic_pixel(t_fractal *f, t_mlx *mlx, int x, int y)
{
	t_mandel	c;
	t_complex	p;
	int			iter;
	int			color;

	p = calculate_complex(f, x, y);
	c.cr = p.r;
	c.ci = p.i;
	c.zr = 0;
	c.zi = 0;
	iter = 0;
	while (c.zr * c.zr + c.zi * c.zi < 4 && iter < f->max_iter)
	{
		c.temp = fabs(c.zr * c.zr - c.zi * c.zi) + c.cr;
		c.zi = 2.0 * c.zr * c.zi + c.ci;
		c.zr = c.temp;
		iter++;
	}
	if (iter == f->max_iter)
		color_pixel(mlx, x, y, 0x000000);
	else
	{
		color = psychedelic_color(iter, f->color_shift);
		color_pixel(mlx, x, y, color);
	}
}

void	draw_celtic(t_fractal *fractal, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_celtic_pixel(fractal, mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}

void	draw_burning_ship_pixel(t_fractal *f, t_mlx *mlx, int x, int y)
{
	t_mandel	c;
	t_complex	p;
	int			iter;
	int			color;

	p = calculate_complex(f, x, y);
	c.cr = p.r;
	c.ci = p.i;
	c.zr = 0;
	c.zi = 0;
	iter = 0;
	while (c.zr * c.zr + c.zi * c.zi < 4 && iter < f->max_iter)
	{
		c.temp = c.zr * c.zr - c.zi * c.zi + c.cr;
		c.zi = fabs(2.0 * c.zr * c.zi) + c.ci;
		c.zr = fabs(c.temp);
		iter++;
	}
	if (iter == f->max_iter)
		color_pixel(mlx, x, y, 0x000000);
	else
	{
		color = psychedelic_color(iter, f->color_shift);
		color_pixel(mlx, x, y, color);
	}
}

void	draw_burning_ship(t_fractal *fractal, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_burning_ship_pixel(fractal, mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}
