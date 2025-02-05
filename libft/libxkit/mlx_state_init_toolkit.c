/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_state_init_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:03:33 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 11:49:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_state_init_toolkit.h"

int	init_state(t_state **state)
{
	*state = malloc(sizeof(t_state));
	if (!*state)
		return (ft_error(1, "Error\nstate malloc failed\n"));
	ft_memset(*state, 0, sizeof(t_state));
	(*state)->env = malloc(sizeof(t_env));
	if ((*state)->env == NULL)
	{
		free(*state);
		return (ft_error(1, "Error\n[init_state] env malloc failed\n"));
	}
	ft_memset((*state)->env, 0, sizeof(t_env));
	(*state)->env->canvas = malloc(sizeof(t_img));
	if ((*state)->env->canvas == NULL)
	{
		free((*state)->env);
		free(*state);
		return (ft_error(1, "Error\n[init_state] canvas malloc failed\n"));
	}
	ft_memset((*state)->env->canvas, 0, sizeof(t_img));
	(*state)->env->canvas_width = WIN_WIDTH;
	(*state)->env->canvas_height = WIN_HEIGHT;
	(*state)->env->mlx = NULL;
	(*state)->bkgd_event = 1;
	(*state)->map_event = 1;
	(*state)->hero_event = 1;
	return (0);
}

int     set_state(t_state *state)
{
	ft_printf("[set_state 0] Setting state...\n");
	state->env->mlx = mlx_init();
	if (!state->env->mlx)
		return (ft_error(1, "Error\nmlx_init failed\n"));
	ft_printf("[1] mlx set\n");
	if (set_window(state) != 0)
		return (ft_error(1, "Error\nset_window failed\n"));
	ft_printf("[2] window set\n");
	if (set_hooks(state) != 0)
		return (ft_error(1, "Error\nset_hooks failed\n"));
	ft_printf("[3] hooks set\n");
	if (set_canvas(state->env) != 0)
		return (ft_error(1, "Error\nset_canvas failed\n"));
	ft_printf("[4] canvas set\n");
	if (set_map(state) != 0)	
		return (ft_error(1, "Error\nset_map failed\n"));
	ft_printf("[5] map set\n");
	if (upload_assets(state) != 0)
		return (ft_error(1, "Error\nupload_assets failed\n"));
	ft_printf("[6] assets... uploaded\n");
	if (set_cam(state) != 0)
		return (ft_error(1, "Error\nset_cam failed\n"));
	ft_printf("[7] State set successfully!\n");
	return (0);
}

int	set_window(t_state *state)
{
	void	*win;

	win = mlx_new_window(state->env->mlx, WIN_WIDTH, WIN_HEIGHT, "So Long");
	if (!win)
		return (ft_error(1, "Error\nmlx_new_window failed\n"));	
	state->env->win = win;
	return (0);
}

int    set_hooks(t_state *state)
{
	t_env	*env;

	env = state->env;
	mlx_hook(env->win, KeyPress, KeyPressMask, &on_keypress, state);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, &on_destroy, env);
//	mlx_hook(env->win, ConfigureNotify, StructureNotifyMask, &on_resize, state);
//      mlx_hook(env->win, 4, 0, mouse_handler, &env); // on mouse down event
//      mlx_hook(env->win, 2, 1L << 0, key_handler, &env); // on key press
//      mlx_hook(env->win, 17, 1L << 0, close_window, &env); // red cross
	return (0);
}

int	set_canvas(t_env *env)
{
	t_img   *c;
	int     endian;

	c = env->canvas;
	if (!c)
		return (ft_error(1, "Error\ncanvas uninitialized\n"));
	c->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!c->img)
		return (ft_error(1, "Error\nmlx_new_image failed\n"));
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->l_len, &endian);	
	if (!c->addr)
		return (ft_error(1, "Error\nmlx_get_data_addr failed\n"));
	c->width = WIN_WIDTH;
	c->height = WIN_WIDTH;
	return (0);
}
