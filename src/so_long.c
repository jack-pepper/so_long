/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 14:56:36 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO [leak] when exit on map parsing errors. Seems to come from the
//		unfreed persistant stash in ft_gnl. extern is not allowed (global)
//	[norminette]
//	

#include "../inc/so_long.h"
/*
 * So_long uses my library LIBXKIT, based on the graphics library MiniLibX.
 * At the moment (01/2025) this engine handles 2D collecting top-view games.
 * LIBXKIT, though, can be used for various types of projects.
 */

void	display_start_screen(void)
{
	ft_printf("\033[1;32m");
	ft_printf(" ___     ___         _      ___    _  _    ___    \n");
	ft_printf("/ __|   / _ \\   o O | |    / _ \\  | \\| |  / __|   \n");
	ft_printf("\\__ \\  | (_) |  o   | |__ | (_) | | .` | | (_ |   \n");
	ft_printf("|___/   \\___/  [O]  |____| \\___/  |_|\\_|  \\___|   \n");
	ft_printf("_|'''''|_|'''''| {=|_|''''|_|''''|_|'''''|\n");
	ft_printf("\"`-0-0-'\"`-0-0-'./0'\"`-0-0-'\"`-0-0-'\"`-0-0-'     \n");
	ft_printf("\033[0m"); // Reset color
}

int	main(int argc, char **argv)
{
	t_state	*state;
	t_data	data;
	char	fpath[256];

	if (argc != 2)
		return (ft_err(1, "Error\nInvalid number of arguments (req: 1)\n"));
	if (init_state(&state) != 0)
		return (1); // return (EXIT_FAILURE) ?
	ft_strlcpy(fpath, argv[1], ft_strlen(argv[1]) + 1);
	init_data(state, &data);
	if ((init_map(state, fpath, ".ber") != 0) // Export to a function (to set different errors))
		|| (map_parser(state) != 0)
		|| (map_validator(state) != 0)
		|| (set_state(state) != 0))
	{
		{
			ft_printf("error code (%d)\n", state->error_code);
			sl_memfree(state);
			return (1);
		}
	}
	state->error_code = 5;
	display_start_screen();
	state->hero_event = 1;
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

int	map_parser(t_state *state)
{
	char	**tilemap;
	t_count_req	counter;
	size_t  line_len;
	size_t  nb_lines;
	int	i;

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
	//mlx_destroy_image(state->env->mlx, state->env->canvas->img);
	//state->env->canvas->img = mlx_new_image(state->env->mlx, WID_WIDTH, WID_LENGTH);
	
	if (state->hero_event == 1 || state->map_event == 1 || state->bkgd_event == 1)
	//if (state->map_event == 1 || state->bkgd_event == 1)
	{
		render_background(state);
		state->bkgd_event = 0;
		state->map_event = 1;
	}
	if (state->hero_event == 1 || state->map_event == 1)
	{
		render_map(state);
		state->map_event = 0;
		state->hero_event = 1;
	}
	if (state->hero_event == 1)
	{
		render_hero(state);
		update_render(state);
		state->hero_event = 0;
	}
	return (0);
}

void	update_render(t_state *state)
{
	t_pos	*pos;

	pos = state->hero->pos;
	if (state->map->tilemap[pos->y][pos->x] == 'C')
	{
		on_coll_tile(state, pos);
		state->map_event = 1;
	}
	else if (state->map->tilemap[pos->y][pos->x] == 'E')
	{
		on_exit_tile(state);
	}
}
