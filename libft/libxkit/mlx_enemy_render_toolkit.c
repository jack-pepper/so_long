/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_render_toolkit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:03:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 13:58:04 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

/* If the map is smaller than the window, it will be centered.
 * The enemy position is set accordingly.
 */

void	render_enemy(t_state *state)
{
	t_env	*env;
	t_pos	enemy_pos;
	int		i;

	env = state->env;
	i = 0;
	while (i < NB_ENEMIES)
	{
		if (state->enemies[i]->frame == 0)
			state->enemies[i]->frame = 1;
		if (state->render_event == 3)
			move_enemy(state, state->enemies[i]);
		enemy_pos.x = (state->enemies[i]->pos->x * RES_PIX)
			- (state->cam->pos.x);
		enemy_pos.y = (state->enemies[i]->pos->y * RES_PIX)
			- (state->cam->pos.y);
		if (state->map->tm_cols * RES_PIX <= WIN_WIDTH)
			enemy_pos.x += (WIN_WIDTH - (state->map->tm_cols * RES_PIX)) / 2;
		if (state->map->tm_rows * RES_PIX <= WIN_HEIGHT)
			enemy_pos.y += (WIN_HEIGHT - (state->map->tm_rows * RES_PIX)) / 2;
		mlx_put_image_to_window(env->mlx, env->win,
			state->enemies[i]->current_sprite, enemy_pos.x, enemy_pos.y);
		i++;
	}
}

void	move_enemy(t_state *state, t_enemy *enemy)
{
	if (state->current_frame == FRAME_RATE)
	{
		if (enemy->direction == 'u')
		{
			move_to_up(state, enemy);
		}
		else if (enemy->direction == 'd')
		{
			move_to_down(state, enemy);
		}
		else if (enemy->direction == 'l')
		{
			move_to_left(state, enemy);
		}
		else if (enemy->direction == 'r')
		{
			move_to_right(state, enemy);
		}
	}
}
