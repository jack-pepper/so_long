/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tileset_toolkit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:36:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/04 18:37:08 by mmalie           ###   ########.fr       */
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
/*
t_img *convert_xpm_to_img(void *mlx, char *xpm_path, int width, int height)
{
    t_img *new_img;
    t_img *xpm_img;
    int x, y;
    char *dst, *src;

    // ✅ Load the XPM image
    xpm_img = mlx_xpm_file_to_image(mlx, xpm_path, &width, &height);
    if (!xpm_img)
    {
        ft_printf("Error: Failed to load XPM: %s\n", xpm_path);
        return (NULL);
    }

    // ✅ Create a modifiable image
    new_img = mlx_new_image(mlx, width, height);
    if (!new_img)
    {
        ft_printf("Error: Failed to create new image for: %s\n", xpm_path);
        return (NULL);
    }

    // ✅ Get addresses for both images
    new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bpp, &new_img->l_len, &new_img->endian);
    xpm_img->addr = mlx_get_data_addr(xpm_img->img, &xpm_img->bpp, &xpm_img->l_len, &xpm_img->endian);

    if (!new_img->addr || !xpm_img->addr)
    {
        ft_printf("Error: mlx_get_data_addr failed for %s\n", xpm_path);
        return (NULL);
    }

    // ✅ Copy pixels from XPM image to new image
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            src = xpm_img->addr + (y * xpm_img->l_len + x * (xpm_img->bpp / 8));
            dst = new_img->addr + (y * new_img->l_len + x * (new_img->bpp / 8));
            *(unsigned int *)dst = *(unsigned int *)src;
        }
    }

    return new_img; // ✅ Return the modifiable image
}
*/

int     upload_assets(t_state *state)
{
        int     width;
        int     height;

	if (init_hero(state) != 0)
		return (1);
        // Load background
        state->env->bkgd_img = mlx_xpm_file_to_image(state->env->mlx, bkgd_path, &width, &height);
        if (!state->env->bkgd_img)
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

	//t_img *bkgd_img = state->env->bkgd_img;
        //bkgd_img->addr = mlx_get_data_addr(bkgd_img->img, &bkgd_img->bpp, &bkgd_img->l_len, &bkgd_img->endian);
        /*
        //block->addr = mlx_get_data_addr(block->img, &block->bits_per_pixel, &block->line_length, &block->endian);
        //token->addr = mlx_get_data_addr(token->img, &token->bits_per_pixel, &token->line_length, &token->endian);
        //exit->addr = mlx_get_data_addr(exit->img, &exit->bits_per_pixel, &exit->line_length, &exit->endian); */
}
