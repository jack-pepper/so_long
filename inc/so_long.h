/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:30 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/31 00:38:27 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_X 1620
# define WIN_Y 780

/* External libraries */
# include <math.h>
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>


# include "assets.h"

/* Main structs */

typedef struct	s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct  s_img
{
        void    *img;
        char    *addr;
        int     bpp;
        int     l_len;
        int     endian;
}               t_img;

typedef struct  s_env
{
        t_img		*canvas;
	void    	*mlx;
        void    	*win;
	int		canvas_width;
	int		canvas_height;
}               t_env;

/*typedef struct	s_assets
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
	int	width;
	int	height;
}		t_tile;

typedef struct	s_map
{
	char	**tiles;
	int	width;
	int	height;
	t_img	*background;
	t_tile	*wall;
	t_tile	*coll;
	t_tile	*exit;
}		t_map;

typedef struct	s_hero
{
	void	*sprite;
	t_pos	pos;
}		t_hero;

typedef struct	s_game
{
	t_env	*env;
	t_state	*state;
	t_map	*map;
	t_hero	*hero;
}		t_game;

/* Custom libraries */
# include "../lib/libft/libft.h"
# include "../lib/libxkit/mlx_draw_toolkit.h"
# include "../lib/libxkit/mlx_color_toolkit.h"


#include "./rendering.h"


int     win_close(int keysym, t_env *env);

// event_handler.c
int on_keypress(int keysym, t_env *env);
int on_destroy(t_env *env);

void	set_hooks(t_env *env);
void	set_canvas(t_env *env);
void	set_map(t_game *game);
void    upload_assets(t_game *game);

int		check_extension(char *filepath, char *extension);


// Assets (name and path:)
//char	*tile;
//tile = 4_Seasons_Ground_Tiles.xpm

#endif
