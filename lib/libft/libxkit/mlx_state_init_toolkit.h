/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_state_init_toolkit.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:13:33 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 14:59:21 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STATE_INIT_H
# define MLX_STATE_INIT_H

# include "./libxkit.h"

int	init_state(t_state **state);
int	set_state(t_state *state);
void	set_window(t_state *state);
void	set_hooks(t_state *state);
void	set_canvas(t_env *env);

#endif
