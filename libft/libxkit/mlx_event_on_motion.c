/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_on_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:19:01 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 14:27:38 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	on_motion_up(t_state *state)
{
	state->hero->pos->y -= 1;
	(state->data->nb_steps)++;
	ft_printf("👟 steps: %d \n", state->data->nb_steps);
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	state->render_event = 3;
	state->hero->frame = 1;
}

void	on_motion_down(t_state *state)
{
	state->hero->pos->y += 1;
	(state->data->nb_steps)++;
	ft_printf("👟 steps: %d \n", state->data->nb_steps);
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	state->render_event = 3;
	state->hero->frame = 2;
}

void	on_motion_left(t_state *state)
{
	state->hero->pos->x -= 1;
	(state->data->nb_steps)++;
	ft_printf("👟 steps: %d \n", state->data->nb_steps);
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	state->render_event = 3;
	state->hero->frame = 3;
}

void	on_motion_right(t_state *state)
{
	state->hero->pos->x += 1;
	(state->data->nb_steps)++;
	ft_printf("👟 steps: %d \n", state->data->nb_steps);
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	state->render_event = 3;
	state->hero->frame = 4;
}
