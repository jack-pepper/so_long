/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:27:53 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/11 08:48:44 by mmalie           ###   ########.fr       */
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
	int	*goal;

	score = &(state->data->collected);
	goal = &(state->data->to_be_collected);
	ft_printf("Found collectible!\n");
	(*score)++;
	state->map->tilemap[pos->y][pos->x] = '0';
	(state->map->tile_count[2])++;
	(state->map->tile_count[0])--;
	if ((*score == *goal / 4) || (*score == *goal / 2)
		|| *score == (*goal / 4) + (*goal / 2))
	{
		if (change_level(state) != 0)
			return ; // Need to change coll_tile() to int
	}
}

/* On exit position:
 * - win condition: all collectible have been collected
 * - if not reached: display a message
 */
void	on_exit_tile(t_state *state)
{
	if (state->data->collected == state->data->to_be_collected)
	{
		display_victory_screen();
		sl_memfree(state);
		ft_printf("[on_exit_tile] Free all! \n");
		exit(0);
	}
	else
		ft_printf("Keep searching!\n");
}

int	change_level(t_state *state)
{
	int	goal;

	goal = state->data->to_be_collected;
	sl_destroy_imgs(state);
	if (state->data->collected == goal / 4)
	{
		if (upload_assets_ice_lvl(state) != 0)
			return (1);
	}
	else if (state->data->collected == goal / 2)
	{
		if (upload_assets_sand_lvl(state) != 0)
			return (1);
	}
	else if (state->data->collected == (goal / 2) + (goal / 4))
	{
		if (upload_assets_pacman_lvl(state) != 0)
			return (1);
	}
	return (0);
}
