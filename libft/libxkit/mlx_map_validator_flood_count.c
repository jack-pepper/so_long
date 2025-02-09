/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_validator_flood_count.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:40:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 21:41:46 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	flood_count(char **tab, t_pos size, t_pos begin, int reached[2])
{
	if (begin.y > 0 && tab[begin.y - 1][begin.x] != '1')
		flood_count_up(tab, size, begin, reached);
	if (begin.y < (size.y - 1) && tab[begin.y + 1][begin.x] != '1')
		flood_count_down(tab, size, begin, reached);
	if (begin.x > 0 && tab[begin.y][begin.x - 1] != '1')
		flood_count_left(tab, size, begin, reached);
	if (begin.x < (size.x - 1) && tab[begin.y][begin.x + 1] != '1')
		flood_count_right(tab, size, begin, reached);
}

void	flood_count_up(char **tab, t_pos size, t_pos begin, int reached[2])
{
	t_pos	p;

	p.y = begin.y - 1;
	p.x = begin.x;
	update_flood_count(tab[p.y][p.x], reached);
	tab[p.y][p.x] = '1';
	flood_count(tab, size, p, reached);
}

void	flood_count_down(char **tab, t_pos size, t_pos begin, int reached[2])
{
	t_pos	p;

	p.y = begin.y + 1;
	p.x = begin.x;
	update_flood_count(tab[p.y][p.x], reached);
	tab[p.y][p.x] = '1';
	flood_count(tab, size, p, reached);
}

void	flood_count_left(char **tab, t_pos size, t_pos begin, int reached[2])
{
	t_pos	p;

	p.y = begin.y;
	p.x = begin.x - 1;
	update_flood_count(tab[p.y][p.x], reached);
	tab[p.y][p.x] = '1';
	flood_count(tab, size, p, reached);
}

void	flood_count_right(char **tab, t_pos size, t_pos begin, int reached[2])
{
	t_pos	p;

	p.y = begin.y;
	p.x = begin.x + 1;
	update_flood_count(tab[p.y][p.x], reached);
	tab[p.y][p.x] = '1';
	flood_count(tab, size, p, reached);
}
