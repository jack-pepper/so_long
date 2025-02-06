/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_memfree_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:39 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/06 12:33:08 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_memfree_toolkit.h"

void    sl_memfree(t_state *state)
{
        sl_destroy_imgs(state);
//      sl_free_map(state);
        mlx_destroy_window(state->env->mlx, state->env->win);
        mlx_destroy_display(state->env->mlx);
        free(state->env->mlx);
        free(state);
}

void    sl_destroy_imgs(t_state *state)
{
        mlx_destroy_image(state->env->mlx, state->map->tileset[0]->sprite); //  
        mlx_destroy_image(state->env->mlx, state->map->tileset[1]->sprite); //
        mlx_destroy_image(state->env->mlx, state->map->tileset[2]->sprite); //
        //mlx_destroy_image(state->env->mlx, state->map->player_front.xpm_ptr);
        mlx_destroy_image(state->env->mlx, state->hero->sprite);
}

/*
void    sl_free_map(t_state *state)
{
        int     string;

        string = 0;
        while (string < state->map->tm_rows)
                free(state->map.full[string++]);
        free(game->map.full);
}*/

