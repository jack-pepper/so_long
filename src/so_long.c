/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/28 23:52:29 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_background(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->canvas->img, 0, 0);
}

int	render(t_env *env)
{
	render_background(env);
//	render_map(env, img);
//	render_player(env, img);
//	render_moves(env, img);
	return (0);
}

int	main(void)
{
	t_game	game = {};
	t_env	env;
	t_img	canvas;

	env.canvas = &canvas;
	game.env = &env;
	//t_img	img;
	
	/*
	if (argc != 2)
	{
		ft_printf("Invalid args (needed .ber map)!\n");
		return (1);
	}
	else
		ft_printf("Argv[1] = %s\n", argv[1]);
	*/

	// Init MLX	
	game.env->mlx = mlx_init();
	if (!game.env->mlx)
		return (-1);
	game.env->win = mlx_new_window(game.env->mlx, WIN_X, WIN_Y, "So Long");
	set_hooks(game.env);
	set_canvas(game.env);
	upload_assets(game.env);

	// Rendering
//	mlx_loop_hook(env.mlx, render, &env);
	
	// Init main loop
	mlx_loop(game.env->mlx);

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

void    upload_assets(t_env *env)
{
        int     width = WIN_X;
        int     height = WIN_Y;
        char    *filepath = "./assets/background.xpm";

        env->canvas->img = mlx_xpm_file_to_image(env->mlx, filepath, &width, &height);
        if (!env->canvas->img)
                return ;
        //bkgd->addr = mlx_get_data_addr(bkgd->img, &bkgd->bits_per_pixel, &bkgd->line_length, &bkgd->endian);

        /*
        assets->block->img = mlx_xpm_file_to_image(env->mlx, block_path, &width, &height);
        if (!assets->block->img)
                return ;
        //block->addr = mlx_get_data_addr(block->img, &block->bits_per_pixel, &block->line_length, &block->endian);
        
        assets->token->img = mlx_xpm_file_to_image(env->mlx, token_path, &width, &height);
        if (!assets->token->img)
                return ;
        //token->addr = mlx_get_data_addr(token->img, &token->bits_per_pixel, &token->line_length, &token->endian);
        
        assets->exit->img = mlx_xpm_file_to_image(env->mlx, exit_path, &width, &height);
        if (!assets->exit->img)
                return ;
        //exit->addr = mlx_get_data_addr(exit->img, &exit->bits_per_pixel, &exit->line_length, &exit->endian);

        assets->hero->img = mlx_xpm_file_to_image(env->mlx, hero_path, &width, &height);
        if (!assets->hero->img)
                return ;
*/}



/*
	// Draw a pixel
	//mlx_pixel_put(env.mlx, env.win, WIN_X/2, WIN_Y/2, 0xFFFFFF);
	//mlx_fast_pixel_put(&img, 5, 5, 0x00FF0000);
	//t_mlx_line line = {0, 0, WIN_X, WIN_Y};
	
	t_mlx_line line;
	line.start_x = 0;
	line.start_y = 0;
	line.end_x = WIN_X;
	line.end_y = WIN_Y;
	draw_mlx_line(&env, &line);

	t_mlx_circle circle;
	circle.center_x = WIN_X/2;
	circle.center_y = WIN_Y/2;
	circle.radius = 50;
	draw_mlx_circle(&env, &circle);
	
	// TESTS
	int	i;

	i = 0;
	while (i < 500)
	{
		t_mlx_rect rect;
		rect.origin_x = 10 + i;
		rect.origin_y = 10 + i;
		rect.length = WIN_X - 20;
		rect.width = WIN_Y - 20;
		draw_mlx_rect(&env, &rect);
		i += 2;
	}
	// Display a string
	//mlx_string_put(env.mlx, env.win, 100, 100, 0xFFFFFF, "COUNTER");	
*/
