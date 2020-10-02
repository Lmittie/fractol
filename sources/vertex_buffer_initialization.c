/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_buffer_initialization.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:32:40 by lmittie           #+#    #+#             */
/*   Updated: 2020/01/25 15:33:01 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vertex_buffer	vertex_buffer_initialization(void)
{
	t_vertex_buffer	buffer;
	const GLfloat	vertices[4][3] = {
						{-1.0, 1.0, 0.0},
						{1.0, 1.0, 0.0},
						{1.0, -1.0, 0.0},
						{-1.0, -1.0, 0.0},
						};

	glGenVertexArraysAPPLE(1, &(buffer.vao));
	glBindVertexArrayAPPLE(buffer.vao);
	glGenBuffers(1, &(buffer.vbo));
	glBindBuffer(GL_ARRAY_BUFFER, buffer.vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindVertexArrayAPPLE(0);
	return (buffer);
}
