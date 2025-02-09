/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color_toolkit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/12 19:31:16 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLOR_TOOLKIT_H
# define MLX_COLOR_TOOLKIT_H

# include "./libxkit.h"

/* Coloring structs */
typedef struct s_mlx_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_mlx_color;

/* Prototypes */
int	set_color(t_mlx_color *color);
int	get_color(t_mlx_color *color, char param);
int	rev_color(t_mlx_color *color);
// int	get_gradient_color(t_mlx_color *start, t_mlx color *end, float t);
// int	blend_colors(t_mlx_color *color_1, t_mlx_color *color_2);

#endif
