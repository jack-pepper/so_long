/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/01 00:56:00 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TO DO: parse the map for validity */

#include "../inc/so_long.h"

int	check_extension(char *filepath, char *extension)
{
	int	i;
	int	j;

	i = ft_strlen(extension) - 1;
	j = ft_strlen(filepath) - 1;
	printf("ext index: %d - filepath index: %d\n", i, j);
	while (i >= 0)
	{
		if (filepath[j] != extension[i])
			return (1);
		printf("filepath[j]: %c - extension[i]: %c\n", filepath[j], extension[i]);
		i--;
		j--;
	}
	ft_printf("Matching extensions!\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_env	env;
	t_img	canvas;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);	
	env.canvas = &canvas;
	game->env = &env;
	if (argc != 2)
	{
		ft_printf("Invalid args (needed .ber map)!\n");
		return (1);
	}
	else
		ft_printf("Argv[1] = %s\n", argv[1]);
	if (check_extension(argv[1], ".ber") != 0)
	{
		ft_printf("Not a .ber file!\n");
		return (1);
	}
	else
		ft_printf("Correct filetype .ber!\n");

	game->env->mlx = mlx_init();
	if (!game->env->mlx)
		return (-1);
	game->env->win = mlx_new_window(game->env->mlx, WIN_X, WIN_Y, "So Long");
	set_hooks(game->env);
	set_canvas(game->env);
	set_map(game);
	upload_assets(game);
	mlx_loop_hook(game->env->mlx, &render, game);

	mlx_loop(game->env->mlx);

	// Exit:
	return (0);
}

void    set_hooks(t_env *env)
{
        mlx_hook(env->win, KeyRelease, KeyReleaseMask, &on_keypress, env);
        mlx_hook(env->win, DestroyNotify, StructureNotifyMask, &on_destroy, env);

//      mlx_hook(env->win, 4, 0, mouse_handler, &env); // on mouse down event
//      mlx_hook(env->win, 2, 1L << 0, key_handler, &env); // on key press
//      mlx_hook(env->win, 17, 1L << 0, close_window, &env); // red cross
}

void    set_canvas(t_env *env)
{
        t_img   *c;

        c = env->canvas;
        c->img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
        c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->l_len, &c->endian);
}

void	set_map(t_game *game)
{
	t_map *map;
	t_tile *wall;
	t_tile *coll;
	t_tile *exit;

	map = malloc(sizeof(t_map));
	if (!map)
		return ;
	game->map = map;
	
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
	
	
	game->map->width = WIN_X;
	game->map->height = WIN_Y;
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
        //exit->addr = mlx_get_data_addr(exit->img, &exit->bits_per_pixel, &exit->line_length, &exit->endian);
*/}
