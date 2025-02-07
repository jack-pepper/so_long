/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tileset_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:36:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 16:02:04 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_tileset_toolkit.h"

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
	state->map->width = WIN_WIDTH;
	state->map->height = WIN_HEIGHT;
	state->map->wall->width = WALL_WIDTH;
	state->map->wall->height = WALL_HEIGHT;
	state->map->coll->width = COLL_WIDTH;
	state->map->coll->height = COLL_HEIGHT;
	state->map->exit->width = EXIT_WIDTH;
	state->map->exit->height = EXIT_HEIGHT;
	return (0);
}

int	upload_assets(t_state *state)
{
	int	width;
	int	height;

	if (init_hero(state) != 0)
		return (1);
	state->env->bkgd_img = mlx_xpm_file_to_image(state->env->mlx,
		BKGD_PATH, &width, &height);
	if (!state->env->bkgd_img)
		return (1);
	state->map->wall->img = mlx_xpm_file_to_image(state->env->mlx,
		WALL_PATH, &width, &height);
	if (!state->map->wall->img)
		return (1);
	state->map->coll->img = mlx_xpm_file_to_image(state->env->mlx,
		COLL_PATH, &width, &height);
	if (!state->map->coll->img)
		return (1);
	state->map->exit->img = mlx_xpm_file_to_image(state->env->mlx,
		EXIT_PATH, &width, &height);
	if (!state->map->exit->img)
		return (1);
	state->hero->img = mlx_xpm_file_to_image(state->env->mlx,
		HERO_PATH, &width, &height);
	if (!state->hero->img)
		return (1);
	return (0);
}
