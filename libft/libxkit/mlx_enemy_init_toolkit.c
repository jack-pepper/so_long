/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_init_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:42:47 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 13:56:38 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

// Enemy hardcoded here to use only allowed functions
int	init_enemy(t_state *state, int nb_enemies)
{
	t_enemy	*enemy;
	t_pos	*enemy_pos;
	int		i;

	state->enemies = malloc(sizeof(t_enemy) * (nb_enemies));
	if (!state->enemies)
		return (1);
	i = 0;
	while (i < nb_enemies)
	{
		enemy = malloc(sizeof(t_enemy));
		if (!enemy)
			return (1);
		state->enemies[i] = enemy;
		enemy_pos = malloc(sizeof(t_pos));
		if (!enemy_pos)
			return (1);
		state->enemies[i]->pos = enemy_pos;
		set_enemy_data(state->enemies[i]);
		i++;
	}
	return (0);
}

int	upload_enemy(t_state *state, int nb_enemies)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	while (i < nb_enemies)
	{
		state->enemies[i]->to_up = mlx_xpm_file_to_image(state->env->mlx,
				state->enemies[i]->to_up_path, &width, &height);
		state->enemies[i]->to_down = mlx_xpm_file_to_image(state->env->mlx,
				state->enemies[i]->to_down_path, &width, &height);
		state->enemies[i]->to_left = mlx_xpm_file_to_image(state->env->mlx,
				state->enemies[i]->to_left_path, &width, &height);
		state->enemies[i]->to_right = mlx_xpm_file_to_image(state->env->mlx,
				state->enemies[i]->to_right_path, &width, &height);
		if (!state->enemies[i]->to_up || !state->enemies[i]->to_down
			|| !state->enemies[i]->to_left || !state->enemies[i]->to_right)
			return (1);
		state->enemies[i]->current_sprite = state->enemies[i]->to_down;
		i++;
	}
	return (0);
}

void	set_enemy_pos(t_state *state)
{
	if (NB_ENEMIES >= 1)
		state->map->tilemap[6][13] = 'M';
	if (NB_ENEMIES >= 2)
		state->map->tilemap[12][24] = 'M';
	if (NB_ENEMIES >= 3)
		state->map->tilemap[9][42] = 'M';
	if (NB_ENEMIES >= 4)
		state->map->tilemap[17][42] = 'M';
	if (NB_ENEMIES == 5)
		state->map->tilemap[20][20] = 'M';
}

void	set_enemy_data(t_enemy *enemy)
{
	static int	i = 0;

	enemy->frame = 1;
	if (i % 2 == 0)
	{
		if (i % 3 == 0)
			enemy->direction = 'r';
		else
			enemy->direction = 'l';
	}
	else
	{
		if (i % 3 == 0)
			enemy->direction = 'd';
		else
			enemy->direction = 'u';
	}
	enemy->amplitude = 10;
	i++;
}

void	spawn_enemy(t_state *state)
{
	int		row;
	int		col;
	int		i;

	i = 0;
	row = 0;
	while (row < state->map->tm_rows)
	{
		col = 0;
		while (col < state->map->tm_cols)
		{
			if (state->map->tilemap[row][col] == 'M')
			{
				state->enemies[i]->pos->x = col;
				state->enemies[i]->pos->y = row;
				state->enemies[i]->current_sprite = state->enemies[i]->to_down;
				i++;
			}
			col++;
		}
		row++;
	}
	return ;
}
