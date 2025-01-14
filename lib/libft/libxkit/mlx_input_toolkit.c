/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_toolkit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:05:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 15:24:23 by mmalie           ###   ########.fr       */
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
		hero_pos->y -= 1;
	else if ((keysym == XK_a || keysym == XK_Left)
		&& (tilemap[hero_pos->y][hero_pos->x - 1] != '1'))
		hero_pos->x -= 1;
	else if ((keysym == XK_s || keysym == XK_Down)
		&& (tilemap[hero_pos->y + 1][hero_pos->x] != '1'))
		hero_pos->y += 1;
	else if ((keysym == XK_d || keysym == XK_Right)
		&& (tilemap[hero_pos->y][hero_pos->x + 1] != '1'))
		hero_pos->x += 1;
	return ;
}

int	on_destroy(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(0);
	return (0);
}

int     on_resize(int win_width, int win_height, t_state *state)
{
        state->env->canvas_width = win_width;
        state->env->canvas_height = win_height;
        return (0);
}


//int	on_keyrelease(int keysym, t_state *state)
//int	on_mouseclick(int button, t_pos pos, t_state *state)
//int	on_mousemove(t_pos pos, t_state *state)

// Input mapping (create customizable key bindings)
//void    map_key_to_action(int key, void (*action)(t_state * state));
