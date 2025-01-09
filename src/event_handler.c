/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/09 21:14:31 by mmalie           ###   ########.fr       */
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

int on_keypress(int keysym, t_game *game)
{
	t_pos *pos;

	pos = game->hero->pos;
	if (keysym == XK_Escape)
	{
		ft_printf("ESC!\n");
		mlx_destroy_window(game->env->mlx, game->env->win);
	//	mlx_destroy_display(game->env->mlx);
	//	free(game->env->mlx);
		exit(0);
	}
	else if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
	{
		ft_printf("Pressed key: %x\n", keysym);	
		ft_printf("Before move! hero_pos: y(row): %d - x(col)%d\n", game->hero->pos->y, game->hero->pos->x);
		//if (keysym == XK_w && (game->map->tilemap[pos->x][pos->y - 1] != '1'))
		//	game->hero->pos->y -= 1;
		//else if (keysym == XK_a && (game->map->tilemap[pos->x - 1][pos->y] != '1'))
		//	game->hero->pos->x -= 1;
		//else if (keysym == XK_s && (game->map->tilemap[pos->x][pos->y + 1] != '1'))
		//	game->hero->pos->y += 1;
		//else if (keysym == XK_d && (game->map->tilemap[pos->x + 1][pos->y] != '1'))
		//	game->hero->pos->x += 1;
		if (keysym == XK_w && (game->map->tilemap[pos->y - 1][pos->x] != '1'))
			game->hero->pos->y -= 1;
		else if (keysym == XK_a && (game->map->tilemap[pos->y][pos->x - 1] != '1'))
			game->hero->pos->x -= 1;
		else if (keysym == XK_s && (game->map->tilemap[pos->y + 1][pos->x] != '1'))
			game->hero->pos->y += 1;
		else if (keysym == XK_d && (game->map->tilemap[pos->y][pos->x + 1] != '1'))
			game->hero->pos->x += 1;
		ft_printf("After move! hero_pos: %d - %d\n", game->hero->pos->y, game->hero->pos->x);
	}
	return (0);
}


/*
int	win_close(int keycode, t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	return (0);
}
*/
