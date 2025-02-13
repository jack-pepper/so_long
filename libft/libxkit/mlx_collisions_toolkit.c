/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_collisions_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:52:59 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 15:38:13 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

// Check collision on same tile
int	check_collision_tile(t_pos *p1, t_pos *p2)
{
	if ((p1->y == p2->y) && (p1->x == p2->x))
		return (1);
	else
		return (0);
}

// Check collision on same cell (radius 0) or adjacent cells (any direction)
int	check_collision_radius(t_pos *p1, t_pos *p2, int rad)
{
	if (rad == 0 || rad < 0)
	{
		if (check_collision_tile(p1, p2) == 1)
			return (1);
	}
	else
	{
		if (((p1->y == p2->y) && (p1->x == p2->x))
			|| ((p1->y == p2->y) && (p1->x + rad == p2->x))
			|| ((p1->y == p2->y) && (p1->x - rad == p2->x))
			|| ((p1->y + rad == p2->y) && (p1->x == p2->x))
			|| ((p1->y - rad == p2->y) && (p1->x == p2->x))
			|| ((p1->y + rad == p2->y) && (p1->x + rad == p2->x))
			|| ((p1->y - rad == p2->y) && (p1->x - rad == p2->x))
			|| ((p1->y + rad == p2->y) && (p1->x - rad == p2->x))
			|| ((p1->y - rad == p2->y) && (p1->x + rad == p2->x)))
			return (1);
	}
	return (0);
}

int	check_coll_mult(t_pos *p1, t_enemy **enemies, int rad)
{
	int	i;

	i = 0;
	while (i < NB_ENEMIES)
	{
		if (check_collision_radius(p1, enemies[i]->pos, rad) == 1)
			return (1);
		i++;
	}
	return (0);
}
