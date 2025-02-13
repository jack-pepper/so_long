/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_toolkit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:05:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 14:00:23 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

/* Keyboard input handling */

// Handles keyboard input: ESC + WASD or arrows
int	on_keypress(int keysym, t_state *state)
{
	if (keysym == XK_Escape)
	{
		ft_printf("🐟 [ESC] Leaving already? So long! 👋\n");
		sl_memfree(state);
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
	ft_printf("[on_destroy] Free all! 🧹\n");
	sl_memfree(state);
	exit(0);
	return (0);
}
