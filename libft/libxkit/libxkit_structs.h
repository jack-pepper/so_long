/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxkit_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:16:07 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 02:13:25 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXKIT_STRUCTS_H
# define LIBXKIT_STRUCTS_H

/* */

/* Coloring struct */
typedef struct s_mlx_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_mlx_color;

/* Drawing structs */
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
}		t_mlx_rect;

/* Game env structs */
typedef struct s_pos
{
	int		x;
	int		y;
}		t_pos;

typedef struct s_size
{
	int		width;
	int		height;
}		t_size;

typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*path;
	int		bpp;
	int		l_len;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	t_img		*canvas;
	t_img		*bkgd_img;
	char		*bkgd_path;
	int			canvas_width;
	int			canvas_height;
}		t_env;

typedef struct s_data
{
	int	is_running;
	int	nb_steps;
	int	collected;
	int	to_be_collected;
}		t_data;

typedef struct s_cam
{
	t_pos	pos;
	t_pos	max;
}		t_cam;

typedef struct s_tile
{
	t_img		*img;
	t_pos		*pos;
	char		*path;
	int			width;
	int			height;
}		t_tile;

typedef struct s_map
{
	char	*fpath;
	char	**tilemap;
	t_tile	*wall;
	t_tile	*coll;
	t_tile	*exit;
	int		*tile_count;
	int		width;
	int		height;
	int		tm_rows;
	int		tm_cols;
	int		cell_width;
	int		cell_height;
	int		cell_size;
}		t_map;

// A counter and a requirement counter for checking tiles count.
typedef struct s_count_req
{
	int		count[6];
	int		req[6];
}		t_count_req;

typedef struct s_enemy
{
	t_img		*current_sprite;
	t_img		*to_up;
	t_img		*to_down;
	t_img		*to_left;
	t_img		*to_right;
	char		*to_up_path;
	char		*to_down_path;
	char		*to_left_path;
	char		*to_right_path;
	t_pos		*pos;
	int			frame;
	int			amplitude;
	char		direction;
	char		padding[7];
}		t_enemy;

typedef struct s_hero
{
	t_img		*img;
	t_img		*to_up;
	t_img		*to_down;
	t_img		*to_left;
	t_img		*to_right;
	char		*img_path;
	char		*to_up_path;
	char		*to_down_path;
	char		*to_left_path;
	char		*to_right_path;
	t_pos		*pos;
	int			frame;
	char		padding[4];
}		t_hero;

typedef struct s_state
{
	t_env		*env;
	t_data		*data;
	t_map		*map;
	t_cam		*cam;
	t_hero		*hero;
	t_enemy		**enemies;
	int			render_event;
	int			error_code;
	int			current_frame;
	char		padding[4];
}		t_state;

#endif
