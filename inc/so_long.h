/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/09 10:40:05 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 1620
# define WIN_HEIGHT 780

/* External libraries */
# include <errno.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>


# include "../lib/libft/libft.h"
# include "../lib/libxkit/libxkit.h"

# include "assets.h"

/* Main structs */

/*
typedef struct	s_assets
{
	t_img	*bkgd;
	t_img	*block;
	t_img	*token;
	t_img	*exit;
	t_img	*hero;	
}		t_assets;
*/



typedef struct	s_state
{
	int	is_running;
	int	score;
}		t_state;

typedef struct	s_tile
{
	void	*sprite;
	t_pos	*pos;
	int	width;
	int	height;
}		t_tile;

typedef struct	s_map
{
	char	**tilemap;
	char	*fpath;
	size_t	tm_rows;
	size_t	tm_cols;
	int	width;
	int	height;
	int	cell_width;
	int	cell_height;
	int	cell_size;
	t_img	*background;
	t_tile	*wall;
	t_tile	*coll;
	t_tile	*exit;
}		t_map;

typedef struct	s_hero
{
	void	*sprite;
	t_pos	*pos;
}		t_hero;

typedef struct	s_game
{
	t_env	*env;
	t_state	*state;
	t_map	*map;
	t_hero	*hero;
}		t_game;

/* Custom libraries */
# include "../lib/libxkit/mlx_draw_toolkit.h"
# include "../lib/libxkit/mlx_color_toolkit.h"

#include "./initer.h"
#include "./event_handler.h"
#include "./map_parser.h"
#include "./map_validator.h"
#include "./renderer.h"

int     win_close(int keysym, t_env *env);


int     map_parser(t_game *game, int argc, char **argv);
int	init_map(t_game *game, char *fpath, size_t line_len, size_t nb_lines);
int     init_game(t_game *game);

// flood fill


// Assets (name and path:)
//char	*tile;
//tile = 4_Seasons_Ground_Tiles.xpm

#endif
