/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_toolkit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:57:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/15 10:15:36 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INPUT_TOOLKIT_H
# define MLX_INPUT_TOOLKIT_H

# include "./libxkit.h"

int		on_keypress(int keysym, t_state *state);
void	kp_motion(int keysym, t_state *state);
int		on_destroy(t_state *state);
int	on_resize(int width, int height, t_state *state);

#endif
