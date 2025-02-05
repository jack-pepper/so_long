/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_toolkit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:05:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 21:38:19 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_input_toolkit.h"

/* Keyboard input handling */

// Handles keyboard input: ESC + WASD or arrows
int	on_keypress(int keysym, t_state *state)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(state->env->mlx, state->env->win);
		exit(0);
	}
	else if ((keysym == XK_w || keysym == XK_Up)
		|| (keysym == XK_a || keysym == XK_Left)
		|| (keysym == XK_s || keysym == XK_Down)
		|| (keysym == XK_d || keysym == XK_Right))
	{
		kp_motion(keysym, state);
	}
	return (0);
}

// If next pos is reachable, move hero to next pos. 
void	kp_motion(int keysym, t_state *state)
{
	char	**tilemap;
	t_pos	*hero_pos;

	tilemap = state->map->tilemap;
	hero_pos = state->hero->pos;
	if ((keysym == XK_w || keysym == XK_Up)
		&& (tilemap[hero_pos->y - 1][hero_pos->x] != '1'))
	{
		on_motion_up(state);
	}
	else if ((keysym == XK_a || keysym == XK_Left)
		&& (tilemap[hero_pos->y][hero_pos->x - 1] != '1'))
	{
		on_motion_left(state);
	}
	else if ((keysym == XK_s || keysym == XK_Down)
		&& (tilemap[hero_pos->y + 1][hero_pos->x] != '1'))
	{
		on_motion_down(state);
	}
	else if ((keysym == XK_d || keysym == XK_Right)
		&& (tilemap[hero_pos->y][hero_pos->x + 1] != '1'))
	{
		on_motion_right(state);
	}
}

int	on_destroy(t_state *state)
{
/*
	if (!state)
		return (0);
	if (state->map)
	{
        	if (state->map->tilemap)
            		free(state->map->tilemap);
        	if (state->map->tileset)
		{
			int i = 0;
			while (i < 3)
			{
				if (state->map->tileset[i])
				{
					mlx_destroy_image(state->env->mlx, state->map->tileset[i]->sprite);
					free(state->map->tileset[i]);
				}
				i++;
			}
            		free(state->map->tileset);
		}
		if (state->map->tile_count)
	   		free(state->map->tile_count);
        	free(state->map);
    }
    if (state->hero)
    {
    	if (state->hero->pos)
        	free(state->hero->pos);
        free(state->hero);
    }
    if (state->env && state->env->canvas)
    {
        if (state->env->canvas->image)
        {
        	mlx_destroy_image(state->env->mlx, state->env->canvas->image);
        }
        free(state->env->canvas);
        state->env->canvas = NULL;
    }
    if (state->env && state->env->win)
    {
        mlx_destroy_window(state->env->mlx, state->env->win);
        state->env->win = NULL;
    }
    if (state->env && state->env->mlx)
    {
        mlx_destroy_display(state->env->mlx);
        free(state->env->mlx);
    }
    if (state->env)
    {
        free(state->env);
    }*/
	mlx_destroy_image(state->env->mlx, state->map->tilemap[0]);
	mlx_destroy_image(state->env->mlx, state->map->tilemap[1]);
	mlx_destroy_image(state->env->mlx, state->map->tilemap[2]); // etc
	mlx_destroy_display(state->env->mlx);
	free(state->env->mlx);
	state->env->mlx = NULL;	
	free(state);
	exit(0);
}

//int	on_keyrelease(int keysym, t_state *state)
//int	on_mouseclick(int button, t_pos pos, t_state *state)
//int	on_mousemove(t_pos pos, t_state *state)

// Input mapping (create customizable key bindings)
//void    map_key_to_action(int key, void (*action)(t_state * state));
