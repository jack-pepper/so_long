/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_on_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:19:01 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/31 21:23:32 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_event_on_motion.h"

void	on_motion_up(t_state *state)
{
	state->hero->pos->y -= 1;
	(state->data->nb_steps)++;
	ft_printf("steps: %d \n", state->data->nb_steps);
	update_cam_pos(state->cam, -1, 0, state->env);
	state->hero_event = 1;
}

void	on_motion_down(t_state *state)
{
	state->hero->pos->y += 1;
	(state->data->nb_steps)++;
	ft_printf("steps: %d \n", state->data->nb_steps);
	update_cam_pos(state->cam, 1, 0, state->env);
	state->hero_event = 1;
}

void	on_motion_left(t_state *state)
{
	state->hero->pos->x -= 1;
	(state->data->nb_steps)++;
	ft_printf("steps: %d \n", state->data->nb_steps);
	update_cam_pos(state->cam, 0, -1, state->env);
	state->hero_event = 1;
}

void	on_motion_right(t_state *state)
{
	state->hero->pos->x += 1;
	(state->data->nb_steps)++;
	ft_printf("steps: %d \n", state->data->nb_steps);
	update_cam_pos(state->cam, 0, 1, state->env);
	state->hero_event = 1;
}
