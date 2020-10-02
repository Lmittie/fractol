/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_identifiers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:17:55 by lmittie           #+#    #+#             */
/*   Updated: 2020/02/04 18:50:58 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IDENTIFIERS_H

# define MLX_IDENTIFIERS_H

# include "linear_vectors.h"

# define MLX_K_C			8
# define MLX_K_O			31
# define MLX_K_UP			126
# define MLX_K_DOWN			125
# define MLX_K_LEFT			123
# define MLX_K_RIGHT		124
# define MLX_K_ESC			53
# define MLX_M_LEFT			1
# define MLX_M_RIGHT		2
# define MLX_M_MIDDLE		3
# define MLX_M_SCROLL_UP	4
# define MLX_M_SCROLL_DOWN	5

typedef struct		s_mlx_identifiers
{
	void		*win_ptr;
	void		*mlx_ptr;

	t_ivec2		window_geometry;
}					t_mlx_identifiers;

#endif
