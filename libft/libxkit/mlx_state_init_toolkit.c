/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_state_init_toolkit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:03:33 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/14 23:11:43 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

int	init_state(t_state **state)
{
	*state = malloc(sizeof(t_state));
	if (!*state)
		return (ft_err(1, "Error\n[init_state] state fail ❌\n"));
	ft_memset(*state, 0, sizeof(t_state));
	(*state)->env = malloc(sizeof(t_env));
	if ((*state)->env == NULL)
	{
		free(*state);
		return (ft_err(1, "Error\n[init_state] env fail ❌\n"));
	}
	ft_memset((*state)->env, 0, sizeof(t_env));
	(*state)->env->canvas = malloc(sizeof(t_img));
	if ((*state)->env->canvas == NULL)
	{
		free((*state)->env);
		free(*state);
		return (ft_err(1, "Error\n[init_state] canvas fail ❌\n"));
	}
	ft_memset((*state)->env->canvas, 0, sizeof(t_img));
	(*state)->env->canvas_width = WIN_WIDTH;
	(*state)->env->canvas_height = WIN_HEIGHT;
	(*state)->env->mlx = NULL;
	(*state)->error_code = 1;
	return (0);
}

int	set_state(t_state *state)
{
	state->env->mlx = mlx_init();
	if (!state->env->mlx)
		return (ft_err(1, "Error\nmlx_init FAIL! 💀\n"));
	ft_printf("🔌 [1] mlx: ✅ READY!\n");
	if (set_window(state) != 0)
		return (ft_err(1, "Error\nset_window FAIL! 💀\n"));
	ft_printf("🖥️  [2] window: ✅ CREATED!\n");
	if (set_hooks(state) != 0)
		return (ft_err(1, "Error\nset_hooks FAIL! 💀\n"));
	ft_printf("🎮 [3] hooks: ✅ CONNECTED!\n");
	if (set_canvas(state->env) != 0)
		return (ft_err(1, "Error\nset_canvas FAIL! 💀\n"));
	ft_printf("🖌️  [4] canvas: ✅ PAINTED!\n");
	if (set_map(state) != 0)
		return (ft_err(1, "Error\nset_map FAIL 💀\n"));
	ft_printf("🗺️  [5] game map: ✅ LOADED!\n");
	if (upload_assets(state, PATH_BASIC) != 0)
		return (ft_err(1, "Error\nupload_assets FAIL 💀\n"));
	ft_printf("📦 [6] sprites: ✅ TEXTURED!\n");
	if (set_cam(state) != 0)
		return (ft_err(1, "Error\nset_cam FAIL 💀\n"));
	ft_printf("🎥 [7] camera: ✅ POSITIONED!\n");
	ft_printf("\n🚀 STATE SET, GAME READY! 🕹️\n");
	return (0);
}

int	set_window(t_state *state)
{
	void	*win;

	win = mlx_new_window(state->env->mlx, WIN_WIDTH, WIN_HEIGHT, "So Long");
	if (!win)
		return (ft_err(1, "Error\nmlx_new_window fail ❌\n"));
	state->env->win = win;
	return (0);
}

int	set_hooks(t_state *state)
{
	t_env	*env;

	env = state->env;
	mlx_hook(env->win, KeyPress, KeyPressMask, &on_keypress, state);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, &on_destroy, state);
	return (0);
}

int	set_canvas(t_env *env)
{
	t_img	*c;
	int		endian;

	c = env->canvas;
	if (!c)
		return (ft_err(1, "Error\ncanvas uninitialized ❌\n"));
	c->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!c->img)
		return (ft_err(1, "Error\nmlx_new_image fail ❌\n"));
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->l_len, &endian);
	if (!c->addr)
		return (ft_err(1, "Error\nmlx_get_data_addr failed ❌\n"));
	c->width = WIN_WIDTH;
	c->height = WIN_WIDTH;
	return (0);
}
