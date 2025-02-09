/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_toolkit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/09 21:03:16 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

// The binary operations return 1 if start < end, else -1
void	draw_mlx_line(t_env *env, t_mlx_line *line)
{
	t_bres_data	img;

	img.dx = abs(line->end_x - line->start_x);
	img.dy = abs(line->end_y - line->start_y);
	img.sx = (line->end_x - line->start_x) >> 31 | 1;
	img.sy = (line->end_y - line->start_y) >> 31 | 1;
	draw_bresenham_line(env, line, &img);
}

void	draw_bresenham_line(t_env *env, t_mlx_line *line, t_bres_data *img)
{
	int	x;
	int	y;
	int	e2;

	x = line->start_x;
	y = line->start_y;
	img->err = (img->dx) - (img->dy);
	while (1)
	{
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
		if (x == line->end_x && y == line->end_y)
			break ;
		e2 = 2 * img->err;
		if (e2 > -(img->dy))
		{
			img->err -= img->dy;
			x += img->sx;
		}
		if (e2 < img->dx)
		{
			img->err += img->dx;
			y += img->sy;
		}
	}
}

void	draw_mlx_circle(t_env *env, t_mlx_circle *circle)
{
	double	x;
	double	y;
	int		angle;
	int		pix;
	double	rad;

	pix = 360;
	angle = 0;
	while (angle < pix)
	{
		rad = angle * (M_PI / 180.0);
		x = circle->center_x + circle->radius * cos(rad);
		y = circle->center_y + circle->radius * sin(rad);
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
		angle++;
	}
}

void	draw_mlx_rect(t_env *env, t_mlx_rect *rect)
{
	t_mlx_line	line;
	int			sides[4][4];
	int			side;

	map_mlx_rect(rect, sides);
	side = 0;
	while (side < 4)
	{
		line.start_x = sides[side][0];
		line.start_y = sides[side][1];
		line.end_x = sides[side][2];
		line.end_y = sides[side][3];
		draw_mlx_line(env, &line);
		side++;
	}
}

void	map_mlx_rect(t_mlx_rect *rect, int sides[4][4])
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;

	x1 = rect->origin_x;
	x2 = (rect->origin_x + rect->length);
	y1 = rect->origin_y;
	y2 = (rect->origin_y + rect->width);
	sides[0][0] = x1;
	sides[0][1] = y1;
	sides[0][2] = x2;
	sides[0][3] = y1;
	sides[1][0] = x2;
	sides[1][1] = y1;
	sides[1][2] = x2;
	sides[1][3] = y2;
	sides[2][0] = x2;
	sides[2][1] = y2;
	sides[2][2] = x1;
	sides[2][3] = y2;
	sides[3][0] = x1;
	sides[3][1] = y2;
	sides[3][2] = x1;
	sides[3][3] = y1;
}
