/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_toolkit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:49:05 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 18:58:19 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_utils_toolkit.h"

/* The name "mlx_put_image_to_window" with 5 parameters is too long to display.
 * To respect the 42 Norm, this function reduces its length by 15 characters.
 */
void	mlx_show(t_xvar *xvar, t_win_list *win, XImage *img, t_pos pos)
{
	mlx_put_image_to_window(xvar, win, img, pos.x, pos.y);
}

int	ft_error(int return_val, char *error_msg)
{
	perror(error_msg);
	return (return_val);
}
