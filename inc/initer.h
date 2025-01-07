/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:42:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/07 20:09:34 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITER_H
# define INITER_H

# include "./so_long.h"

void	set_hooks(t_game *game);
void	set_canvas(t_env *env);
void	set_map(t_game *game);
int		calc_cell_size(t_game *game);
void	upload_assets(t_game *game);

#endif
