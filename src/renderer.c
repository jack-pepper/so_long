/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:03:23 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/06 23:05:01 by mmalie           ###   ########.fr       */
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
	char	**tilemap;	
	size_t	row;
	size_t	col;

	tilemap = game->map->tilemap;
	row = 0;
	while (row < game->map->tm_rows)
	{
		col = 0;
		while (col < (game->map->tm_cols - 2))
		{
			if (tilemap[row][col] == '1')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->wall->sprite, 100, 100);
			else if (tilemap[row][col] == 'C')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->coll->sprite, row * 100, col * 100);
			else if (tilemap[row][col] == 'E')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->exit->sprite, row * 100, col * 100);
			col++;
		}
		row++;	
	}
}

void	render_hero(t_game *game)
{	
	mlx_put_image_to_window(game->env->mlx, game->env->win, game->hero->sprite, game->hero->pos->x, game->hero->pos->y);
}
