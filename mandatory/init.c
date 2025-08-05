/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:03:30 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/13 15:06:25 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->max_iter = MAX_ITER;
	fractal->color_shift = 0;
}

void	set_mlx(t_mlx *mlx)
{
	char	*title;

	title = "Fractal";
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, title);
	mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->buffer = mlx_get_data_addr(mlx->image, &mlx->bpp, &mlx->size_line,
			&mlx->endian);
}
