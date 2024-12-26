/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/27 00:44:31 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIN_X 1620
#define WIN_Y 780

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef struct	s_mlx_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
}		t_mlx_line;

void	mlx_fast_pixel_put(t_data *data, int x, int y, int color);
int	win_close(int keysym, t_vars *vars);

/*
int	key_hook(int key, t_vars *vars)
{
	ft_printf("%s\n", key);
	ft_printf("Hello world! ");
	return (0);
}
*/

int	draw_mlx_line(t_vars *vars, t_mlx_line *line)
{
	int	len;
	int	pix;
	int	x;
	int	y;

	len = line->end_x - line->start_x;
	pix = 0;
	while (pix > len)
	{
		x = line->start_x + pix;
		y = line->start_y + pix;
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
		pix++;
	}
	return (0);
}

int on_keypress(int keysym, t_vars *vars)
{
	// ESC = 65307
	(void)vars;
	ft_printf("Pressed key: %x\n", keysym);
	if (keysym == XK_Escape)
	{
		ft_printf("ESC!\n");
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	//if (keysym == XK_W)
	//if (keysym == XK_A)
	//if (keysym == XK_S)
	//if (keysym == XK_D)
	
	return (0);
}

int on_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

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
	t_mlx_line line;
	line.start_x = 0;
	line.start_y = 0;
	line.end_x = WIN_X;
	line.end_y = WIN_Y;
	draw_mlx_line(&vars, &line);

	// Display a string
	//mlx_string_put(vars.mlx, vars.win, 100, 100, 0xFFFFFF, "COUNTER");	

	//mlx_key_hook(vars.win, key_hook, &vars);
	// Register key release hook
	mlx_hook(vars.win, KeyRelease, KeyReleaseMask, &on_keypress, &vars);
	// Register destroy hook (cross)
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, &on_destroy, &vars);

	// register mouse movement: mlx_hook(vars.win, MotionNotify, )

	
	// Init main loop
	mlx_loop(vars.mlx);

	// Exit
	return (0);
}

void	mlx_fast_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
int	win_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
*/
