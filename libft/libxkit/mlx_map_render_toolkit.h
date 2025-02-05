/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_render_toolkit.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:49:36 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/13 11:31:01 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MAP_RENDER_TOOLKIT_H
# define MLX_MAP_RENDER_TOOLKIT_H

# include "./libxkit.h"

void	render_map(t_state *state);
void	rm_put_tiles(t_state *state, int row, int col, int cell_size);

#endif
