/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:39:47 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/21 16:17:18 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 1050
# define HEIGHT 600
# define MAX_ITER 50

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*buffer;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlx;

typedef struct s_fractal
{
	t_mlx	*mlx;
	char	*name;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	double	julia_cr;
	double	julia_ci;
	int		color_shift;
	int		track_julia;
}			t_fractal;

typedef struct s_mandel
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	temp;
}			t_mandel;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

void		set_mlx(t_mlx *mlx);
void		fractal_init(t_fractal *fractal);
void		draw_fractal(t_fractal *fractal, t_mlx *mlx);
void		color_pixel(t_mlx *mlx, int x, int y, int color);
int			psychedelic_color(int iter, int color_shift);
void		draw_mandelbrot(t_fractal *fractal, t_mlx *mlx);
void		draw_julia(t_fractal *fractal, t_mlx *mlx);
void		render_mandel_pixel(t_fractal *fractal, t_mlx *mlx, int x, int y);
void		render_julia_pixel(t_fractal *fractal, t_mlx *mlx, int x, int y);
t_complex	calculate_complex(t_fractal *fractal, int x, int y);
int			key_hook(int keycode, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			exit_program(void *param);
int			is_valid_number(const char *str);
double		ft_atof(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			julia_track(int x, int y, t_fractal *fractal);

#endif