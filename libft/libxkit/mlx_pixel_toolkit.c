/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_toolkit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 14:08:46 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	mlx_fast_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pix;

	if ((x >= 0 && x < img->width) && (y >= 0 && y < img->height))
	{
		pix = img->addr + (y * img->l_len) + (x * (img->bpp / 8));
		*(unsigned int *)pix = color;
	}
}

/* For testing purposes */
/*
        // Draw a pixel
        //mlx_pixel_put(env.mlx, env.win, WIN_X/2, WIN_Y/2, 0xFFFFFF);
        //mlx_fast_pixel_put(&img, 5, 5, 0x00FF0000);
        //t_mlx_line line = {0, 0, WIN_X, WIN_Y};
        
        t_mlx_line line;
        line.start_x = 0;
        line.start_y = 0;
        line.end_x = WIN_X;
        line.end_y = WIN_Y;
        draw_mlx_line(&env, &line);

        t_mlx_circle circle;
        circle.center_x = WIN_X/2;
        circle.center_y = WIN_Y/2;
        circle.radius = 50;
        draw_mlx_circle(&env, &circle);
        
        // TESTS
        int     i;

        i = 0;
        while (i < 500)
        {
                t_mlx_rect rect;
                rect.origin_x = 10 + i;
                rect.origin_y = 10 + i;
                rect.length = WIN_X - 20;
                rect.width = WIN_Y - 20;
                draw_mlx_rect(&env, &rect);
                i += 2;
        }
        // Display a string
        //mlx_string_put(env.mlx, env.win, 100, 100, 0xFFFFFF, "COUNTER");      
*/
