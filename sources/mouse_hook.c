/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:38:29 by lmittie           #+#    #+#             */
/*   Updated: 2020/01/25 15:41:24 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zooming(int button, int x, int y, t_basic_fractal *fractal)
{
	if (button == MLX_M_SCROLL_UP)
	{
		fractal->zoom *= 1.1;
		fractal->camera_position.x += ((float)(x - 750.0) / 750.0)
										/ fractal->zoom / fractal->offset_ratio;
		fractal->camera_position.y += ((float)(750.0 - y) / 750.0)
										/ fractal->zoom / fractal->offset_ratio;
	}
	else if (button == MLX_M_SCROLL_DOWN)
	{
		fractal->zoom /= 1.1;
		fractal->camera_position.x -= ((float)(x - 750.0) / 750.0)
										/ fractal->zoom / fractal->offset_ratio;
		fractal->camera_position.y -= ((float)(750.0 - y) / 750.0)
										/ fractal->zoom / fractal->offset_ratio;
	}
}

int		on_mouse_press(int button, int x, int y, t_fractal *data)
{
	t_basic_fractal	*fractal;

	fractal = ((t_basic_fractal*)data->fractal_name);
	if (button == MLX_M_RIGHT && !fractal->pkm_pressed)
		fractal->pkm_pressed = 1;
	else if (button == MLX_M_RIGHT)
		fractal->pkm_pressed = 0;
	if (button == MLX_M_LEFT && !fractal->lkm_pressed)
		fractal->lkm_pressed = 1;
	else if (button == MLX_M_LEFT)
		fractal->lkm_pressed = 0;
	if (button == MLX_M_SCROLL_UP || button == MLX_M_SCROLL_DOWN)
		zooming(button, x, y, fractal);
	return (0);
}

int		on_mouse_move(int x, int y, t_fractal *data)
{
	t_basic_fractal	*fractal;

	fractal = ((t_basic_fractal*)data->fractal_name);
	if (!fractal->pkm_pressed)
	{
		fractal->param.x = 4 * ((float)x / 1500.0 - 0.5);
		fractal->param.y = 4 * ((float)(1500 - y) / 1500.0 - 0.5);
	}
	if (fractal->lkm_pressed)
	{
		fractal->camera_position.x += ((float)(x - 750.0) / 750.0)
										/ fractal->zoom / fractal->ratio;
		fractal->camera_position.y += ((float)(750.0 - y) / 750.0)
										/ fractal->zoom / fractal->ratio;
	}
	return (0);
}
