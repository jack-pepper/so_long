/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy_render_toolkit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:03:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 10:06:51 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

/* If the map is smaller than the window, it will be centered.
 * The enemy position is set accordingly.
 */

void	*move_enemy(t_state *state, t_enemy *enemy, void *enemy_sprite)
{
	if (enemy->frame == 1)
	{
		enemy_sprite = enemy->to_up;
		enemy->pos->y -= 1;
		enemy->frame = 2;
	}
	else if (state->current_frame == FRAME_RATE && enemy->frame == 2)
	{
		enemy_sprite = enemy->to_down;
		enemy->pos->y += 1;
		enemy->frame = 1;
	}
	else if (state->current_frame == FRAME_RATE && enemy->frame == 3)
	{
		enemy_sprite = enemy->to_left;
		enemy->pos->x -= 1;
		enemy->frame = 4;
	}
	else if (state->current_frame == FRAME_RATE && enemy->frame == 4)
	{
		enemy_sprite = enemy->to_right;
		enemy->pos->x += 1;
		enemy->frame = 1;
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
	while (state->enemies[i] != NULL)
	{
	//	ft_printf("enemy 0 pos x: %d | pos y: %d | frame: %d\n",
	//		state->enemies[0]->pos->x, state->enemies[0]->pos->y, state->enemies[0]->frame);
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
		//mlx_show(env->mlx, env->win, enemy_sprite, enemy_pos);
		mlx_put_image_to_window(env->mlx, env->win,
                        enemy_sprite, enemy_pos.x, enemy_pos.y);
		i++;	
	}
}
