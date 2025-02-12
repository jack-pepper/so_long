/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 11:11:17 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: ADD FREEING EVENT FOR CTRL+C ???

#include "../inc/so_long.h"
/*
 * So_long uses my library LIBXKIT, based on the graphics library MiniLibX.
 * At the moment (01/2025) this engine handles 2D collecting top-view games.
 * LIBXKIT, though, can be used for various types of projects.
 */

int	main(int argc, char **argv)
{
	t_state	*state;
	t_data	data;
	char	fpath[256];

	if (argc != 2 || ls_bonus_check(argv))
		return (ft_err(1, "Error\n[main] Invalid input! ❌\n"));
	if (init_state(&state) != 0)
		return (1);
	ft_strlcpy(fpath, argv[1], ft_strlen(argv[1]) + 1);
	init_data(state, &data, 1);
	if ((init_map(state, fpath, ".ber") != 0) || (map_parser(state) != 0)
		|| (map_validator(state) != 0) || (set_state(state) != 0))
	{
		ft_printf("error code (%d)\n", state->error_code);
		sl_memfree(state);
		return (1);
	}
	display_start_screen();
	init_data(state, state->data, 2);
	if (NB_ENEMIES > 0)
		spawn_enemy(state);
	mlx_loop_hook(state->env->mlx, &render, state);
	mlx_loop(state->env->mlx);
	return (0);
}

int	init_data(t_state *state, t_data *data, int step)
{
	if (step == 1)
	{
		data->collected = 0;
		data->nb_steps = 0;
		state->data = data;
		state->current_frame = 0;
	}
	else if (step == 2)
	{
		state->error_code = 5;
		state->hero->frame = 0;
		if (NB_ENEMIES > 0)
			set_enemy_pos(state);
		state->render_event = 3;
	}
	return (0);
}

int	map_parser(t_state *state)
{
	char		**tilemap;
	t_count_req	counter;
	size_t		line_len;
	size_t		nb_lines;
	int			i;

	state->error_code = 2;
	set_counter_req(&counter);
	tilemap = state->map->tilemap;
	line_len = state->map->tm_cols;
	nb_lines = state->map->tm_rows;
	if (check_border(tilemap, line_len, nb_lines, '1') != 0)
		return (1);
	if (check_chars(tilemap, nb_lines, "01CEP\n") != 0)
		return (1);
	if (check_count(tilemap, nb_lines, "01CEP\n", &counter) != 0)
		return (1);
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
	int	count[6];
	int	req_count[6];
	int	i;

	req_count[0] = -1;
	req_count[1] = -1;
	req_count[2] = -1;
	req_count[3] = 1;
	req_count[4] = 1;
	req_count[5] = -1;
	ft_memset(count, 0, sizeof(count));
	i = 0;
	while (i < 5)
	{
		counter->count[i] = count[i];
		counter->req[i] = req_count[i];
		i++;
	}
	return ;
}

int	render(t_state *state)
{
	t_pos	*pos;

	if (state->current_frame == FRAME_RATE)
	{
		pos = state->hero->pos;
		render_background(state);
		render_map(state);
		render_hero(state);
		if (NB_ENEMIES > 0)
			render_enemy(state);
		display_steps_on_screen(state);
		if (state->map->tilemap[pos->y][pos->x] == 'C')
		{
			if (on_coll_tile(state, pos))
				return (1);
		}
		else if (state->map->tilemap[pos->y][pos->x] == 'E')
			on_exit_tile(state);
		else if ((NB_ENEMIES > 0)
			&& (check_coll_mult(pos, state->enemies, 0)))
			on_enemy_tile(state);
		state->render_event = 0; // Comment out?
	}
	else
		(state->current_frame)++;
	return (0);
}
