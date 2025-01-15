/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_toolkit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:37:27 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/15 23:14:31 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_camera_toolkit.h"

int	set_cam(t_state *state)
{
	state->cam = malloc(sizeof(t_cam));
	if (!state->cam)
		return (ft_error(1, "Error\ncam alloc failed\n"));
	state->cam->max.y = state->map->height - state->env->canvas->height;
	state->cam->max.x = state->map->width - state->env->canvas->width;
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	return (0);
}

void	check_cam_bounds(t_cam *cam, t_env *env)
{	
	if (cam->pos.x < 0)
		cam->pos.x = 0;
	if (cam->pos.y < 0)
		cam->pos.y = 0;
	if ((cam->pos.x) > ((cam->max.x) - env->canvas_width))
		cam->pos.x = ((cam->max.x) - env->canvas_width);
	if ((cam->pos.y) < ((cam->max.y) - env->canvas_height))
		cam->pos.y = ((cam->max.y) - env->canvas_height);
}

void	center_cam_on_hero(t_cam *cam, t_pos *hero_pos, t_env *env)
{
	cam->pos.y = hero_pos->y - (env->canvas_height / 2);
	cam->pos.x = hero_pos->x - (env->canvas_width / 2);
	check_cam_bounds(cam, env);
}

void	update_cam_pos(t_cam *cam, int y_move , int x_move, t_env *env)
{
	cam->pos.y += y_move;
	cam->pos.x += x_move;
	check_cam_bounds(cam, env); 
}
