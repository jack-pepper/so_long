/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 00:07:58 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/05 19:02:34 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_h

# include "./so_long.h"

int	render(t_game *game);
void	render_background(t_env *env);
void	render_map(t_game *game);
void	render_hero(t_game *game);

#endif
