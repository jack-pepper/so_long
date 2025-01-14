/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_state_init_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:03:33 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 15:45:20 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_state_init_toolkit.h"

int	init_state(t_state **state)
{
	*state = malloc(sizeof(t_state));
	if (!*state)
	{
		perror("Error\nstate malloc failed\n");
		return (1);
	}
	(*state)->env = malloc(sizeof(t_env));  // Ensure `env` is allocated.
    	if ((*state)->env == NULL)
    	{
        	perror("Error: malloc failed for env");
        	free(*state);  // Free state if env allocation fails.
        	return 1;
    	}
	return (0);
}

int     set_state(t_state *state)
{
	state->env->mlx = mlx_init();
	if (!state->env->mlx)
		return (1);
	set_window(state);
	//state->env->win = mlx_new_window(state->env->mlx, WIN_WIDTH, WIN_HEIGHT, "So Long");
	set_hooks(state);
	set_canvas(state->env);
	set_map(state);
	upload_assets(state);
	return (0);
}

void	set_window(t_state *state)
{
	state->env->win = mlx_new_window(state->env->mlx, WIN_WIDTH, WIN_HEIGHT, "So Long");
	state->env->canvas_width = WIN_WIDTH;
	state->env->canvas_height = WIN_HEIGHT;
}

void    set_hooks(t_state *state)
{
	t_env	*env;

	env = state->env;
	mlx_hook(env->win, KeyPress, KeyPressMask, &on_keypress, state);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, &on_destroy, env);
//	mlx_hook(env->win, ConfigureNotify, StructureNotifyMask, &on_resize, state);
//      mlx_hook(env->win, 4, 0, mouse_handler, &env); // on mouse down event
//      mlx_hook(env->win, 2, 1L << 0, key_handler, &env); // on key press
//      mlx_hook(env->win, 17, 1L << 0, close_window, &env); // red cross
}

void	set_canvas(t_env *env)
{
	t_img   *c;
	int     endian;

	c = env->canvas;
	c->image = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	c->data = mlx_get_data_addr(c->image, &c->bpp, &c->size_line, &endian);
}
