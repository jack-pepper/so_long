/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:03:23 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/01 12:17:15 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int     render(t_game *game)
{
     	render_background(game->env);
	render_map(game);
	render_hero(game);
//      render_moves(env, img);
        return (0);
}

void    render_background(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->canvas->img, 0, 0);
}

void	render_map(t_game *game)
{
	mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->wall->sprite, 100, 100);
	mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->coll->sprite, 200, 200);
	mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->exit->sprite, 300, 300);
}

void	render_hero(t_game *game)
{	
	mlx_put_image_to_window(game->env->mlx, game->env->win, game->hero->sprite, game->hero->pos->x, game->hero->pos->y);
}
