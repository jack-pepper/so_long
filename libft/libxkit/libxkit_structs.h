/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxkit_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:16:07 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/04 16:49:00 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXKIT_STRUCTS_H
# define LIBXKIT_STRUCTS_H

/* Env structs */
typedef struct s_pos
{
	int		x;
	int		y;
}		t_pos;

/* Redefinition from mlx_int.h */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_env
{
	t_img		*canvas;
	t_img		*bkgd_img;
	void		*mlx;
	void		*win;
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
	t_img		*sprite;
	t_pos		*pos;
	int			width;
	int			height;
}		t_tile;

typedef struct s_map
{
	char	*fpath;
	char	**tilemap;
	t_tile	**tileset;
	int		*tile_count;
	int		width;
	int		height;
	int		tm_rows;
	int		tm_cols;
	int		cell_width;
	int		cell_height;
	int		cell_size;
}		t_map;

// A counter and a requirement counter to compare it with by index.
typedef struct s_count_req
{
	int		count[6];
	int		req[6];
}		t_count_req;

typedef struct s_enemy
{
	void		*sprite;
	t_img		**frames;
	t_pos		*pos;
}		t_enemy;

typedef struct s_hero
{
	t_img		*sprite;
	t_img		**frames;
	t_pos		*pos;
}		t_hero;

typedef struct s_state
{
	t_env		*env;
	t_data		*data;
	t_map		*map;
	t_cam		*cam;
	t_hero		*hero;
	int			bkgd_event;
	int			map_event;
	int			hero_event;
	//t_mouse		*mouse;
}		t_state;

#endif
