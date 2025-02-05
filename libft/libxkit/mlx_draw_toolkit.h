/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_toolkit.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:03:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/13 12:10:52 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DRAW_TOOLKIT_H
# define MLX_DRAW_TOOLKIT_H

# include "./libxkit.h"

/* Structs */
typedef struct s_mlx_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
}		t_mlx_line;

typedef struct s_bres_data
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}		t_bres_data;

typedef struct s_mlx_circle
{
	int	center_x;
	int	center_y;
	int	radius;
}		t_mlx_circle;

typedef struct s_mlx_rect
{
	int	origin_x;
	int	origin_y;
	int	length;
	int	width;
}	t_mlx_rect;

/* Prototypes */
void	draw_mlx_line(t_env *env, t_mlx_line *line);
void	draw_bresenham_line(t_env *env, t_mlx_line *line, t_bres_data *img);
void	draw_mlx_circle(t_env *env, t_mlx_circle *circle);
void	draw_mlx_rect(t_env *env, t_mlx_rect *rect);
void	map_mlx_rect(t_mlx_rect *rect, int sides[4][4]);

#endif
