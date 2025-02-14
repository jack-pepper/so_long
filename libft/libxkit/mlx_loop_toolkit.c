/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_toolkit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:01:34 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/14 23:10:25 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	update_render(t_state *state)
{
	mlx_clear_window(state->env->mlx, state->env->win);
	render_background(state);
	render_map(state);
	render_hero(state);
	if (NB_ENEMIES > 0)
		render_enemy(state);
}
