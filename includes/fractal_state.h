/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_state.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:22:45 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/09 16:14:48 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_STATE_H

# define FRACTAL_STATE_H

# include "mlx_identifiers.h"

typedef struct	s_fractal
{
	t_mlx_identifiers	mlx;
	void				*fractal_name;
	int					(*draw_fractal)(struct s_fractal *fractal);
}				t_fractal;

typedef struct	s_shader
{
	GLuint	shader_program;
	GLuint	vertex_shader;
	GLuint	fragment_shader;
}				t_shader;

typedef struct	s_vertex_buffer
{
	GLuint	vbo;
	GLuint	vao;
}				t_vertex_buffer;

typedef struct	s_basic_fractal
{
	t_shader		shader;
	t_vertex_buffer	buffer;
	GLuint			resolution_location;

	GLfloat			zoom;
	GLuint			zoom_location;

	t_vec2			camera_position;
	GLuint			camera_position_location;

	t_vec3			color_shift;
	GLuint			color_shift_location;

	t_vec2			param;
	GLuint			julia_parameters_location;

	GLfloat			max_iteration;
	GLuint			max_iteration_location;

	int				pkm_pressed;
	int				lkm_pressed;

	float			ratio;
	float			offset_ratio;
}				t_basic_fractal;

#endif
