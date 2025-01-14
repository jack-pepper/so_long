/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tileset_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:36:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 19:14:51 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_tileset_toolkit.h"

int	set_map(t_state *state)
{
        t_tile **tileset;
        t_tile *wall;
        t_tile *coll;
        t_tile *exit;

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
        state->map->tileset[0]->width = wall_width;
        state->map->tileset[0]->height = wall_height;
        state->map->tileset[1]->width = coll_width;
        state->map->tileset[1]->height = coll_height;
        state->map->tileset[2]->width = exit_width;
        state->map->tileset[2]->height = exit_height;
	return (0);
}

int     upload_assets(t_state *state)
{
        int     width;
        int     height;

	if (init_hero(state) != 0)
		return (1);
        // Load background
        state->env->canvas->image = mlx_xpm_file_to_image(state->env->mlx, bkgd_path, &width, &height);
        if (!state->env->canvas->image)
                return (1);
        // Load wall
        state->map->tileset[0]->sprite = mlx_xpm_file_to_image(state->env->mlx, wall_path, &width, &height);
        if (!state->map->tileset[0]->sprite)
                return (1);
        // Load coll
        state->map->tileset[1]->sprite = mlx_xpm_file_to_image(state->env->mlx, coll_path, &width, &height);
        if (!state->map->tileset[1]->sprite)
                return (1);
        // Load exit
        state->map->tileset[2]->sprite = mlx_xpm_file_to_image(state->env->mlx, exit_path, &width, &height);
        if (!state->map->tileset[2]->sprite)
                return (1);
        // Load hero
        state->hero->sprite = mlx_xpm_file_to_image(state->env->mlx, hero_path, &width, &height);
        if (!state->hero->sprite)
                return (1);
        return (0);
        //bkgd->addr = mlx_get_data_addr(bkgd->img, &bkgd->bits_per_pixel, &bkgd->line_length, &bkgd->endian);
        /*
        //block->addr = mlx_get_data_addr(block->img, &block->bits_per_pixel, &block->line_length, &block->endian);
        //token->addr = mlx_get_data_addr(token->img, &token->bits_per_pixel, &token->line_length, &token->endian);
        //exit->addr = mlx_get_data_addr(exit->img, &exit->bits_per_pixel, &exit->line_length, &exit->endian); */
}

