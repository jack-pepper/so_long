/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:03:23 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/07 20:17:40 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	calc_cell_size(t_game *game)
{
	size_t	cell_width;
	size_t	cell_height;
	size_t	cell_size;

	cell_width = WIN_WIDTH / (int)(game->map->tm_cols);
	cell_height = WIN_HEIGHT / (int)(game->map->tm_rows);
	game->map->cell_width = cell_width;
	game->map->cell_height = cell_height;
	if (cell_width <= cell_height)
		cell_size = cell_width;
	else
		cell_size = cell_height;
	game->map->cell_size = cell_size;
	return (cell_size);
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
	size_t	row;
	size_t	col;
	int	c_size;
	
	tilemap = game->map->tilemap;
	row = 0;
	c_size = game->map->cell_size;
	//ft_printf("C_SIZE = %d\n", c_size);
	while (row < game->map->tm_rows)
	{
		col = 0;
		while (col < game->map->tm_cols)
		{
			if (tilemap[row][col] == '1')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->wall->sprite, col * c_size, row * c_size);
			if (tilemap[row][col] == 'C')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->coll->sprite, col * c_size, row * c_size);
			if (tilemap[row][col] == 'E')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->exit->sprite, col * c_size, row * c_size);
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
