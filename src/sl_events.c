/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:27:53 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 14:29:50 by mmalie           ###   ########.fr       */
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
int	on_coll_tile(t_state *state, t_pos *pos)
{
	int	*score;
	int	step;

	score = &state->data->collected;
	step = state->data->to_be_collected / 5;
	ft_printf("🪙 Found collectible!\n");
	(*score)++;
	state->map->tilemap[pos->y][pos->x] = '0';
	(state->map->tile_count[2])++;
	(state->map->tile_count[0])--;
	if ((*score == step * 1) || (*score == step * 2)
		|| (*score == step * 3) || (*score == (step * 4)))
	{
		if (change_level(state) != 0)
			return (1);
	}
	return (0);
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

void	on_enemy_tile(t_state *state)
{
	display_defeat_screen();
	sl_memfree(state);
	ft_printf("[on_enemy_tile] Be more careful next time! ☠️ \n");
	exit(0);
}

int	change_level(t_state *state)
{
	int	collected;
	int	step;
	int	res;

	collected = state->data->collected;
	step = state->data->to_be_collected / 5;
	sl_destroy_imgs(state);
	res = 0;
	if (collected >= step * 1 && collected < step * 2)
		res = upload_assets(state, PATH_ICE);
	else if (collected >= step * 2 && collected < (step * 3))
		res = upload_assets(state, PATH_SAND);
	else if (collected >= step * 3 && collected < (step * 4))
		res = upload_assets(state, PATH_PACMAN);
	else if (collected >= step * 4 && collected < (step * 5))
		res = upload_assets(state, PATH_MARIO);
	if (res != 0)
		return (1);
	return (0);
}

int	ls_bonus_check(char **argv)
{
	if ((ft_strncmp(argv[1], "maps/valid_map_so_long_bonus.ber",
				ft_strlen(argv[1])) != 0)
		&& (argv[1] && NB_ENEMIES != 0))
	{
		return (1);
	}
	if (NB_ENEMIES > 5)
	{
		return (1);
	}
	return (0);
}
