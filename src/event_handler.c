/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/31 00:10:52 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
int	key_hook(int key, t_env *env)
{
	ft_printf("%s\n", key);
	ft_printf("Hello world! ");
	return (0);
}
*/

/*
int	mouse_handler(t_env *env)
{
	
}

int	key_handler(t_env *env)
{
	
}
*/


int on_destroy(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_env *env)
{
	(void)env;
	ft_printf("Pressed key: %x\n", keysym);
	if (keysym == XK_Escape)
	{
		ft_printf("ESC!\n");
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		exit(0);
	}
	//if (keysym == XK_W)
	//	env->player.pos.x += 1;
	//if (keysym == XK_A)	
	//	env->player.pos.x -= 1;
	//if (keysym == XK_S)
	//	env->player.pos.y -= 1;
	//if (keysym == XK_D)
	//	env->player.pos.y += 1;
	
	return (0);
}


/*
int	win_close(int keycode, t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	return (0);
}
*/
