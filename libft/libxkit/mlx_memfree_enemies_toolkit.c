/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_memfree_enemies_toolkit .c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:10:39 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/14 14:58:31 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	sl_destroy_imgs_enemy(t_state *state)
{
	int	i;

	i = 0;
	while (i < NB_ENEMIES)
	{
		if (state->enemies[i]->to_up)
			mlx_destroy_image(state->env->mlx, state->enemies[i]->to_up);
		if (state->enemies[i]->to_down)
			mlx_destroy_image(state->env->mlx, state->enemies[i]->to_down);
		if (state->enemies[i]->to_left)
			mlx_destroy_image(state->env->mlx, state->enemies[i]->to_left);
		if (state->enemies[i]->to_right)
			mlx_destroy_image(state->env->mlx, state->enemies[i]->to_right);
		i++;
	}
}

void	sl_free_enemies(t_state *state)
{
	int	i;

	i = 0;
	while (i < NB_ENEMIES)
	{
		free(state->enemies[i]->pos);
		free(state->enemies[i]);
		i++;
	}
	free(state->enemies);
}

void	free_paths_enemy(t_state *state)
{
	int	i;

	i = 0;
	while (i < NB_ENEMIES)
	{
		if (state->enemies[i]->to_up_path)
			free(state->enemies[i]->to_up_path);
		if (state->enemies[i]->to_down_path)
			free(state->enemies[i]->to_down_path);
		if (state->enemies[i]->to_left_path)
			free(state->enemies[i]->to_left_path);
		if (state->hero->to_right_path)
			free(state->enemies[i]->to_right_path);
		i++;
	}
}
