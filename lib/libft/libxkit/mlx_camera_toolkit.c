/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_toolkit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:37:27 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/04 18:43:28 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_camera_toolkit.h"

int	set_cam(t_state *state)
{
	state->cam = malloc(sizeof(t_cam));
	if (!state->cam)
		return (ft_error(1, "Error\ncam alloc failed\n"));	
	state->cam->pos.y = 0;
	state->cam->pos.x = 0;
	state->cam->max.y = (state->map->tm_rows * RES_PIX) - WIN_HEIGHT;
	if (state->cam->max.y < 0) state->cam->max.y = 0; // try
	state->cam->max.x = (state->map->tm_cols * RES_PIX) - WIN_WIDTH;
	if (state->cam->max.x < 0) state->cam->max.x = 0;
	//state->cam->max.y = state->map->height / RES_PIX;
	//state->cam->max.x = state->map->width / RES_PIX;
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
	//if ((cam->pos.x) > ((cam->max.x) - env->canvas_width))
	//	cam->pos.x = ((cam->max.x) - env->canvas_width);
	//if ((cam->pos.y) < ((cam->max.y) - env->canvas_height))
	//	cam->pos.y = ((cam->max.y) - env->canvas_height);
}

void	center_cam_on_hero(t_cam *cam, t_pos *hero_pos, t_env *env)
{
	cam->pos.y = ((hero_pos->y * RES_PIX - (env->canvas_height / 2)));
	cam->pos.x = ((hero_pos->x * RES_PIX - (env->canvas_width / 2)));
	//cam->pos.y = ((hero_pos->y));
	//cam->pos.x = ((hero_pos->x));
	//if (cam->max.x < 0)
	//	cam->pos.x = 0;
	//if (cam->max.y < 0)
	//	cam->pos.y = 0;
//	ft_printf("[center_cam_on_hero, before check bounds] Centered: cam.pos.x: %d - cam.pos.y: %d\n", cam->pos.x, cam->pos.y);
	check_cam_bounds(cam, env);
//	ft_printf("[center_cam_on_hero, after check bounds] Centered: cam.pos.x: %d - cam.pos.y: %d\n", cam->pos.x, cam->pos.y);
}

void	update_cam_pos(t_cam *cam, int y_move , int x_move, t_env *env)
{
	if (y_move != 0)
		cam->pos.y += y_move * RES_PIX;
	if (x_move != 0)
		cam->pos.x += x_move * RES_PIX;
	check_cam_bounds(cam, env);	
//	ft_printf("[update_cam_pos] Centered: cam.pos.x: %d - cam.pos.y: %d\n", cam->pos.x, cam->pos.y);
}
