/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_movement_toolkit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:03:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 21:21:29 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

/* For each direction, if next pos is not a wall, set the same sprite. 
 * Else, reverse direction.
 */

void	*move_to_left(t_state *state, t_enemy *enemy, void *enemy_sprite)
{
	if (state->map->tilemap[enemy->pos->y][enemy->pos->x - 1] != '1')
	{
		enemy_sprite = enemy->to_left;
		enemy->pos->x -= 1;
		enemy->frame = 3;
	}
	else
	{
		enemy->direction = 'r';
	}
	return (enemy_sprite);
}

void	*move_to_right(t_state *state, t_enemy *enemy, void *enemy_sprite)
{
	if (state->map->tilemap[enemy->pos->y][enemy->pos->x + 1] != '1')
	{
		enemy_sprite = enemy->to_right;
		enemy->pos->x += 1;
		enemy->frame = 4;
	}
	else
	{
		enemy->direction = 'l';
	}
	return (enemy_sprite);
}

void	*move_to_up(t_state *state, t_enemy *enemy, void *enemy_sprite)
{
	if (state->map->tilemap[enemy->pos->y - 1][enemy->pos->x] != '1')
	{
		enemy_sprite = enemy->to_up;
		enemy->pos->y -= 1;
		enemy->frame = 2;
	}
	else
	{
		enemy->direction = 'd';
	}
	return (enemy_sprite);
}

void	*move_to_down(t_state *state, t_enemy *enemy, void *enemy_sprite)
{
	if (state->map->tilemap[enemy->pos->y + 1][enemy->pos->x] != '1')
	{
		enemy_sprite = enemy->to_down;
		enemy->pos->y += 1;
		enemy->frame = 1;
	}
	else
	{
		enemy->direction = 'u';
	}
	return (enemy_sprite);
}
