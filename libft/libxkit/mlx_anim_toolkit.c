/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_anim_toolkit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:53:58 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/13 11:55:34 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h" 

/*
void    draw_sprite_frame(t_env *env, t_img *sprite, int frame, t_pos *pos);

void    animate_frames(t_img *frames[], int frame_count, int delay)
{
	
}
*/

/* XXX Sprite and animation utilities
t_sprite        *load_sprite(void *mlx, char *path);
{
	t_img	*sprite;
	int	width;
	int	height;

	sprite = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!sprite)
	{
		return (1);
	}
	return (sprite);
}


void    draw_sprite(t_env *env, t_img *sprite, t_pos pos)
{
	mlx_show(env->mlx, env->win, sprite, pos->x, pos->y);
}


void    draw_spr_frm(t_env *env, t_img *sprite_sheet, int t_frame frame_data);
 // need sprite width and pos

int     update_animation(int *current_frame, int frame_count, int frame_delay)
{
	
	if (*current_frame == frame_count)
		*current_frame == 0;
	else
		*current_frame++;
	return (*current_frame);
}
*/
