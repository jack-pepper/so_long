/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:26:48 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/10 00:00:12 by mmalie           ###   ########.fr       */
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

int	init_hero(t_game *game)
{
	t_hero	*hero;
	t_pos	*hero_pos;
	size_t	row;
	size_t	col;

	hero = malloc(sizeof(t_hero));
	if (!hero)
		return (1);
	game->hero = hero;	
	hero_pos = malloc(sizeof(t_pos));
	if (!hero_pos)
		return (1);
	game->hero->pos = hero_pos;
	row = 0;
	col = 0;
	while (row < game->map->tm_rows)
	{
		col = 0;
		while (col < game->map->tm_cols)
		{
			if (game->map->tilemap[row][col] == 'P')
			{
				game->hero->pos->x = col; 
				game->hero->pos->y = row;
				ft_printf("Hero start: y(row)=%d - x(col)=%d\n", game->hero->pos->y, game->hero->pos->x);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}





int	upload_assets(t_game *game)
{
        int     width;
        int     height;
	
	if (init_hero(game) != 0)
		return (1);
//	ft_printf("After init! hero_pos: %d - %d\n", game->hero->pos->x, game->hero->pos->y);
	// Load background
        game->env->canvas->img = mlx_xpm_file_to_image(game->env->mlx, bkgd_path, &width, &height);
	if (!game->env->canvas->img)
                return (1);
        // Load wall
        game->map->wall->sprite = mlx_xpm_file_to_image(game->env->mlx, wall_path, &width, &height);
        if (!game->map->wall->sprite)
                return (1);
	// Load coll
        game->map->coll->sprite = mlx_xpm_file_to_image(game->env->mlx, coll_path, &width, &height);
        if (!game->map->coll->sprite)
                return (1);
	// Load exit
        game->map->exit->sprite = mlx_xpm_file_to_image(game->env->mlx, exit_path, &width, &height);
        if (!game->map->exit->sprite)
                return (1);
	// Load hero
        game->hero->sprite = mlx_xpm_file_to_image(game->env->mlx, hero_path, &width, &height);
        if (!game->hero->sprite)
                return (1);
	return (0);
	//bkgd->addr = mlx_get_data_addr(bkgd->img, &bkgd->bits_per_pixel, &bkgd->line_length, &bkgd->endian);
        /*
        //block->addr = mlx_get_data_addr(block->img, &block->bits_per_pixel, &block->line_length, &block->endian);
        //token->addr = mlx_get_data_addr(token->img, &token->bits_per_pixel, &token->line_length, &token->endian);
        //exit->addr = mlx_get_data_addr(exit->img, &exit->bits_per_pixel, &exit->line_length, &exit->endian); */
}
