/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:38:42 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/13 15:43:34 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractal *fractal, t_mlx *mlx)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		draw_mandelbrot(fractal, mlx);
	else if (!ft_strncmp(fractal->name, "julia", 5))
		draw_julia(fractal, mlx);
}

t_complex	calculate_complex(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	double		aspect_ratio;

	aspect_ratio = (double)WIDTH / HEIGHT;
	c.r = ((x - WIDTH / 2.0) * 4.0 / WIDTH) * fractal->zoom + fractal->offset_x;
	c.i = ((y - HEIGHT / 2.0) * (4.0 / aspect_ratio) / HEIGHT) * fractal->zoom
		+ fractal->offset_y;
	return (c);
}

void	draw_mandelbrot(t_fractal *fractal, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_mandel_pixel(fractal, mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}

void	draw_julia(t_fractal *fractal, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_julia_pixel(fractal, mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}
