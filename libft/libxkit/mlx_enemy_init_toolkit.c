/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_init_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:42:47 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 09:45:23 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	set_enemy_pos(t_state *state)
{
	if (NB_ENEMIES >= 1)
		state->map->tilemap[6][9] = 'M';
	if (NB_ENEMIES >= 2)
		state->map->tilemap[8][11] = 'M';
	if (NB_ENEMIES >= 3)
		state->map->tilemap[10][13] = 'M';
	if (NB_ENEMIES >= 4)
		state->map->tilemap[4][5] = 'M';
	if (NB_ENEMIES == 5)
		state->map->tilemap[7][3] = 'M';
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
	return (0);
}

void	spawn_enemy(t_state *state)
{
	int		row;
	int		col;
	int		i;

	i = 0;
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
