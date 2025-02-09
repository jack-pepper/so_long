/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ui_toolkit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:09:06 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/09 21:19:49 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

void	display_steps_on_screen(t_state *state)
{
	static char	steps_msg[8] = "STEPS: ";
	char		*nb_steps;
	char		*final_msg;

	nb_steps = ft_itoa(state->data->nb_steps);
	final_msg = ft_strjoin(steps_msg, nb_steps);
	mlx_string_put(state->env->mlx, state->env->win,
		50, 50, 0xFFFFFF, final_msg);
	free(nb_steps);
	free(final_msg);
}
