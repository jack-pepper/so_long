/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_render_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:47:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 10:32:29 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_map_render_toolkit.h"

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
}

void	rm_put_tiles(t_state *state, int row, int col, int cell_size)
{
	t_env	*env;
	t_map	*map;
	char	tile;
	t_pos	pos;

	env = state->env;
	map = state->map;
	if (!map)
	{
		ft_printf("Error: NULL map or tilemap in rm_put_tiles()\n");
		return;
	}
	pos.x = ((col) * cell_size) - state->cam->pos.x;
	pos.y = ((row) * cell_size) - state->cam->pos.y;
	if (state->map->tm_cols * cell_size <= WIN_WIDTH)
		pos.x += (WIN_WIDTH - (state->map->tm_cols * cell_size)) / 2;
	if (state->map->tm_rows * cell_size <= WIN_HEIGHT)
		pos.y += (WIN_HEIGHT - (state->map->tm_rows * cell_size)) / 2;
	tile = map->tilemap[row][col];
	if (tile == '1' && map->wall && map->wall->sprite)
		mlx_put_image_to_window(env->mlx, env->win, map->wall->sprite, pos.x, pos.y);
	else if (tile == 'C' && map->coll && map->coll->sprite)
		mlx_put_image_to_window(env->mlx, env->win, map->coll->sprite, pos.x, pos.y);
	else if (tile == 'E' && map->exit && map->exit->sprite)
		mlx_put_image_to_window(env->mlx, env->win, map->exit->sprite, pos.x, pos.y);
}

//void    scroll_map(t_pos *cam_pos, t_pos *hero_pos, int win_width, 
	//int win_height)
