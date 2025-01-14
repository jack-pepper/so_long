/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_toolkit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:57:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 15:12:03 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INPUT_TOOLKIT_H
# define MLX_INPUT_TOOLKIT_H

# include "./libxkit.h"

int		on_keypress(int keysym, t_state *state);
void	kp_motion(int keysym, t_state *state);
int		on_destroy(t_env *env);
int	on_resize(int win_width, int win_height, t_state *state);

#endif
