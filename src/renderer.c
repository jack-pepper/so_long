/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:03:23 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/10 00:03:50 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* I need to improve rendering. Three options:
 * - modify the size of assets? Not convenient
 * - resize them dynamically? Not efficient
 * - I should resize them before starting the game and use those new images
 */


int	calc_cell_size(t_game *game)
{
	size_t	cell_width;
	size_t	cell_height;
	size_t	cell_size;

	//cell_width = WIN_WIDTH / (int)(game->map->tm_cols);
	//cell_height = WIN_HEIGHT / (int)(game->map->tm_rows);
	cell_width = RES_PIX;
	cell_height = RES_PIX;
	game->map->cell_width = cell_width;
	game->map->cell_height = cell_height;
	if (cell_width <= cell_height)
		cell_size = cell_width;
	else
		cell_size = cell_height;
	game->map->cell_size = cell_size;
	return (cell_size);
}

/*
void	scale_img(void *mlx, void *win, void *img, int factor)
{
	int	img_width;
	int	img_height;
	int	scaled_img;

	
	img_width = img_width * factor;
	img_height = img_height * factor;
	scaled_img = mlx_new_image(mlx, img_width, img_height);
	img->img = scaled_img;
}
*/	

int     render(t_game *game)
{
     	render_background(game->env);
	render_map(game);
	render_hero(game);
//      render_moves(env, img);
	on_collect(game);
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
			{
				//scale_img(game->env->mlx, game->env->win, game->map->wall, 2);
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->wall->sprite, col * c_size, row * c_size);
			}
			if (tilemap[row][col] == 'C')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->coll->sprite, col * c_size, row * c_size);
			if (tilemap[row][col] == 'E')
				mlx_put_image_to_window(game->env->mlx, game->env->win, game->map->exit->sprite, col * c_size, row * c_size);
			col++;
		}
		row++;	
	}
}

void	render_hero(t_game *game)
{
	mlx_put_image_to_window(game->env->mlx, game->env->win, game->hero->sprite, game->hero->pos->x * RES_PIX, game->hero->pos->y * RES_PIX);
}

void	on_collect(t_game *game)
{
	char	**tilemap;
	t_pos	*pos;

	tilemap = game->map->tilemap;
	pos = game->hero->pos;
	if (tilemap[pos->y][pos->x] == 'C')
	{
		ft_printf("Found collectible!\n");
		// Add one to number of collected (add to struct)
		tilemap[pos->y][pos->x] = '0';
		// minus one to collectibles (counter) and plus one to empty
	}
}
