/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:15:24 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/09 18:05:49 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot_values(t_basic_fractal *fractal)
{
	fractal->zoom = 0.4f;
	fractal->camera_position = (t_vec2){-0.5f, 0.0f};
	fractal->ratio = 125.0;
	fractal->offset_ratio = 19.95;
}

void	init_julia_values(t_basic_fractal *fractal)
{
	fractal->param = (t_vec2){-0.4, 0.6};
	fractal->zoom = 0.25f;
	fractal->camera_position = (t_vec2){0.0f, 0.0f};
	fractal->ratio = 120.0f;
	fractal->offset_ratio = 19.6;
}

void	init_burning_ship_values(t_basic_fractal *fractal)
{
	fractal->zoom = 0.5;
	fractal->offset_ratio = 19.7;
	fractal->camera_position = (t_vec2){0.2f, 0.2f};
	fractal->ratio = 125.0;
}

void	init_newton_values(t_basic_fractal *fractal)
{
	fractal->zoom = 1.0;
	fractal->camera_position = (t_vec2){0.0, 0.0};
	fractal->offset_ratio = 19.85;
	fractal->ratio = 130.0;
}

void	init_celtic_mand_values(t_basic_fractal *fractal)
{
	fractal->zoom = 0.9;
	fractal->camera_position = (t_vec2){-0.2, 0.0};
	fractal->offset_ratio = 3.45;
	fractal->ratio = 50.0;
}
