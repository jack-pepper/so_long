/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_toolkit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:49:05 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/04 16:39:11 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_utils_toolkit.h"

/* The name "mlx_put_image_to_window" with 5 parameters is too long to display.
 * To respect the 42 Norm, this function reduces its length by 15 characters.
 */
void	mlx_show(void *xvar, void *win, void *img, t_pos pos)
{
	mlx_put_image_to_window(xvar, win, img, pos.x, pos.y);
}

int	ft_error(int return_val, char *error_msg)
{
	perror(error_msg);
	return (return_val);
}

void mlx_draw_to_canvas(t_img *canvas, t_img *sprite, t_pos pos)
{
    int x, y;
    char *dst, *src;

    if (!canvas || !sprite || !canvas->addr || !sprite->addr)
    {
        ft_printf("Error: Uninitialized canvas or sprite in mlx_draw_to_canvas\n");
        return;
    }

    // Copy pixel data from sprite to canvas
    for (y = 0; y < sprite->height; y++)
    {
        for (x = 0; x < sprite->width; x++)
        {
            // Compute memory addresses
            src = sprite->addr + (y * sprite->l_len + x * (sprite->bpp / 8));
            dst = canvas->addr + ((pos.y + y) * canvas->l_len + (pos.x + x) * (canvas->bpp / 8));

            // Copy pixel
            *(unsigned int *)dst = *(unsigned int *)src;
        }
    }
}

