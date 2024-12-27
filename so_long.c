/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/27 15:10:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars	vars;
	t_data	img;

	// Init MLX
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (-1);
	// Init window

	vars.win = mlx_new_window(vars.mlx, WIN_X, WIN_Y, "So Long");

	// Load assets
	//mlx_xpm_file_to_image(mlx, tile, 16, 16);
	
	// Init image
	img.img = mlx_new_image(vars.mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	
	// Draw a pixel
	//mlx_pixel_put(vars.mlx, vars.win, WIN_X/2, WIN_Y/2, 0xFFFFFF);
	//mlx_fast_pixel_put(&img, 5, 5, 0x00FF0000);
	//t_mlx_line line = {0, 0, WIN_X, WIN_Y};
	
	/*
	t_mlx_line line;
	line.start_x = 0;
	line.start_y = 0;
	line.end_x = WIN_X;
	line.end_y = WIN_Y;
	draw_mlx_line(&vars, &line);

	t_mlx_circle circle;
	circle.center_x = WIN_X/2;
	circle.center_y = WIN_Y/2;
	circle.radius = 50;
	draw_mlx_circle(&vars, &circle);
*/
	
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
		draw_mlx_rect(&vars, &rect);
		i += 2;
	}
	// Display a string
	//mlx_string_put(vars.mlx, vars.win, 100, 100, 0xFFFFFF, "COUNTER");	

	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, KeyRelease, KeyReleaseMask, &on_keypress, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);
	
	// Init main loop
	mlx_loop(vars.mlx);

	// Exit
	return (0);
}
