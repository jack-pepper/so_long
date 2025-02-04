/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_background_render_toolkit.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:12:49 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/04 19:13:05 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_background_render_toolkit.h"

void	render_background(t_state *state)
{
	t_env	*env;
	static t_pos	pos = {.x = 0, .y = 0};

	env = state->env;
	//mlx_show(env->mlx, env->win, env->canvas->img, pos);
	mlx_show(env->mlx, env->win, env->bkgd_img, pos);
	//mlx_draw_to_canvas(env->canvas, env->bkgd_img, pos);
	//mlx_draw_to_canvas(env->canvas, state->map->tileset[2], pos);
//	mlx_put_image_to_window(env->mlx, env->canvas->img, env->bkgd_img, pos.x, pos.y);
}
