/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_toolkit.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:22:13 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/02 15:32:54 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CAMERA_TOOLKIT_H
# define MLX_CAMERA_TOOLKIT_H

# include "./libxkit.h"

int	set_cam(t_state *state);
void	check_cam_bounds(t_cam *cam, t_env *env);
void	center_cam_on_hero(t_cam *cam, t_pos *hero_pos, t_env *env);
void	update_cam_pos(t_cam *cam, int y_move, int x_move, t_env *env);

#endif
