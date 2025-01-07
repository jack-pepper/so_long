/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:26:48 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/07 11:24:59 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    set_hooks(t_game *game)
{
        mlx_hook(game->env->win, KeyPress, KeyPressMask, &on_keypress, game);
        mlx_hook(game->env->win, DestroyNotify, StructureNotifyMask, &on_destroy, game->env);

//      mlx_hook(env->win, 4, 0, mouse_handler, &env); // on mouse down event
//      mlx_hook(env->win, 2, 1L << 0, key_handler, &env); // on key press
//      mlx_hook(env->win, 17, 1L << 0, close_window, &env); // red cross
}

void    set_canvas(t_env *env)
{
        t_img   *c;

        c = env->canvas;
        c->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
        c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->l_len, &c->endian);
}

void	set_map(t_game *game)
{
	t_tile *wall;
	t_tile *coll;
	t_tile *exit;
	
	wall = malloc (sizeof(t_tile));
	if (!wall)
		return ;
	game->map->wall = wall;	
	
	coll = malloc (sizeof(t_tile));
	if (!coll)
		return ;
	game->map->coll = coll;	
	
	exit = malloc (sizeof(t_tile));
	if (!exit)
		return ;
	game->map->exit = exit;
		
	game->map->width = WIN_WIDTH;
	game->map->height = WIN_HEIGHT;
	game->map->wall->width = wall_width;
	game->map->wall->height = wall_height;
	game->map->coll->width = coll_width;
	game->map->coll->height = coll_height;
	game->map->exit->width = exit_width;
	game->map->exit->height = exit_height;

}

void    upload_assets(t_game *game)
{
	t_hero	*hero;
        int     width;
        int     height;
	
	hero = malloc(sizeof(t_hero));
	if (!hero)
		return ;
	game->hero = hero;	

	// Init hero pos
	t_pos *hero_pos;
	hero_pos = malloc(sizeof(t_pos));
	if (!hero_pos)
		return ;
	game->hero->pos = hero_pos;
	game->hero->pos->x = 600;
	game->hero->pos->y = 600;
//	ft_printf("After init! hero_pos: %d - %d\n", game->hero->pos->x, game->hero->pos->y);

	// Load background
        game->env->canvas->img = mlx_xpm_file_to_image(game->env->mlx, bkgd_path, &width, &height);
	if (!game->env->canvas->img)
                return ;
        // Load wall
        game->map->wall->sprite = mlx_xpm_file_to_image(game->env->mlx, wall_path, &width, &height);
        if (!game->map->wall->sprite)
                return ;
	// Load coll
        game->map->coll->sprite = mlx_xpm_file_to_image(game->env->mlx, coll_path, &width, &height);
        if (!game->map->coll->sprite)
                return ;
	// Load exit
        game->map->exit->sprite = mlx_xpm_file_to_image(game->env->mlx, exit_path, &width, &height);
        if (!game->map->exit->sprite)
                return ;
	// Load hero
        hero->sprite = mlx_xpm_file_to_image(game->env->mlx, hero_path, &width, &height);
        if (!hero->sprite)
                return ;
	//bkgd->addr = mlx_get_data_addr(bkgd->img, &bkgd->bits_per_pixel, &bkgd->line_length, &bkgd->endian);
        /*
        //block->addr = mlx_get_data_addr(block->img, &block->bits_per_pixel, &block->line_length, &block->endian);
        //token->addr = mlx_get_data_addr(token->img, &token->bits_per_pixel, &token->line_length, &token->endian);
        //exit->addr = mlx_get_data_addr(exit->img, &exit->bits_per_pixel, &exit->line_length, &exit->endian); */
}
