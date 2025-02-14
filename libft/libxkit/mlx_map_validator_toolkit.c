/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_validator_toolkit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:40:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/15 00:28:32 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

char	**copy_map(char **src, t_pos size)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (size.y + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size.y)
	{
		copy[i] = malloc(size.x * sizeof(char));
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		ft_memcpy(copy[i], src[i], size.x * sizeof(char));
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	set_start_pos(t_state *state, t_pos *start_pos)
{
	int	row;
	int	col;

	row = 0;
	while (row < state->map->tm_rows)
	{
		col = 0;
		while (col < state->map->tm_cols)
		{
			if (state->map->tilemap[row][col] == 'P')
			{
				start_pos->x = col;
				start_pos->y = row;
				ft_printf("👣 [set_start_pos]: x: %d - y: %d\n",
					start_pos->x, start_pos->y);
				return ;
			}
			col++;
		}
		row++;
	}
	return ;
}

// reached[0] = collectibles / [1] = exit
int	map_validator(t_state *state)
{
	char		**map_copy;
	t_pos		map_size;
	t_pos		start_pos;
	int			reached[2];

	state->error_code = 3;
	ft_memset(reached, 0, sizeof(int) * 2);
	map_size.x = state->map->tm_cols;
	map_size.y = state->map->tm_rows;
	map_copy = copy_map(state->map->tilemap, map_size);
	if (!map_copy)
		return (1);
	set_start_pos(state, &start_pos);
	flood_count(map_copy, map_size, start_pos, reached);
	ft_printf("🌊 [map_validator] reachable: %d/%d coll, %d/%d exit\n",
		reached[0], state->map->tile_count[2],
		reached[1], state->map->tile_count[3]);
	if ((reached[0] == state->map->tile_count[2])
		&& (reached[1] == state->map->tile_count[3]))
	{
		sl_free_all(map_copy);
		return (0);
	}
	sl_free_all(map_copy);
	return (ft_err(1, "Error\nthe map has no valid path\n"));
}

void	update_flood_count(char tile, int reached[2])
{
	if (tile == 'C')
	{
		reached[0] += 1;
	}
	else if (tile == 'E')
	{
		reached[1] += 1;
	}
}
