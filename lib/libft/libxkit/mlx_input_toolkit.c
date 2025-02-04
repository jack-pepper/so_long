/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_toolkit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:05:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/04 14:56:53 by mmalie           ###   ########.fr       */
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
    	mlx_destroy_display(state->env->mlx);
	free(state);
	exit(0);
}

/*
int     on_resize(int width, int height, t_state *state)
{
	int	endian;

	if (!state || !state->env || !state->env->canvas)
		return (ft_error(1, "Error\nstate, env or canvas uninitialized\n"));
	//if (!state->env->canvas_width)
	//	return (ft_error(1, "Error\ncanvas_width uninitialized\n"));
	ft_printf("1-");
	//env = state->env;	
	ft_printf("2-");
	//	
	//
	ft_printf("3-");
	if (state->env->canvas->image)
		mlx_destroy_image(state->env->mlx, state->env->canvas->image);  // Clean up previous image	
	ft_printf("4-");
	state->env->canvas_width = width;
        state->env->canvas_height = height;
	state->env->canvas->image = mlx_new_image(state->env->mlx, width, height);
	ft_printf("5-");
	if (!state->env->canvas->image)
		return (ft_error(1, "Error\nmlx_new_image failed (on_resize)\n"));
	state->env->canvas->data = mlx_get_data_addr(state->env->canvas->image, &state->env->canvas->bpp, &state->env->canvas->size_line, &endian); 
	return (0);
}
*/

//int	on_keyrelease(int keysym, t_state *state)
//int	on_mouseclick(int button, t_pos pos, t_state *state)
//int	on_mousemove(t_pos pos, t_state *state)

// Input mapping (create customizable key bindings)
//void    map_key_to_action(int key, void (*action)(t_state * state));
