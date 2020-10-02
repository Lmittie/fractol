/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:48:46 by lmittie           #+#    #+#             */
/*   Updated: 2020/10/02 18:51:04 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define GL_SILENCE_DEPRECATION
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "mlx_identifiers.h"
# include "linear_vectors.h"
# include "fractal_state.h"
# include <OpenGL/gl.h>

t_vertex_buffer	vertex_buffer_initialization(void);

void			init_mandelbrot_values(t_basic_fractal *fractal);
void			init_julia_values(t_basic_fractal *fractal);
void			init_burning_ship_values(t_basic_fractal *fractal);
void			init_newton_values(t_basic_fractal *fractal);
void			init_celtic_mand_values(t_basic_fractal *fractal);

t_shader		create_shader_program(const char *vertex_shader,
										const char *fragment_shader);
t_fractal		*create_basic_fractal(const char *path, t_mlx_identifiers mlx);

void			run_program(const char *fractal_name, t_mlx_identifiers mlx);
void			check_valid(const char *fractal_name);

void			error_message(void);

int				draw_basic_fractal(t_fractal *fractal);

int				on_key(int key, t_fractal *data);
int				on_mouse_press(int button, int x, int y, t_fractal *data);
int				on_mouse_move(int x, int y, t_fractal *data);
int				on_close(t_fractal *data);

#endif
