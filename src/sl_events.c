/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:27:53 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/06 12:36:24 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
 * Sets events specific to the game So Long.
 */

/* On collecting a collectible:
 * - increment the number of items collected
 * - erase the collectible
 * - update the tile count
 */
void	on_coll_tile(t_state *state, t_pos *pos)
{
	int	*score;

	score = &(state->data->collected);
	ft_printf("Found collectible!\n");
	(*score)++;
	state->map->tilemap[pos->y][pos->x] = '0';
	(state->map->tile_count[2])++;
	(state->map->tile_count[0])--;
}

/* On exit position:
 * - win condition: all collectible have been collected
 * - if not reached: display a message
 */
void	on_exit_tile(t_state *state)
{
	if (state->data->collected == state->data->to_be_collected)
	{
		ft_printf("YOU WIN!\n");
		sl_memfree(state); // 
		ft_printf("[on_exit_tile] Free all! \n"); //
		exit(0);
	}
	else
		ft_printf("Keep searching!\n");
}

