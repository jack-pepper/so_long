/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_background_render_toolkit.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:12:49 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 21:27:37 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	render_background(t_state *state)
{
	t_env			*env;
	static t_pos	pos = {.x = 0, .y = 0};

	env = state->env;
	mlx_put_image_to_window(env->mlx, env->win, env->bkgd_img, pos.x, pos.y);
}
