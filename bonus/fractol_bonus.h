/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:00:34 by aevstegn          #+#    #+#             */
/*   Updated: 2025/05/21 16:29:25 by aevstegn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../mandatory/fractol.h"

void		draw_celtic_pixel(t_fractal *f, t_mlx *mlx, int x, int y);
int			mouse_handler_bonus(int button, int x, int y, t_fractal *fractal);
int			key_hook_bonus(int keycode, t_fractal *fractal);
void		draw_celtic(t_fractal *fractal, t_mlx *mlx);
void		draw_fractal_bonus(t_fractal *fractal, t_mlx *mlx);
void		draw_burning_ship(t_fractal *fractal, t_mlx *mlx);
void		draw_burning_ship_pixel(t_fractal *f, t_mlx *mlx, int x, int y);
int			mouse_move_bonus(int x, int y, t_fractal *fractal);
#endif