/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:39:24 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/13 16:02:58 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("\t1) ./fractol mandelbrot\n");
	ft_printf("\t2) ./fractol julia <value 1> <value 2>\n");
}

static int	handle_arguments(t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2)
	{
		print_usage();
		return (0);
	}
	if (!ft_strcmp(argv[1], "mandelbrot"))
		fractal->name = "mandelbrot";
	else if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc != 4 || !is_valid_number(argv[2]) || !is_valid_number(argv[3]))
		{
			print_usage();
			return (0);
		}
		fractal->name = "julia";
		fractal->julia_cr = ft_atof(argv[2]);
		fractal->julia_ci = ft_atof(argv[3]);
	}
	else
	{
		print_usage();
		return (0);
	}
	return (1);
}

static void	start_fractal(t_fractal *fractal)
{
	t_mlx	mlx;

	set_mlx(&mlx);
	fractal_init(fractal);
	fractal->mlx = &mlx;
	draw_fractal(fractal, &mlx);
	mlx_mouse_hook(mlx.window, mouse_handler, fractal);
	mlx_key_hook(mlx.window, key_hook, fractal);
	mlx_hook(mlx.window, 6, 1L << 6, julia_track, fractal);
	mlx_hook(mlx.window, 17, 0, exit_program, fractal);
	mlx_loop(mlx.mlx);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (!handle_arguments(&fractal, argc, argv))
		return (1);
	start_fractal(&fractal);
	return (0);
}
