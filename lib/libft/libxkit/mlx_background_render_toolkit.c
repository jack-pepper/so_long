/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_background_render_toolkit.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:12:49 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 16:53:16 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_background_render_toolkit.h"

void	render_background(t_state *state)
{
	t_env	*env;
	static t_pos	pos = {.x = 0, .y = 0};

	env = state->env;
	mlx_show(env->mlx, env->win, env->canvas->image, pos);
}
