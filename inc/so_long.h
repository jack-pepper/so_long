/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/14 12:01:18 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 1620
# define WIN_HEIGHT 780

/* External libraries */
# include <errno.h>
# include <math.h>
# include "../lib/libft/libxkit/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>


# include "assets.h"

/* Custom libraries */
# include "../lib/libft/libft.h"
# include "../lib/libft/libxkit/libxkit.h"
# include "./map_validator.h"

int	map_parser(t_state *state);
int	init_state(t_state **state);
int     render(t_state *state);
void	update_render(t_state *state);
void    on_events(t_state *state);
void    set_counter_req(t_count_req *counter);

#endif
