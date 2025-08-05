/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:02:43 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/21 16:09:07 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/fractol.h"
#include "fractol_bonus.h"

static void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("\t1) ./fractol mandelbrot\n");
	ft_printf("\t2) ./fractol julia <value 1> <value 2>\n");
	ft_printf("\t3) ./fractol celtic\n");
	ft_printf("\t4) ./fractol burning_ship\n");
}

static int	handle_julia_args(t_fractal *fractal, int argc, char **argv)
{
	if (argc != 4 || !is_valid_number(argv[2]) || !is_valid_number(argv[3]))
	{
		print_usage();
		return (0);
	}
	fractal->name = "julia";
	fractal->julia_cr = ft_atof(argv[2]);
	fractal->julia_ci = ft_atof(argv[3]);
	return (1);
}

static int	handle_arguments(t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2)
	{
		print_usage();
		return (0);
	}
	if (!ft_strcmp(argv[1], "mandelbrot") && argc < 3)
		fractal->name = "mandelbrot";
	else if (!ft_strcmp(argv[1], "celtic") && argc < 3)
		fractal->name = "celtic";
	else if (!ft_strcmp(argv[1], "burning_ship"))
		fractal->name = "burning_ship";
	else if (!ft_strcmp(argv[1], "julia"))
		return (handle_julia_args(fractal, argc, argv));
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
	fractal->track_julia = 0;
	draw_fractal_bonus(fractal, &mlx);
	mlx_mouse_hook(mlx.window, mouse_handler_bonus, fractal);
	mlx_hook(mlx.window, 6, 1L << 6, mouse_move_bonus, fractal);
	mlx_key_hook(mlx.window, key_hook_bonus, fractal);
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
