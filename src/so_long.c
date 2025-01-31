/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/31 12:02:02 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
 * My custom library LIBXKIT, based on the graphics library MiniLibX, allows
 * to modify the game settings with minimal effort:
 * - parsing map (rectangular only) with any extension, set and count.   
 * - 
 * At the moment (01/2025) this engine handles 2D collecting top-view games.
 * LIBXKIT, though, can be used for various types of projects.
 */

int	main(int argc, char **argv)
{
	t_state	*state;
	t_data	data;
	char	fpath[256];

	if (init_state(&state) != 0)
		return (1); // return (EXIT_FAILURE); : replace all
        if (argc != 2)
                return (ft_error(1, "Error\nInvalid number of arguments (req: 1)\n"));
        ft_strlcpy(fpath, argv[1], ft_strlen(argv[1]) + 1); // without + 1?
        ft_printf("FILEPATH: %s\n", fpath); // DEBUG
	if (init_data(state, &data) != 0)
		return (1);
	if ((init_map(state, fpath, ".ber") != 0) // Export to a function (to set different errors))
		|| (map_parser(state) != 0)
		|| (map_validator(state) != 0)
		|| (set_state(state) != 0))
		return (1);
	mlx_loop_hook(state->env->mlx, &render, state);
	mlx_loop(state->env->mlx);
	return (0);
}

int	init_data(t_state *state, t_data *data)
{
	data->collected = 0;
	data->nb_steps = 0;
	state->data = data;
	return (0);
}

int     map_parser(t_state *state)
{
        char	**tilemap;
	t_count_req	counter;
	size_t  line_len;
        size_t  nb_lines;
	int	i;
	
	set_counter_req(&counter);
	tilemap = state->map->tilemap;
        line_len = state->map->tm_cols;
        nb_lines = state->map->tm_rows;
        if (check_border(tilemap, line_len, nb_lines, '1') != 0)
                return (1);
        ft_printf("Map is closed\n"); // DEBUG
        if (check_chars(tilemap, nb_lines, "01CEP\n") != 0)
                return (1);
        ft_printf("Correct chars (req: 01CEP)\n"); // DEBUG
        if (check_count(tilemap, nb_lines, "01CEP\n", &counter) != 0) // Should the nl char be accepted?
                return (1);
        ft_printf("Correct counts (req: 0, 1, C>1, Ex1, Px1)\n"); // DEBUG 
	i = 0;
	while (i < 6)
	{
		state->map->tile_count[i] = counter.count[i];
		i++;
	}
	state->data->to_be_collected = counter.count[2];
	return (0);
}

// [0]=empty | [1]=wall | [2]=C (coll) | [3]=E (exit) | [4] =P (start pos)
/* For each index (matching counter index), 'required' expects: 
 * - if expected a precise value: a positive int (1 = only one)
 * - if expected a minimal value: a negative int (-1 = at least 1)
 * - 0 is considered positive (0 = not even one).
 * The counter array should be initialised to 0 beforehand.
 */
void	set_counter_req(t_count_req *counter)
{	
	int	count[6] = {0, 0, 0, 0, 0, 0};
	int	req_count[6] = {-1, -1, -1, 1, 1, -1};
	int	i;
	
	i = 0;
	while (i < 6)
	{	
		counter->count[i] = count[i];
		counter->req[i] = req_count[i];
		i++;
	}
	return;	
}

int	render(t_state *state)
{
	render_background(state);
	render_map(state);
	render_hero(state);
	update_render(state);
	return (0);
}

void	update_render(t_state *state)
{
	t_pos	*pos;
	
	pos = state->hero->pos;

	// DEBUG
	//ft_printf("coll: %d - tbc: %d\n", state->data->collected, state->data->to_be_collected);
	// END DEBUG
	if (state->map->tilemap[pos->y][pos->x])
	{
		
	}
        if (state->map->tilemap[pos->y][pos->x] == 'C')
        {
		on_coll_tile(state, pos);
        }
        else if (state->map->tilemap[pos->y][pos->x] == 'E')
		on_exit_tile(state);
}
