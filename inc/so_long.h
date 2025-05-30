/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 11:06:07 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 1620
# define WIN_HEIGHT 780

# define PROG_NAME "So long"

/* External libraries */
# include <errno.h>
# include <math.h>
# include "../libft/libxkit/.minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# include "../textures/assets.h"

/* Custom libraries */
# include "../libft/libft.h"
# include "../libft/libxkit/libxkit.h"

int		map_parser(t_state *state);
int		init_state(t_state **state);
int		init_data(t_state *state, t_data *data, int step);
int		render(t_state *state);
void	on_events(t_state *state);
void	set_counter_req(t_count_req *counter);

// Events
int		on_coll_tile(t_state *state, t_pos *pos);
void	on_exit_tile(t_state *state);
void	on_enemy_tile(t_state *state);
int		ls_bonus_check(char **argv);

// Screens
void	display_start_screen(void);
void	display_victory_screen(void);
void	display_defeat_screen(void);

// Levels
int		change_level(t_state *state);

#endif
