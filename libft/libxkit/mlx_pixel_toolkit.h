/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_toolkit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:03:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/13 12:02:15 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PIXEL_TOOLKIT_H
# define MLX_PIXEL_TOOLKIT_H

# include "./libxkit.h"

/* Prototypes */
void	mlx_fast_pixel_put(t_img *img, int x, int y, int color);

#endif
