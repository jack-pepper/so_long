/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_validator_flood_count.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:30:36 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 22:51:11 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MAP_VALIDATOR_FLOOD_COUNT_H
# define MLX_MAP_VALIDATOR_FLOOD_COUNT_H

# include "./libxkit.h"

void	flood_count(char **tab, t_pos size, t_pos begin, int reached[2]);
void	flood_count_up(char **tab, t_pos size, t_pos begin, int reached[2]);
void	flood_count_down(char **tab, t_pos size, t_pos begin, int reached[2]);
void	flood_count_left(char **tab, t_pos size, t_pos begin, int reached[2]);
void	flood_count_right(char **tab, t_pos size, t_pos begin, int reached[2]);

#endif
