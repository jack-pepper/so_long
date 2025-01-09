/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color_toolkit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/06 23:28:37 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLOR_TOOLKIT_H
# define MLX_COLOR_TOOLKIT_H

# include "./libxkit.h"

/* Coloring structs */
typedef struct	s_mlx_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_mlx_color;

/* Prototypes */
int     set_color(t_mlx_color *color);
int     get_color(t_mlx_color *color, char param);

#endif
