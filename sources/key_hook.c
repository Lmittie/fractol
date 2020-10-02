/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:35:47 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/09 18:06:11 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		change_color(t_basic_fractal *fractal)
{
	static t_vec3	color_shift = (t_vec3){0.10, 0.0, 0.0};

	if (color_shift.x < 0.25)
		color_shift.x += 0.01;
	else if (color_shift.x >= 0.25 && color_shift.y < 0.25)
		color_shift.y += 0.01;
	else if (color_shift.y >= 0.25 && color_shift.z < 0.25)
		color_shift.z += 0.01;
	else
		color_shift = (t_vec3){0.05, 0.0, 0.0};
	fractal->color_shift = color_shift;
}

static void		moving(t_basic_fractal *fractal, int key)
{
	if (key == MLX_K_UP)
		fractal->camera_position.y += (0.01) / fractal->zoom;
	else if (key == MLX_K_DOWN)
		fractal->camera_position.y -= (0.01) / fractal->zoom;
	else if (key == MLX_K_LEFT)
		fractal->camera_position.x -= (0.01) / fractal->zoom;
	else if (key == MLX_K_RIGHT)
		fractal->camera_position.x += (0.01) / fractal->zoom;
}

int				on_key(int key, t_fractal *data)
{
	t_basic_fractal	*fractal;

	fractal = ((t_basic_fractal*)data->fractal_name);
	if (key == MLX_K_ESC)
	{
		glDeleteBuffers(1, &(fractal->buffer.vbo));
		glDeleteVertexArraysAPPLE(1, &(fractal->buffer.vao));
		glDeleteShader(fractal->shader.shader_program);
		exit(0);
	}
	else if (key == MLX_K_C)
		change_color(fractal);
	else if (key == MLX_K_UP || key == MLX_K_DOWN
				|| key == MLX_K_LEFT || key == MLX_K_RIGHT)
		moving(fractal, key);
	else if (key == 69)
		fractal->max_iteration++;
	else if (key == 78)
		fractal->max_iteration--;
	return (0);
}
