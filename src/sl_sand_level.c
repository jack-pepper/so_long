/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_sand_level.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nsand.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:27:53 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/10 10:25:46 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*
 * Upload assets to sand level in the game So Long.
 */

int     upload_assets_sand_lvl(t_state *state)
{
	int	width;
	int	height;

	state->env->bkgd_img = mlx_xpm_file_to_image(state->env->mlx,
			BKGD_PATH_SAND, &width, &height);
	if (!state->env->bkgd_img)
		return (1);
	state->map->wall->img = mlx_xpm_file_to_image(state->env->mlx,
			WALL_PATH_SAND, &width, &height);
	if (!state->map->wall->img)
		return (1);
	state->map->coll->img = mlx_xpm_file_to_image(state->env->mlx,
			COLL_PATH_SAND, &width, &height);
	if (!state->map->coll->img)
		return (1);
	state->map->exit->img = mlx_xpm_file_to_image(state->env->mlx,
			EXIT_PATH_SAND, &width, &height);
	if (!state->map->exit->img)
		return (1);
	if (upload_hero(state) != 0)
		return (1);
	if (upload_enemy(state) != 0)
		return (1);
	return (0);
}

int	upload_hero_sand_lvl(t_state *state)
{
	int	width;
	int	height;

	state->hero->img = mlx_xpm_file_to_image(state->env->mlx,
			HERO_PATH_SAND, &width, &height);
	if (!state->hero->img)
		return (1);
	state->hero->to_up = mlx_xpm_file_to_image(state->env->mlx,
			HERO_TO_UP_PATH_SAND, &width, &height);
	if (!state->hero->to_up)
		return (1);
	state->hero->to_down = mlx_xpm_file_to_image(state->env->mlx,
			HERO_TO_DOWN_PATH_SAND, &width, &height);
	if (!state->hero->to_down)
		return (1);
	state->hero->to_left = mlx_xpm_file_to_image(state->env->mlx,
			HERO_TO_LEFT_PATH_SAND, &width, &height);
	if (!state->hero->to_left)
		return (1);
	state->hero->to_right = mlx_xpm_file_to_image(state->env->mlx,
			HERO_TO_RIGHT_PATH_SAND, &width, &height);
	if (!state->hero->to_right)
		return (1);
	return (0);
}

int	upload_enemy_sand_lvl(t_state *state)
{
	int	width;
	int	height;

	state->enemy->img = mlx_xpm_file_to_image(state->env->mlx,
			ENEMY_PATH_SAND, &width, &height);
	if (!state->enemy->img)
		return (1);
	state->enemy->to_up = mlx_xpm_file_to_image(state->env->mlx,
			ENEMY_TO_UP_PATH_SAND, &width, &height);
	if (!state->enemy->to_up)
		return (1);
	state->enemy->to_down = mlx_xpm_file_to_image(state->env->mlx,
			ENEMY_TO_DOWN_PATH_SAND, &width, &height);
	if (!state->enemy->to_down)
		return (1);
	state->enemy->to_left = mlx_xpm_file_to_image(state->env->mlx,
			ENEMY_TO_LEFT_PATH_SAND, &width, &height);
	if (!state->enemy->to_left)
		return (1);
	state->enemy->to_right = mlx_xpm_file_to_image(state->env->mlx,
			ENEMY_TO_RIGHT_PATH_SAND, &width, &height);
	if (!state->enemy->to_right)
		return (1);
	return (0);
}
