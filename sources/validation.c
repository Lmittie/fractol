/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:00:53 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/04 17:55:30 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_valid(const char *fractal_name)
{
	if (ft_strcmp(fractal_name, "Mandelbrot")
	&& ft_strcmp(fractal_name, "Julia")
	&& ft_strcmp(fractal_name, "BurningShip")
	&& ft_strcmp(fractal_name, "Newton")
	&& ft_strcmp(fractal_name, "CelticMandelbrot"))
	{
		error_message();
		exit(-1);
	}
}

void	run_program(const char *fractal_name, t_mlx_identifiers mlx)
{
	t_fractal *data;

	data = NULL;
	if (!ft_strcmp(fractal_name, "Mandelbrot"))
		data = create_basic_fractal("./shaders/Mandelbrot_shader.glsl", mlx);
	else if (!ft_strcmp(fractal_name, "Julia"))
		data = create_basic_fractal("./shaders/Julia_shader.glsl", mlx);
	else if (!ft_strcmp(fractal_name, "BurningShip"))
		data = create_basic_fractal("./shaders/Burning_ship_shader.glsl", mlx);
	else if (!ft_strcmp(fractal_name, "Newton"))
		data = create_basic_fractal("./shaders/Newton_shader.glsl", mlx);
	else if (!ft_strcmp(fractal_name, "CelticMandelbrot"))
		data = create_basic_fractal("./shaders/Celtic_Mand_shader.glsl", mlx);
	else
	{
		error_message();
		exit(-1);
	}
	mlx_hook(data->mlx.win_ptr, 2, 0, on_key, data);
	mlx_hook(data->mlx.win_ptr, 17, 0, on_close, data);
	mlx_hook(data->mlx.win_ptr, 6, 0, on_mouse_move, data);
	mlx_hook(data->mlx.win_ptr, 4, 0, on_mouse_press, data);
	mlx_loop_hook(data->mlx.mlx_ptr, data->draw_fractal, data);
}
