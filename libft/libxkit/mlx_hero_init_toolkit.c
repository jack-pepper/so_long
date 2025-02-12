/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hero_init_toolkit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:52:17 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 11:31:45 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

int	init_hero(t_state *state)
{
	t_hero	*hero;
	t_pos	*hero_pos;

	hero = malloc(sizeof(t_hero));
	if (!hero)
		return (1);
	state->hero = hero;
	hero_pos = malloc(sizeof(t_pos));
	if (!hero_pos)
		return (1);
	state->hero->pos = hero_pos;
	set_hero_pos(state);
	return (0);
}

void	set_hero_pos(t_state *state)
{
	int		row;
	int		col;

	row = 0;
	while (row < state->map->tm_rows)
	{
		col = 0;
		while (col < state->map->tm_cols)
		{
			if (state->map->tilemap[row][col] == 'P')
			{
				state->hero->pos->x = col;
				state->hero->pos->y = row;
				return ;
			}
			col++;
		}
		row++;
	}
	return ;
}

int	upload_hero(t_state *state)
{
	int	width;
	int	height;

	state->hero->img = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->img_path, &width, &height);
	if (!state->hero->img)
		return (1);
	state->hero->to_up = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->to_up_path, &width, &height);
	if (!state->hero->to_up)
		return (1);
	state->hero->to_down = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->to_down_path, &width, &height);
	if (!state->hero->to_down)
		return (1);
	state->hero->to_left = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->to_left_path, &width, &height);
	if (!state->hero->to_left)
		return (1);
	state->hero->to_right = mlx_xpm_file_to_image(state->env->mlx,
			state->hero->to_right_path, &width, &height);
	if (!state->hero->to_right)
		return (1);
	return (0);
}
