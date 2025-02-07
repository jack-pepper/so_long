/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_memfree_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:39 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 13:46:33 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_memfree_toolkit.h"

void    sl_memfree(t_state *state)
{
	/*sl_destroy_imgs(state);
	free(state->hero->pos);
	free(state->hero);
	free(state->cam);
	free(state->env->canvas);
	sl_free_map(state);
	mlx_destroy_window(state->env->mlx, state->env->win);
	mlx_destroy_display(state->env->mlx);
	free(state->env->mlx);
	free(state->env);
	free(state);*/
	
	if (state->error_code > 4) // fail after set_state, on game loop (5)
	{
		sl_destroy_imgs(state);
		free(state->hero->pos);
		free(state->hero);
		free(state->cam);	
		mlx_destroy_window(state->env->mlx, state->env->win);	
		mlx_destroy_display(state->env->mlx);		
		free(state->env->mlx);
		//free(state->env->canvas);
	}
	if (state->error_code > 1) // fail on (2) map_parser (3) map_validator (4) set_state
		sl_free_map(state);
	if (state->error_code > 0) // (1) fail on init_map
	{
		//mlx_destroy_window(state->env->mlx, state->env->win);
	//	mlx_destroy_display(state->env->mlx);		
//		free(state->env->mlx);
		free(state->env->canvas);
		free(state->env);
		free(state);
	}
}

void    sl_destroy_imgs(t_state *state)
{
	mlx_destroy_image(state->env->mlx, state->env->bkgd_img);
	mlx_destroy_image(state->env->mlx, state->map->wall->sprite);
	mlx_destroy_image(state->env->mlx, state->map->coll->sprite);
	mlx_destroy_image(state->env->mlx, state->map->exit->sprite);
	mlx_destroy_image(state->env->mlx, state->hero->sprite);
	mlx_destroy_image(state->env->mlx, state->env->canvas->img);
}

void    sl_free_map(t_state *state)
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
