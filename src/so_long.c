/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/29 00:54:38 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	game.env->mlx = mlx_init();
	if (!game.env->mlx)
		return (-1);
	game.env->win = mlx_new_window(game.env->mlx, WIN_X, WIN_Y, "So Long");
	set_hooks(game.env);
	set_canvas(game.env);
	upload_assets(game.env);
	mlx_loop_hook(game.env->mlx, render, game.env);
	
	mlx_loop(game.env->mlx);
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
        int     width;
        int     height;
        char    *filepath = "./ass/background.xpm";

        env->canvas->img = mlx_xpm_file_to_image(env->mlx, filepath, &width, &height);
	if (!env->canvas->img)
                return ;
        /*

	// Create in map an array of tiles to store the tiles of the game, then loop:
	while (tile ///)
	{
		tile->sprite = mlx_xpm_file_to_image(env->mlx, PATH(i), &tile->width, &tile->height)
		if (!tile->sprite)
			return ;
	}
*/}
