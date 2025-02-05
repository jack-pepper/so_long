/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tileset_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:36:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 21:48:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_tileset_toolkit.h"

int	set_map(t_state *state)
{
	t_tile	**tileset;
	t_tile	*wall;
	t_tile	*coll;
	t_tile	*exit;

	tileset = malloc(sizeof(t_tile) * 5);
	if (!tileset)
		return (ft_error(1, "Error\ntileset malloc failed\n"));
	state->map->tileset = tileset;
	wall = malloc (sizeof(t_tile));
	if (!wall)
		return (1);
	state->map->tileset[0] = wall;
	coll = malloc (sizeof(t_tile));
	if (!coll)
		return (1);
	state->map->tileset[1] = coll;
	exit = malloc (sizeof(t_tile));
	if (!exit)
		return (1);
	state->map->tileset[2] = exit;
	state->map->width = WIN_WIDTH;
	state->map->height = WIN_HEIGHT;
	state->map->tileset[0]->width = WALL_WIDTH;
	state->map->tileset[0]->height = WALL_HEIGHT;
	state->map->tileset[1]->width = COLL_WIDTH;
	state->map->tileset[1]->height = COLL_HEIGHT;
	state->map->tileset[2]->width = EXIT_WIDTH;
	state->map->tileset[2]->height = EXIT_HEIGHT;
	return (0);
}

int	upload_assets(t_state *state)
{
	int	width;
	int	height;

	if (init_hero(state) != 0)
		return (1);
	state->env->bkgd_img = mlx_xpm_file_to_image(state->env->mlx, BKGD_PATH, &width, &height);
	if (!state->env->bkgd_img)
		return (1);
	// Load wall
	state->map->tileset[0]->sprite = mlx_xpm_file_to_image(state->env->mlx, WALL_PATH, &width, &height);
	if (!state->map->tileset[0]->sprite)
		return (1);
	// Load coll
	state->map->tileset[1]->sprite = mlx_xpm_file_to_image(state->env->mlx, COLL_PATH, &width, &height);
	if (!state->map->tileset[1]->sprite)
		return (1);
	// Load exit
	state->map->tileset[2]->sprite = mlx_xpm_file_to_image(state->env->mlx, EXIT_PATH, &width, &height);
	if (!state->map->tileset[2]->sprite)
		return (1);
	// Load hero
	state->hero->sprite = mlx_xpm_file_to_image(state->env->mlx, HERO_PATH, &width, &height);
	if (!state->hero->sprite)
		return (1);
	return (0);
}
