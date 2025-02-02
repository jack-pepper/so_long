/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:40:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/02 15:02:43 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Free arr and each element
void    sl_free_all(char **arr)
{
        int     i;

        if (arr == NULL)
                return ;
        i = 0;
        while (arr[i] != NULL)
        {
                free(arr[i]);
                i++;
        }
        free(arr);
        return ;
}


char	**copy_map(char **src, t_pos size)
{
	char	**copy;
	int	i;

	copy = malloc(sizeof(char *) * (size.y + 1));
	if (!copy)
		return (NULL);
	i = 0;
    	while (i < size.y)
	{
        	copy[i] = malloc(size.x * sizeof(char));
		if(!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		ft_memcpy(copy[i], src[i], size.x * sizeof(char));
		i++;
	}
	ft_printf("[copy_map] copy success!\n"); // DEBUG
	copy[i] = NULL;
	return	(copy);
}

void	set_start_pos(t_state *state, t_pos *start_pos)
{
	int     row;
	int     col;

        row = 0;
        col = 0;
        while (row < state->map->tm_rows)
        {
                col = 0;
                while (col < state->map->tm_cols)
                {
                        if (state->map->tilemap[row][col] == 'P')
                        {
                                start_pos->x = col;
                                start_pos->y = row;
                                ft_printf("start_pos: y(row)=%d - x(col)=%d\n", start_pos->y, start_pos->x); // DEBUG
                                return ;
                        }
                        col++;
                }
                row++;
        }
        return ;
}

// accessed_count[0] = collectibles / [1] = exit
int	map_validator(t_state *state)
{
	t_pos	map_size;
	t_pos	start_pos;
	int	accessed_count[2] = {0, 0};
	char	**map_copy;

	map_size.x = state->map->tm_cols;
	map_size.y = state->map->tm_rows;
	
	map_copy = copy_map(state->map->tilemap, map_size);
	if (!map_copy)
		return (1);
	ft_printf("[map_validator] map_copy success: %c!\n", map_copy[3][1]); // DEBUG
	set_start_pos(state, &start_pos);

	ft_printf("[BEFORE FLOOD] accessed: %d coll, %d exit | required: %d coll, %d exit\n", accessed_count[0], accessed_count[1], state->map->tile_count[2], state->map->tile_count[3]);

	flood_count(map_copy, map_size, start_pos, accessed_count);
	ft_printf("[AFTER FLOOD] accessed: %d coll, %d exit | required: %d coll, %d exit\n", accessed_count[0], accessed_count[1], state->map->tile_count[2], state->map->tile_count[3]);

	if ((accessed_count[0] == state->map->tile_count[2])
		&& (accessed_count[1] == state->map->tile_count[3]))
	{
		sl_free_all(map_copy);
		return (0);
	}
	sl_free_all(map_copy);
	return (1);
}

void	flood_count(char **tab, t_pos size, t_pos begin, int accessed_count[2])
{
	t_pos	p;

	if (begin.y > 0 && tab[begin.y - 1][begin.x] != '1')
	{
		p.y = begin.y - 1;
		p.x = begin.x;
		update_flood_count(tab[p.y][p.x], accessed_count);
		tab[p.y][p.x] = '1';
		flood_count(tab, size, p, accessed_count);
	}
	if (begin.y < (size.y - 1) && tab[begin.y + 1][begin.x] != '1')
	{
		p.y = begin.y + 1;
		p.x = begin.x;
		update_flood_count(tab[p.y][p.x], accessed_count);
		tab[p.y][p.x] = '1';
		flood_count(tab, size, p, accessed_count);
	}
	if (begin.x > 0 && tab[begin.y][begin.x - 1] != '1')
	{
		p.y = begin.y;
		p.x = begin.x - 1;
		update_flood_count(tab[p.y][p.x], accessed_count);	
		tab[p.y][p.x] = '1';
		flood_count(tab, size, p, accessed_count);
	}
	if (begin.x < (size.x - 1) && tab[begin.y][begin.x + 1] != '1')
	{
		p.y = begin.y;
		p.x = begin.x + 1;
		update_flood_count(tab[p.y][p.x], accessed_count);
		tab[p.y][p.x] = '1';
		flood_count(tab, size, p, accessed_count);
	}
}


void	update_flood_count(char tile, int accessed_count[2])
{

	if (tile == 'C')
	{
		accessed_count[0] += 1;
	}
	else if (tile == 'E')
	{
		accessed_count[1] += 1;
	}
}
