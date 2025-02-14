/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tileset_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:36:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/14 23:12:07 by mmalie           ###   ########.fr       */
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
	return (0);
}

int	upload_assets(t_state *state, char *level)
{
	if ((load_paths(state, level) != 0)
		|| (upload_tiles(state) != 0)
		|| (upload_hero(state) != 0))
	{
		free_paths(state);
		return (1);
	}
	if (NB_ENEMIES > 0)
	{
		if (upload_enemy(state, NB_ENEMIES) != 0)
		{
			free_paths(state);
			return (1);
		}
	}
	free_paths(state);
	return (0);
}

int	upload_tiles(t_state *state)
{
	int	width;
	int	height;

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
	return (0);
}
