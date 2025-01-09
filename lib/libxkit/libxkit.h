/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxkit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:16:07 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/09 15:07:14 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXKIT_H
# define LIBXKIT_H

# define WIN_X 1620
# define WIN_Y 780

# define RES_PIX 64

/* Env structs */
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
        t_img           *canvas;
        void            *mlx;
        void            *win;
        int             canvas_width;
        int             canvas_height;
}               t_env;

/* Standard libraries */
# include <stdlib.h>
# include <math.h>
# include "./minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Custom libraries */
//# include "../libft.h"
# include "./mlx_color_toolkit.h"
# include "./mlx_draw_toolkit.h"

#endif
