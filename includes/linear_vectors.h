/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_vectors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:20:37 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/09 17:58:43 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_VECTORS_H

# define LINEAR_VECTORS_H

# include <OpenGL/gl.h>

typedef struct	s_ivec2
{
	GLint	x;
	GLint	y;
}				t_ivec2;

typedef struct	s_ivec3
{
	GLint x;
	GLint y;
	GLint z;
}				t_ivec3;

typedef struct	s_vec2
{
	GLfloat x;
	GLfloat y;
}				t_vec2;

typedef struct	s_vec3
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
}				t_vec3;

typedef struct	s_vec4 {
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
}				t_vec4;

#endif
