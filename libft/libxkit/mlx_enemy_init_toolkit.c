/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_init_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:42:47 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/11 22:46:18 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	set_enemy_pos(t_state *state)
{
	state->map->tilemap[6][9] = 'M';
//	state->map->tilemap[8][12] = 'M';
//	state->map->tilemap[10][4] = 'M';
//	state->map->tilemap[12][10] = 'M';
}

// Enemy hardcoded here to use only allowed functions
int	init_enemy(t_state *state, int nb_enemies)
{
	t_enemy	*enemy;
	t_pos	*enemy_pos;
	int		i;

	state->enemies = malloc(sizeof(t_enemy) * (nb_enemies + 1));
	if (!state->enemies)
		return (1);
	i = 0;
	while (i < nb_enemies)
	{
		enemy = malloc(sizeof(t_enemy));
		if (!enemy)
			return (1);
		state->enemies[i] = enemy;
		enemy_pos = malloc(sizeof(t_pos));
		if (!enemy_pos)
			return (1);
		state->enemies[i]->pos = enemy_pos;
		state->enemies[i]->frame = 0;
		i++;
	}
	state->enemies[i] = NULL;
	return (0);
}

void	spawn_enemy(t_state *state)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	set_enemy_pos(state);
	row = 0;
	while (row < state->map->tm_rows)
	{
		col = 0;
		while (col < state->map->tm_cols)
		{
			if (state->map->tilemap[row][col] == 'M')
			{
				state->enemies[i]->pos->x = col;
				state->enemies[i]->pos->y = row;
				i++;
			}
			col++;
		}
		row++;
	}
	return ;
}
