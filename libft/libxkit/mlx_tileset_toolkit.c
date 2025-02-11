/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tileset_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:36:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/11 22:35:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

int	set_map(t_state *state)
{
	t_map	*map;

	map = state->map;
	map->wall = malloc (sizeof(t_tile));
	if (!map->wall)
		return (1);
	map->coll = malloc (sizeof(t_tile));
	if (!map->coll)
		return (1);
	map->exit = malloc (sizeof(t_tile));
	if (!map->exit)
		return (1);
	if (init_hero(state) != 0)
		return (1);
	if (NB_ENEMIES > 0)
	{
		if (init_enemy(state, NB_ENEMIES) != 0)
			return (1);
	}
//		return (1);
/*	state->map->width = WIN_WIDTH;
	state->map->height = WIN_HEIGHT;
	state->map->wall->width = WALL_WIDTH;
	state->map->wall->height = WALL_HEIGHT;
	state->map->coll->width = COLL_WIDTH;
	state->map->coll->height = COLL_HEIGHT;
	state->map->exit->width = EXIT_WIDTH;
	state->map->exit->height = EXIT_HEIGHT; */
	return (0);
}

int	load_paths(t_state *state, char *level)
{
	state->env->bkgd_path = join_path(level, BKGD);
	state->map->wall->path = join_path(level, WALL);
	state->map->coll->path = join_path(level, COLL);
	state->map->exit->path = join_path(level, EXIT);
	if (!state->env->bkgd_path || !state->map->wall->path
		|| !state->map->coll->path || !state->map->exit->path)
		return (1);
	state->hero->img_path = join_path(level, HERO);
	state->hero->to_up_path = join_path(level, HERO_TO_UP);
	state->hero->to_down_path = join_path(level, HERO_TO_DOWN);
	state->hero->to_left_path = join_path(level, HERO_TO_LEFT);
	state->hero->to_right_path = join_path(level, HERO_TO_RIGHT);
	if (!state->hero->img_path || !state->hero->to_up_path
		|| !state->hero->to_down_path || !state->hero->to_left_path
		|| !state->hero->to_right_path)
		return (1);
	
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
			if (!state->enemies[i]->to_up_path || !state->enemies[i]->to_down_path
				|| !state->enemies[i]->to_left_path
				|| !state->enemies[i]->to_right_path)	
			return (1);
			i++;
		}
	}
	return (0);
}

int	upload_assets(t_state *state, char *level)
{
	int	width;
	int	height;

	if (load_paths(state, level) != 0)
		return (1);
	state->env->bkgd_img = mlx_xpm_file_to_image(state->env->mlx,
			state->env->bkgd_path, &width, &height);
	state->map->wall->img = mlx_xpm_file_to_image(state->env->mlx,
			state->map->wall->path, &width, &height);
	state->map->coll->img = mlx_xpm_file_to_image(state->env->mlx,
			state->map->coll->path, &width, &height);
	state->map->exit->img = mlx_xpm_file_to_image(state->env->mlx,
			state->map->exit->path, &width, &height);
	if (!state->env->bkgd_img || !state->map->wall->img
		|| !state->map->coll->img || !state->map->exit->img)
		return (1);
	if (upload_hero(state) != 0)
		return (1);
	if (NB_ENEMIES > 0)
	{
		if (upload_enemy(state, NB_ENEMIES) != 0)
			return (1);
	}
	free_paths(state);
	return (0);
}

int	upload_hero(t_state *state)
{
	int	width;
	int	height;

	state->hero->img = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->img_path, &width, &height);
	if (!state->hero->img)
		return (1);
	state->hero->to_up = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->to_up_path, &width, &height);
	if (!state->hero->to_up)
		return (1);
	state->hero->to_down = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->to_down_path, &width, &height);
	if (!state->hero->to_down)
		return (1);
	state->hero->to_left = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->to_left_path, &width, &height);
	if (!state->hero->to_left)
		return (1);
	state->hero->to_right = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->to_right_path, &width, &height);
	if (!state->hero->to_right)
		return (1);
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
		if (!state->enemies[i]->to_up)
			return (1);
		state->enemies[i]->to_down = mlx_xpm_file_to_image(state->env->mlx,
				state->enemies[i]->to_down_path, &width, &height);
		if (!state->enemies[i]->to_down)
			return (1);
		state->enemies[i]->to_left = mlx_xpm_file_to_image(state->env->mlx,
				state->enemies[i]->to_left_path, &width, &height);
		if (!state->enemies[i]->to_left)
			return (1);
		state->enemies[i]->to_right = mlx_xpm_file_to_image(state->env->mlx,
				state->enemies[i]->to_right_path, &width, &height);
		if (!state->enemies[i]->to_right)
			return (1);
		i++;
	}
	return (0);
}
