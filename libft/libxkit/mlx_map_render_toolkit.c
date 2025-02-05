/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_render_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:47:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 12:01:40 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_map_render_toolkit.h"

// Draw a grid.
//void    draw_grid(t_env *env, int cell_size, int color)

void	render_map(t_state *state)
{
	int	row;
	int	col;
	int	map_x;
	int	map_y;

	row = 0;
	while (row < ((state->env->canvas_height / RES_PIX) + 1))
	{
		col = 0;
		while (col < ((state->env->canvas_width / RES_PIX) + 1))
		{
			map_x = (state->cam->pos.x / RES_PIX) + col;
			map_y = (state->cam->pos.y / RES_PIX) + row;
			if (map_x < state->map->tm_cols && map_y < state->map->tm_rows)
				rm_put_tiles(state, map_y, map_x, RES_PIX);
			col++;
		}
		row++;
	}
//	ft_printf("[render_map] Camera View - Start: (%d, %d), Max: (%d, %d)\n",
//	state->cam->pos.x / RES_PIX, state->cam->pos.y / RES_PIX, state->cam->max.x, state->cam->max.y);
}

void	rm_put_tiles(t_state *state, int row, int col, int cell_size)
{
	t_env	*env;
	t_tile	**tileset;
	char	**tilemap;
	char	tile;
	t_pos	pos;

	env = state->env;
	tilemap = state->map->tilemap;
	tileset = state->map->tileset;
	if (!tilemap || !tileset)
	{
		ft_printf("Error: NULL tilemap or tileset in rm_put_tiles()\n");
		return;
	}
	pos.x = ((col) * cell_size) - state->cam->pos.x;
	pos.y = ((row) * cell_size) - state->cam->pos.y;
	if (state->map->tm_cols * cell_size <= WIN_WIDTH)
		pos.x += (WIN_WIDTH - (state->map->tm_cols * cell_size)) / 2;
	if (state->map->tm_rows * cell_size <= WIN_HEIGHT)
		pos.y += (WIN_HEIGHT - (state->map->tm_rows * cell_size)) / 2;
	// Debugging output
    	//ft_printf("[put_tiles] Tile (%d, %d) -> Screen Pos: (%d, %d)\n", col, row, pos.x, pos.y);
	tile = tilemap[row][col];
	if (tile == '1' && tileset[0] && tileset[0]->sprite)
	//	mlx_show(env->mlx, env->win, tileset[0]->sprite, pos);
		mlx_put_image_to_window(env->mlx, env->win, tileset[0]->sprite, pos.x, pos.y); // put_image seems to solve flickering... not mlx_show
	else if (tile == 'C' && tileset[1] && tileset[1]->sprite)
	//	mlx_show(env->mlx, env->win, tileset[1]->sprite, pos);
		mlx_put_image_to_window(env->mlx, env->win, tileset[1]->sprite, pos.x, pos.y);	
	else if (tile == 'E' && tileset[2] && tileset[2]->sprite)	
	//	mlx_show(env->mlx, env->win, tileset[2]->sprite, pos);
		mlx_put_image_to_window(env->mlx, env->win, tileset[2]->sprite, pos.x, pos.y);	
}

/* Scrolling map */
//void    scroll_map(t_pos *camera_pos, t_pos *hero_pos, 
	//int screen_width, int screen_height) {}
