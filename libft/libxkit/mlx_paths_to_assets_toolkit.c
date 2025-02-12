/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_paths_to_assets_toolkit.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:36:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 23:03:48 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

int	load_paths(t_state *state, char *level)
{
	if (load_paths_tiles(state, level) != 0)
		return (1);
	if (load_paths_hero(state, level) != 0)
		return (1);
	if (load_paths_enemy(state, level) != 0)
		return (1);
	return (0);
}

int	load_paths_tiles(t_state *state, char *level)
{
	state->env->bkgd_path = join_path(level, BKGD);
	state->map->wall->path = join_path(level, WALL);
	state->map->coll->path = join_path(level, COLL);
	state->map->exit->path = join_path(level, EXIT);
	if (!state->env->bkgd_path || !state->map->wall->path
		|| !state->map->coll->path || !state->map->exit->path)
		return (1);
	return (0);
}

int	load_paths_hero(t_state *state, char *level)
{
	state->hero->img_path = join_path(level, HERO);
	state->hero->to_up_path = join_path(level, HERO_TO_UP);
	state->hero->to_down_path = join_path(level, HERO_TO_DOWN);
	state->hero->to_left_path = join_path(level, HERO_TO_LEFT);
	state->hero->to_right_path = join_path(level, HERO_TO_RIGHT);
	if (!state->hero->img_path || !state->hero->to_up_path
		|| !state->hero->to_down_path || !state->hero->to_left_path
		|| !state->hero->to_right_path)
		return (1);
	return (0);
}

int	load_paths_enemy(t_state *state, char *level)
{
	int	i;

	i = 0;
	if (NB_ENEMIES > 0)
	{
		while (i < NB_ENEMIES)
		{
			state->enemies[i]->to_up_path = join_path(level, ENEMY_TO_UP);
			state->enemies[i]->to_down_path = join_path(level, ENEMY_TO_DOWN);
			state->enemies[i]->to_left_path = join_path(level, ENEMY_TO_LEFT);
			state->enemies[i]->to_right_path = join_path(level, ENEMY_TO_RIGHT);
			if (!state->enemies[i]->to_up_path
				|| !state->enemies[i]->to_down_path
				|| !state->enemies[i]->to_left_path
				|| !state->enemies[i]->to_right_path)
				return (1);
			i++;
		}
	}
	return (0);
}

void	free_paths(t_state *state)
{
	int	i;

	i = 0;
	free(state->env->bkgd_path);
	free(state->map->wall->path);
	free(state->map->coll->path);
	free(state->map->exit->path);
	free(state->hero->img_path);
	free(state->hero->to_up_path);
	free(state->hero->to_down_path);
	free(state->hero->to_left_path);
	free(state->hero->to_right_path);
	if (NB_ENEMIES > 0)
	{
		while (i < NB_ENEMIES)
		{
			free(state->enemies[i]->to_up_path);
			free(state->enemies[i]->to_down_path);
			free(state->enemies[i]->to_left_path);
			free(state->enemies[i]->to_right_path);
			i++;
		}
	}
}
