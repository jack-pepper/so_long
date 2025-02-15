/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_toolkit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:49:05 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/15 21:02:49 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

/* The name "mlx_put_image_to_window" with 5 parameters is too long to display.
 * To respect the 42 Norm, this function reduces its length by 15 characters.
 */
void	mlx_show(void *xvar, void *win, void *img, t_pos pos)
{
	mlx_put_image_to_window(xvar, win, img, pos.x, pos.y);
}

int	ft_err(int return_val, char *error_msg)
{
	perror(error_msg);
	return (return_val);
}

char	*join_path(char *level, char *file)
{
	char	*fullpath;

	fullpath = ft_strjoin(level, file);
	return (fullpath);
}
