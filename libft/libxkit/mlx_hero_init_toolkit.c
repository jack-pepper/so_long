/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hero_init_toolkit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:52:17 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 21:23:13 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

int	init_hero(t_state *state)
{
	t_hero	*hero;
	t_pos	*hero_pos;

	hero = malloc(sizeof(t_hero));
	if (!hero)
		return (1);
	state->hero = hero;
	hero_pos = malloc(sizeof(t_pos));
	if (!hero_pos)
		return (1);
	state->hero->pos = hero_pos;
	set_hero_pos(state);
	return (0);
}

void	set_hero_pos(t_state *state)
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
				state->hero->pos->x = col;
				state->hero->pos->y = row;
				return ;
			}
			col++;
		}
		row++;
	}
	return ;
}
