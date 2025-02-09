/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_validator_toolkit.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:30:36 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 21:35:39 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MAP_VALIDATOR_TOOLKIT_H
# define MLX_MAP_VALIDATOR_TOOLKIT_H

# include "./libxkit.h"

char	**copy_map(char **src, t_pos size);
void	set_start_pos(t_state *state, t_pos *start_pos);
int		map_validator(t_state *state);
void	update_flood_count(char tile, int reached[2]);

#endif
