/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hero_render_toolkit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:03:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 15:33:39 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_hero_render_toolkit.h"

/* If the map is smaller than the window, it will be centered.
 * The hero position is set accordingly.
 */
void	render_hero(t_state *state)
{
	t_env	*env;
	void	*hero_sprite;
	t_pos	hero_pos;

	env = state->env;
	hero_sprite = state->hero->img;
	hero_pos.x = (state->hero->pos->x * RES_PIX) - (state->cam->pos.x);
	hero_pos.y = (state->hero->pos->y * RES_PIX) - (state->cam->pos.y);
	if (state->map->tm_cols * RES_PIX <= WIN_WIDTH)
		hero_pos.x += (WIN_WIDTH - (state->map->tm_cols * RES_PIX)) / 2;
	if (state->map->tm_rows * RES_PIX <= WIN_HEIGHT)
		hero_pos.y += (WIN_HEIGHT - (state->map->tm_rows * RES_PIX)) / 2;
	mlx_show(env->mlx, env->win, hero_sprite, hero_pos);
}
