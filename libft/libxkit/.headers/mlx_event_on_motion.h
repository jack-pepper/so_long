/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_on_motion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:20:41 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/15 19:28:58 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EVENT_ON_MOTION_H
# define MLX_EVENT_ON_MOTION_H

# include "./libxkit.h"

void	on_motion_up(t_state *state);
void	on_motion_down(t_state *state);
void	on_motion_left(t_state *state);
void	on_motion_right(t_state *state);

#endif
