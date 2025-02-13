/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_render_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:47:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 14:03:15 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

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
	char	tile;
	t_pos	p;

	p.x = ((col) * cell_size) - state->cam->pos.x;
	p.y = ((row) * cell_size) - state->cam->pos.y;
	if (state->map->tm_cols * cell_size <= WIN_WIDTH)
		p.x += (WIN_WIDTH - (state->map->tm_cols * cell_size)) / 2;
	if (state->map->tm_rows * cell_size <= WIN_HEIGHT)
		p.y += (WIN_HEIGHT - (state->map->tm_rows * cell_size)) / 2;
	tile = state->map->tilemap[row][col];
	if (tile == '1' && state->map->wall && state->map->wall->img)
		mlx_put_image_to_window(state->env->mlx, state->env->win,
			state->map->wall->img, p.x, p.y);
	else if (tile == 'C' && state->map->coll && state->map->coll->img)
		mlx_put_image_to_window(state->env->mlx, state->env->win,
			state->map->coll->img, p.x, p.y);
	else if (tile == 'E' && state->map->exit && state->map->exit->img)
		mlx_put_image_to_window(state->env->mlx, state->env->win,
			state->map->exit->img, p.x, p.y);
}
