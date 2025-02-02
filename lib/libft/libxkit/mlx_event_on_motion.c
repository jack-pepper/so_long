/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_on_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:19:01 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/02 21:45:19 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_event_on_motion.h"

void	on_motion_up(t_state *state)
{
	state->hero->pos->y -= 1;
	(state->data->nb_steps)++;
	ft_printf("steps: %d \n", state->data->nb_steps);
	//update_cam_pos(state->cam, -1, 0, state->env);
	ft_printf("[on_motion up] hero.pos: x = %d, y = %d\n", state->hero->pos->x, state->hero->pos->y);
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	state->hero_event = 1;
}

void	on_motion_down(t_state *state)
{
	state->hero->pos->y += 1;
	(state->data->nb_steps)++;
	ft_printf("steps: %d \n", state->data->nb_steps);
	//update_cam_pos(state->cam, 1, 0, state->env);
	ft_printf("[on_motion down] hero.pos: x = %d, y = %d\n", state->hero->pos->x, state->hero->pos->y);
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	state->hero_event = 1;
}

void	on_motion_left(t_state *state)
{
	state->hero->pos->x -= 1;
	(state->data->nb_steps)++;
	ft_printf("steps: %d \n", state->data->nb_steps);
	//update_cam_pos(state->cam, 0, -1, state->env);
	ft_printf("[on_motion left] hero.pos: x = %d, y = %d\n", state->hero->pos->x, state->hero->pos->y);
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	state->hero_event = 1;
}

void	on_motion_right(t_state *state)
{
	state->hero->pos->x += 1;
	(state->data->nb_steps)++;
	ft_printf("steps: %d \n", state->data->nb_steps);
	//update_cam_pos(state->cam, 0, 1, state->env);	
	ft_printf("[on_motion right] hero.pos: x = %d, y = %d\n", state->hero->pos->x, state->hero->pos->y);
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	state->hero_event = 1;
}
