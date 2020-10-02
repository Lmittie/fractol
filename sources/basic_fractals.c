/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:45:44 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/09 18:07:21 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			draw_basic_fractal(t_fractal *fractal)
{
	const t_basic_fractal	*str = ((t_basic_fractal*)fractal->fractal_name);

	glBindVertexArrayAPPLE(str->buffer.vao);
	glUseProgram(str->shader.shader_program);
	glUniform2f(str->resolution_location,
				(GLfloat)fractal->mlx.window_geometry.x,
				(GLfloat)fractal->mlx.window_geometry.y);
	glUniform1f(str->zoom_location, str->zoom);
	glUniform2fv(str->camera_position_location, 1,
				(GLfloat*)&str->camera_position);
	glUniform3fv(str->color_shift_location, 1, (GLfloat*)&str->color_shift);
	glUniform2fv(str->julia_parameters_location, 1, (GLfloat*)&str->param);
	glUniform1f(str->max_iteration_location, str->max_iteration);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glSwapAPPLE();
	return (1);
}

static void	get_uniform_location(t_basic_fractal *fractal, const char *path)
{
	fractal->buffer = vertex_buffer_initialization();
	fractal->shader = create_shader_program(
											"./shaders/vertex_shader.glsl",
											path);
	fractal->resolution_location = glGetUniformLocation(
											fractal->shader.shader_program,
											"iResolution");
	fractal->zoom_location = glGetUniformLocation(
											fractal->shader.shader_program,
											"zoom");
	fractal->camera_position_location = glGetUniformLocation(
											fractal->shader.shader_program,
											"cameraPosition");
	fractal->color_shift_location = glGetUniformLocation(
											fractal->shader.shader_program,
											"colorShift");
	fractal->julia_parameters_location = glGetUniformLocation(
											fractal->shader.shader_program,
											"juliaParameters");
	fractal->max_iteration_location = glGetUniformLocation(
											fractal->shader.shader_program,
											"maxStep");
}

t_fractal	*create_basic_fractal(const char *path, t_mlx_identifiers mlx)
{
	t_fractal		*data;
	t_basic_fractal	*fractal;

	if ((data = (t_fractal*)malloc(sizeof(t_fractal))) == NULL)
		exit(-1);
	if ((fractal = (t_basic_fractal*)malloc(sizeof(t_basic_fractal))) == NULL)
		exit(-1);
	ft_bzero(fractal, sizeof(t_basic_fractal));
	if (ft_strstr(path, "Mandelbrot"))
		init_mandelbrot_values(fractal);
	fractal->max_iteration = 600.0;
	if (ft_strstr(path, "Julia"))
		init_julia_values(fractal);
	if (ft_strstr(path, "Burning"))
		init_burning_ship_values(fractal);
	if (ft_strstr(path, "Newton"))
		init_newton_values(fractal);
	if (ft_strstr(path, "Celtic"))
		init_celtic_mand_values(fractal);
	fractal->color_shift = (t_vec3){0.10, 0.0, 0.0};
	get_uniform_location(fractal, path);
	data->mlx = mlx;
	data->fractal_name = fractal;
	data->draw_fractal = &draw_basic_fractal;
	return (data);
}
