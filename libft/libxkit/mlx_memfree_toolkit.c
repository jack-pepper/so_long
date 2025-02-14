/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_memfree_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:39 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/14 23:29:35 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

/* Fail on [1] init_map | [2] map_parser | [3] map_validator | 
 * [4] set_state | [5] game loop
 */
void	sl_memfree(t_state *state)
{
	if (state->error_code > 4)
		free(state->cam);
	if (state->error_code > 2)
	{
		sl_destroy_imgs(state);
		mlx_destroy_image(state->env->mlx, state->env->canvas->img);
		free(state->hero->pos);
		free(state->hero);
		if (NB_ENEMIES > 0)
			sl_free_enemies(state);
		mlx_destroy_window(state->env->mlx, state->env->win);
		mlx_destroy_display(state->env->mlx);
		free(state->env->mlx);
	}
	if (state->error_code > 1)
		sl_free_map(state);
	if (state->error_code > 0)
	{
		free(state->env->canvas);
		free(state->env);
		free(state);
	}
}

void	sl_destroy_imgs(t_state *state)
{
	if (state->env->bkgd_img)
		mlx_destroy_image(state->env->mlx, state->env->bkgd_img);
	if (state->map->wall->img)
		mlx_destroy_image(state->env->mlx, state->map->wall->img);
	if (state->map->coll->img)
		mlx_destroy_image(state->env->mlx, state->map->coll->img);
	if (state->map->exit->img)
		mlx_destroy_image(state->env->mlx, state->map->exit->img);
	if (state->hero->img)
		mlx_destroy_image(state->env->mlx, state->hero->img);
	if (state->hero->to_up)
		mlx_destroy_image(state->env->mlx, state->hero->to_up);
	if (state->hero->to_down)
		mlx_destroy_image(state->env->mlx, state->hero->to_down);
	if (state->hero->to_left)
		mlx_destroy_image(state->env->mlx, state->hero->to_left);
	if (state->hero->to_right)
		mlx_destroy_image(state->env->mlx, state->hero->to_right);
	if (NB_ENEMIES > 0)
		sl_destroy_imgs_enemy(state);
}

void	sl_free_map(t_state *state)
{
	int	row;

	row = 0;
	while (row < state->map->tm_rows)
	{
		free(state->map->tilemap[row]);
		row++;
	}
	free(state->map->tilemap);
	free(state->map->wall);
	free(state->map->coll);
	free(state->map->exit);
	free(state->map->tile_count);
	free(state->map);
}

void	free_paths(t_state *state)
{
	if (state->env->bkgd_path)
		free(state->env->bkgd_path);
	if (state->map->wall->path)
		free(state->map->wall->path);
	if (state->map->coll->path)
		free(state->map->coll->path);
	if (state->map->exit->path)
		free(state->map->exit->path);
	if (state->hero->img_path)
		free(state->hero->img_path);
	if (state->hero->to_up_path)
		free(state->hero->to_up_path);
	if (state->hero->to_down_path)
		free(state->hero->to_down_path);
	if (state->hero->to_left_path)
		free(state->hero->to_left_path);
	if (state->hero->to_right_path)
		free(state->hero->to_right_path);
	if (NB_ENEMIES > 0)
		free_paths_enemy(state);
}

// Free arr and each element
void	sl_free_all(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}
