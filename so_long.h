/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:30 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/27 15:05:15 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIN_X 1620
#define WIN_Y 780

#include "./libft/libft.h"
#include <math.h>
#include "./minilibx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct  s_vars
{
        void    *mlx;
        void    *win;
}               t_vars;

typedef struct  s_data
{
        void    *img;
        char    *addr;
        int     bits_per_pixel;
        int     line_length;
        int     endian;
}               t_data;

typedef struct  s_mlx_line
{
        int     start_x;
        int     start_y;
        int     end_x;
        int     end_y;
}               t_mlx_line;

typedef struct	s_bres_data
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}		t_bres_data;

typedef struct	s_mlx_circle
{
	int	center_x;
	int	center_y;
	int	radius;
}		t_mlx_circle;

typedef struct	s_mlx_rect
{
	int	origin_x;
	int	origin_y;
	int	length;
	int	width;
}		t_mlx_rect;

/* Prototypes */
//
void    mlx_fast_pixel_put(t_data *data, int x, int y, int color);
void    draw_mlx_line(t_vars *vars, t_mlx_line *line);
void	draw_bresenham_line(t_vars *vars, t_mlx_line *line, t_bres_data *data);
void	draw_mlx_circle(t_vars *vars, t_mlx_circle *circle);
void	draw_mlx_rect(t_vars *vars, t_mlx_rect *rect);
void	map_mlx_rect(t_mlx_rect *rect, int sides[4][4]);


int     win_close(int keysym, t_vars *vars);

// event_handler.c
int on_keypress(int keysym, t_vars *vars);
int on_destroy(t_vars *vars);


// Assets (name and path:)
//char	*tile;
//tile = 4_Seasons_Ground_Tiles.xpm
