/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:30 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/27 17:42:24 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_X 1620
# define WIN_Y 780

/* External libraries */
# include <math.h>
# include "./minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Main structs */
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

/* Custom libraries */
# include "./libft/libft.h"
# include "mlx_draw_toolkit.h"
# include "mlx_color_toolkit.h"

int     win_close(int keysym, t_vars *vars);

// event_handler.c
int on_keypress(int keysym, t_vars *vars);
int on_destroy(t_vars *vars);

void	set_hooks(t_vars *vars);


// Assets (name and path:)
//char	*tile;
//tile = 4_Seasons_Ground_Tiles.xpm

#endif
