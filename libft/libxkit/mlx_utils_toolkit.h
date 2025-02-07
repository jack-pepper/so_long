/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_toolkit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 00:54:41 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 10:51:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_TOOLKIT_H
# define MLX_UTILS_TOOLKIT_H

# include "./libxkit.h"

void	mlx_show(void *xvar, void *win, void *img, t_pos pos);
void	mlx_draw_to_canvas(t_img *canvas, t_img *sprite, t_pos pos);
int		ft_err(int return_val, char *error_msg);

#endif
