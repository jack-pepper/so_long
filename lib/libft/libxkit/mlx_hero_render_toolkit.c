/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hero_render_toolkit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:03:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/02 22:17:36 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_hero_render_toolkit.h"

void	render_hero(t_state *state)
{
	t_env	*env;
	XImage	*hero_sprite;
	t_pos	hero_pos;

	env = state->env;
	hero_sprite = state->hero->sprite;
	hero_pos.x = (state->hero->pos->x * RES_PIX) - (state->cam->pos.x);
	hero_pos.y = (state->hero->pos->y * RES_PIX) - (state->cam->pos.y);
	mlx_show(env->mlx, env->win, hero_sprite, hero_pos);
}
