/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_state_init_toolkit.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:13:33 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 19:10:11 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STATE_INIT_H
# define MLX_STATE_INIT_H

# include "./libxkit.h"

int	init_state(t_state **state);
int	set_state(t_state *state);
int	set_window(t_state *state);
int	set_hooks(t_state *state);
int	set_canvas(t_env *env);

#endif
