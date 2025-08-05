/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:40:40 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/21 16:25:46 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_program(void *parameter)
{
	t_fractal	*fractal;
	t_mlx		*mlx;

	fractal = (t_fractal *)parameter;
	mlx = fractal->mlx;
	if (mlx && mlx->mlx && mlx->image)
		mlx_destroy_image(mlx->mlx, mlx->image);
	if (mlx && mlx->mlx && mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx && mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	exit(0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)y;
	(void)x;
	if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	else if (button == Button5)
	{
		fractal->zoom /= 1.05;
	}
	else
		return (0);
	draw_fractal(fractal, fractal->mlx);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	static int	last_x;
	static int	last_y;
	const int	move_factor = 3;

	last_x = -1;
	last_y = -1;
	if (abs(x - last_x) > move_factor || abs(y - last_y) > move_factor)
	{
		last_x = x;
		last_y = y;
		fractal->julia_cr = ((double)x / (double)WIDTH - 0.5) * 4.0
			* fractal->zoom + fractal->offset_x;
		fractal->julia_ci = ((double)y / (double)HEIGHT - 0.5) * 4.0
			* fractal->zoom + fractal->offset_y;
		draw_fractal(fractal, fractal->mlx);
	}
	return (0);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		exit_program(fractal);
	return (0);
}
