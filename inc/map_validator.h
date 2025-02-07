/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:51:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 15:43:56 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATOR_H
# define MAP_VALIDATOR_H

int		map_validator(t_state *state);
void	flood_count(char **tab, t_pos size, t_pos begin, int reached[2]);
void	update_flood_count(char tile, int reached[2]);

#endif
