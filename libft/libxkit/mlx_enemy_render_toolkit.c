/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_render_toolkit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:03:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 21:26:09 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

/* If the map is smaller than the window, it will be centered.
 * The enemy position is set accordingly.
 */

void	*move_enemy(t_state *state, t_enemy *enemy, void *enemy_sprite)
{
	if (state->current_frame == FRAME_RATE)
	{
		if (enemy->direction == 'u')
		{
			move_to_up(state, enemy, enemy_sprite);
		}
		else if (enemy->direction == 'd')
		{
			move_to_down(state, enemy, enemy_sprite);
		}
		else if (enemy->direction == 'l')
		{
			move_to_left(state, enemy, enemy_sprite);
		}
		else if (enemy->direction == 'r')
		{
			move_to_right(state, enemy, enemy_sprite);
		}
	}
	return (enemy_sprite);
}

void	render_enemy(t_state *state)
{
	t_env	*env;
	void	*enemy_sprite;
	t_pos	enemy_pos;
	int		i;

	env = state->env;
	i = 0;
	while (i < NB_ENEMIES)
	{
		enemy_sprite = state->enemies[i]->to_down;
		if (state->enemies[i]->frame == 0)
			state->enemies[i]->frame = 1;
		if (state->render_event == 3)
			move_enemy(state, state->enemies[i], &enemy_sprite);
		enemy_pos.x = (state->enemies[i]->pos->x * RES_PIX)
			- (state->cam->pos.x);
		enemy_pos.y = (state->enemies[i]->pos->y * RES_PIX)
			- (state->cam->pos.y);
		if (state->map->tm_cols * RES_PIX <= WIN_WIDTH)
			enemy_pos.x += (WIN_WIDTH - (state->map->tm_cols * RES_PIX)) / 2;
		if (state->map->tm_rows * RES_PIX <= WIN_HEIGHT)
			enemy_pos.y += (WIN_HEIGHT - (state->map->tm_rows * RES_PIX)) / 2;
		mlx_show(env->mlx, env->win, enemy_sprite, enemy_pos);
		i++;
	}
}
