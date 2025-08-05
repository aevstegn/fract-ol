/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:38:35 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/21 16:15:03 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/fractol.h"
#include "fractol_bonus.h"

int	mouse_handler_bonus(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = ((double)x / WIDTH - 0.5) * 4.0 * fractal->zoom
		+ fractal->offset_x;
	mouse_im = ((double)y / HEIGHT - 0.5) * 4.0 * fractal->zoom
		+ fractal->offset_y;
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
	fractal->offset_x = mouse_re - ((double)x / WIDTH - 0.5) * 4.0
		* fractal->zoom;
	fractal->offset_y = mouse_im - ((double)y / HEIGHT - 0.5) * 4.0
		* fractal->zoom;
	draw_fractal_bonus(fractal, fractal->mlx);
	return (0);
}

int	mouse_move_bonus(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "julia") && fractal->track_julia)
		return (julia_track(x, y, fractal));
	return (0);
}

int	key_hook_bonus(int keycode, t_fractal *fractal)
{
	double	distance;

	distance = 0.5 * fractal->zoom;
	if (keycode == 65307)
		exit_program(fractal);
	else if (keycode == 65362)
		fractal->offset_y -= distance;
	else if (keycode == 65364)
		fractal->offset_y += distance;
	else if (keycode == 65361)
		fractal->offset_x -= distance;
	else if (keycode == 65363)
		fractal->offset_x += distance;
	else if (keycode == 32)
		fractal->track_julia = !fractal->track_julia;
	else if (keycode == 65289)
	{
		fractal->color_shift += 1;
		if (fractal->color_shift > 255)
			fractal->color_shift = 0;
	}
	draw_fractal_bonus(fractal, fractal->mlx);
	return (0);
}
