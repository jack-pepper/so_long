/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_memfree_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:39 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/06 14:58:43 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_memfree_toolkit.h"

void    sl_memfree(t_state *state)
{
	sl_destroy_imgs(state);
	free(state->hero->pos);
	free(state->hero);
	free(state->cam);
	free(state->env->canvas);
	sl_free_map(state);
	mlx_destroy_window(state->env->mlx, state->env->win);
	mlx_destroy_display(state->env->mlx);
	free(state->env->mlx);
	free(state->env);
	free(state);
}

void    sl_destroy_imgs(t_state *state)
{
	mlx_destroy_image(state->env->mlx, state->env->bkgd_img);
	mlx_destroy_image(state->env->mlx, state->map->tileset[0]->sprite);
	mlx_destroy_image(state->env->mlx, state->map->tileset[1]->sprite);
	mlx_destroy_image(state->env->mlx, state->map->tileset[2]->sprite);
	mlx_destroy_image(state->env->mlx, state->hero->sprite);
	mlx_destroy_image(state->env->mlx, state->env->canvas->img);
}

void    sl_free_map(t_state *state)
{
	int	row;

	row = 0;
	while (row < state->map->tm_rows);
	{        
		free(state->map->tilemap[row]);
		row++;
	}
	free(state->map->tilemap);
	free(state->map->tileset[0]);
	free(state->map->tileset[1]);
	free(state->map->tileset[2]);
	free(state->map->tile_count);
	free(state->map->tileset);
	free(state->map);
}
