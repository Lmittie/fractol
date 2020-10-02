/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:48:08 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/09 18:00:49 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(void)
{
	ft_putendl("usage ./fractol [fractal]");
	ft_putendl("2D fractals:");
	ft_putendl("Mandelbrot\nJulia\nNewton\nBurningShip\nCelticMandelbrot");
}

int		main(int ac, char **av)
{
	t_mlx_identifiers mlx;

	if (ac != 2)
	{
		error_message();
		return (0);
	}
	check_valid(av[1]);
	mlx.mlx_ptr = mlx_init();
	mlx.window_geometry = (t_ivec2){1500, 1500};
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
								mlx.window_geometry.x,
								mlx.window_geometry.y,
								"Fract'ol");
	run_program(av[1], mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
