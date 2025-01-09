/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:40:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/09 12:07:46 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_validator(t_game *game)
{
	t_pos map_size;
	char	**map_copy;

	map_copy = game->map->tilemap;
	map_size.x = game->map->tm_cols;
	map_size.y = game->map->tm_rows;

	flood_count(map_copy, map_size, game->hero->pos);

	// The algo should modify all chars EXCEPT the walls. Then we check whether all the P, C, E have been modified
	// Or... I can count them instead and compare?

	if ()
	{
	}

	free(map_copy);
	return (0);
}

void	flood_count(char **tab, t_pos size, t_pos begin)
{
	char	c;
	t_pos	p;

	c = tab[begin.y][begin.x];
	i = 0;	

	if (begin.y > 0 && tab[begin.y - 1][begin.x] != '1')
	{
		p.y = begin.y - 1;
		p.x = begin.x;
		flood_count(tab, size, p);
	}
	if (begin.y < (size.y - 1) && tab[begin.y + 1][begin.x] != '1')
	{
		p.y = begin.y + 1;
		p.x = begin.x;
		flood_count(tab, size, p);
	}
	if (begin.x > 0 && tab[begin.y][begin.x - 1] != '1')
	{
		p.y = begin.y;
		p.x = begin.x - 1;
		flood_count(tab, size, p);
	}
	if (begin.x < (size.x - 1) && tab[begin.y][begin.x + 1] != '1')
	{
		p.y = begin.y;
		p.x = begin.x + 1;
		flood_count(tab, size, p);
	}
}
