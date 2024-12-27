/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/27 08:55:15 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	key_hook(int key, t_vars *vars)
{
	ft_printf("%s\n", key);
	ft_printf("Hello world! ");
	return (0);
}
*/

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

/*
int	win_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
*/
