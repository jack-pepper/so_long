/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:03:23 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/07 11:31:29 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	calc_cell_size(t_game *game)
{
	int	cell_width;
	int	cell_height;
	int	cell_size;

	cell_width = WIN_WIDTH / game->map->tilemap->tm_cols;
	cell_height = WIN_HEIGHT / game->map->tilemap->tm_rows;
	if (cell_width <= cell_height)
		cell_size = cell_width;
	else
		cell_size = cell_height;
}

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
	int	row;
	int	col;

	tilemap = game->map->tilemap;
	row = 0;
	while (row)
	{
		col = 0;
		while (col)
		{
			if (tilemap[row][col] == '1')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->wall->sprite, 100, 100);
			if (tilemap[row][col] == 'C')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->coll->sprite, row * 100, col * 100);
			if (tilemap[row][col] == 'E')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->exit->sprite, row * 100, col * 100);
			col++;
		}
		row++;	
	}
	// DOES NOT WORK.
}

void	render_hero(t_game *game)
{	
	mlx_put_image_to_window(game->env->mlx, game->env->win, game->hero->sprite, game->hero->pos->x, game->hero->pos->y);
}
