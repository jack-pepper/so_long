/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_toolkit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:37:27 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/11 09:30:52 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

int	set_cam(t_state *state)
{
	state->cam = malloc(sizeof(t_cam));
	if (!state->cam)
		return (ft_err(1, "Error\nmalloc cam fail ❌\n"));
	state->cam->pos.y = 0;
	state->cam->pos.x = 0;
	state->cam->max.y = (state->map->tm_rows * RES_PIX) - WIN_HEIGHT;
	if (state->cam->max.y < 0)
		state->cam->max.y = 0;
	state->cam->max.x = (state->map->tm_cols * RES_PIX) - WIN_WIDTH;
	if (state->cam->max.x < 0)
		state->cam->max.x = 0;
	center_cam_on_hero(state->cam, state->hero->pos, state->env);
	return (0);
}

void	check_cam_bounds(t_cam *cam, t_env *env)
{
	env++;
	env--;
	if (cam->pos.x < 0)
		cam->pos.x = 0;
	if (cam->pos.y < 0)
		cam->pos.y = 0;
	if (cam->pos.x > cam->max.x)
		cam->pos.x = cam->max.x;
	if (cam->pos.y > cam->max.y)
		cam->pos.y = cam->max.y;
}

void	center_cam_on_hero(t_cam *cam, t_pos *hero_pos, t_env *env)
{
	cam->pos.y = ((hero_pos->y * RES_PIX - (env->canvas_height / 2)));
	cam->pos.x = ((hero_pos->x * RES_PIX - (env->canvas_width / 2)));
	check_cam_bounds(cam, env);
}

void	update_cam_pos(t_cam *cam, int y_move, int x_move, t_env *env)
{
	if (y_move != 0)
		cam->pos.y += y_move * RES_PIX;
	if (x_move != 0)
		cam->pos.x += x_move * RES_PIX;
	check_cam_bounds(cam, env);
}
