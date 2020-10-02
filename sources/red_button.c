/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:11:14 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/09 17:35:47 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		on_close(t_fractal *data)
{
	t_basic_fractal	*fractal;

	fractal = ((t_basic_fractal*)data->fractal_name);
	glDeleteBuffers(1, &(fractal->buffer.vbo));
	glDeleteVertexArraysAPPLE(1, &(fractal->buffer.vao));
	glDeleteShader(fractal->shader.shader_program);
	exit(0);
}
