/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ai_toolkit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:42:47 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/10 22:50:26 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

int	init_enemy(t_state *state)
{
	t_enemy	*enemy;
	t_pos	*enemy_pos;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (1);
	state->enemy = enemy;
	enemy_pos = malloc(sizeof(t_pos));
	if (!enemy_pos)
		return (1);
	state->enemy->pos = enemy_pos;
	set_enemy_pos(state);
	return (0);
}

void	set_enemy_pos(t_state *state)
{
	int		row;
	int		col;

	row = 0;
	while (row < state->map->tm_rows)
	{
		col = 0;
		while (col < state->map->tm_cols)
		{
			if (state->map->tilemap[row][col] == 'P')
			{
				//state->enemy->pos->x = col;
				//state->enemy->pos->y = row;
				return ;
			}
			col++;
		}
		row++;
	}
	return ;
}
