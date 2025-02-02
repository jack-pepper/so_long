/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_render_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:47:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/02 22:33:34 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_map_render_toolkit.h"

// Draw a grid.
//void    draw_grid(t_env *env, int cell_size, int color)

void render_map(t_state *state)
{
	int     row;
	int	col;
	int	map_x;
	int	map_y;

//	x_start = cam->pos.x / RES_PIX;
//	y_start = cam->pos.y / RES_PIX;
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

    // Debugging Output
    ft_printf("[render_map] Camera View - Start: (%d, %d), Max: (%d, %d)\n",
              state->cam->pos.x / RES_PIX, state->cam->pos.y / RES_PIX, state->cam->max.x, state->cam->max.y);
}


/*
void	render_map(t_state *state)
{
	t_cam	*cam;
	int	cell_size;
	int	row;
	int	col;

	cam = state->cam;
	//cell_size = state->map->cell_size;
	cell_size = RES_PIX;
	
	row = 0;
	if ((state->map->height <= state->env->canvas_height)
		&& (state->map->width <= state->env->canvas_width))
	{
		while (row < (state->map->tm_rows))
		{
			col = 0;
			while (col < (state->map->tm_cols))
			{
				rm_put_tiles(state, row, col, cell_size);
				col++;
			}
			row++;
		}
	}
	else
	{
		while (row < (state->env->canvas_height))
		{
			col = 0;
			while (col < (state->env->canvas_width))
			{
				if (((cam->pos.x + col) < (state->map->width))
					&& ((cam->pos.y + row) < (state->map->height)))
				rm_put_tiles(state, cam->pos.x + col, cam->pos.y + row, cell_size);
				col++;
			}
			row++;
		}
	}
}
*/

/* Display the sprite defined for each tilemap char:
 * '1' = wall / 'C' = collectible / 'E' = exit)
 * tileset[0] = state->map->wall->sprite / [1] = collectible / [2] = exit 
 */
void	rm_put_tiles(t_state *state, int row, int col, int cell_size)
{
	t_env		*env;
	char		**tilemap;
	t_tile		**tileset;
	t_pos		pos;

	env = state->env;
	tilemap = state->map->tilemap;
	tileset = state->map->tileset;
	//pos.x = (col * cell_size) + ((WIN_WIDTH - (state->map->tm_cols * cell_size)) / 2);
	//pos.y = (row * cell_size) + ((WIN_HEIGHT - (state->map->tm_rows * cell_size)) / 2);
	pos.x = (col * cell_size) - state->cam->pos.x;
	pos.y = (row * cell_size) - state->cam->pos.y;
	if (state->map->tm_cols * cell_size <= WIN_WIDTH)
		pos.x += (WIN_WIDTH - (state->map->tm_cols * cell_size)) / 2;
	if (state->map->tm_rows * cell_size <= WIN_HEIGHT)
		pos.y += (WIN_HEIGHT - (state->map->tm_rows * cell_size)) / 2;
	//ft_printf("[put_tiles] Tile (%d, %d) -> Screen Pos: pos.x: %d - pos.y: %d\n", col, row, pos.x, pos.y); // DEBUG

	//pos.x = (col * cell_size) + ((WIN_WIDTH - (state->map->tm_cols * cell_size)) / 2);
	//pos.y = (row * cell_size) + ((WIN_HEIGHT - (state->map->tm_rows * cell_size)) / 2);
	if (tilemap[row][col] == '1')
	{
		mlx_show(env->mlx, env->win, tileset[0]->sprite, pos);
	}
	if (tilemap[row][col] == 'C')
	{
		mlx_show(env->mlx, env->win, tileset[1]->sprite, pos);
	}
	if (tilemap[row][col] == 'E')
	{
		mlx_show(env->mlx, env->win, tileset[2]->sprite, pos);
	}
}

/* Scrolling map */
//void    scroll_map(t_pos *camera_pos, t_pos *hero_pos, 
	//int screen_width, int screen_height)
//{	
//}

/* Pathfinding */
//t_path  find_path(int **map, t_pos start, t_pos end);
