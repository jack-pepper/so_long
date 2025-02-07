/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxkit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:16:07 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/07 21:44:49 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXKIT_H
# define LIBXKIT_H

# define WIN_WIDTH 1620
# define WIN_HEIGHT 780

# define RES_PIX 64

/* Standard libraries */
# include <stdlib.h>
# include <stddef.h>
# include <math.h>

/* MiniLibX libraries */
# include "./.minilibx/mlx.h"
//# include "./.minilibx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Assets */
# include "./assets.h"

/* Custom libraries */
# include "../libft.h"
# include "./libxkit_structs.h"

# include "./mlx_ai_toolkit.h"
# include "./mlx_anim_toolkit.h"
# include "./mlx_audio_toolkit.h"
# include "./mlx_background_render_toolkit.h"
# include "./mlx_camera_toolkit.h"
# include "./mlx_collisions_toolkit.h"
# include "./mlx_color_toolkit.h"
# include "./mlx_debug_toolkit.h"
# include "./mlx_draw_toolkit.h"
# include "./mlx_event_on_motion.h"
# include "./mlx_hero_init_toolkit.h"
# include "./mlx_hero_render_toolkit.h"
# include "./mlx_input_toolkit.h"
# include "./mlx_loop_toolkit.h"
# include "./mlx_map_init_toolkit.h"
# include "./mlx_map_parser_toolkit.h"
# include "./mlx_map_render_toolkit.h"
# include "./mlx_map_validator_toolkit.h"
# include "./mlx_map_validator_flood_count.h"
# include "./mlx_memfree_toolkit.h"
# include "./mlx_particles_toolkit.h"
# include "./mlx_physics_toolkit.h"
# include "./mlx_pixel_toolkit.h"
# include "./mlx_state_init_toolkit.h"
# include "./mlx_tileset_toolkit.h"
# include "./mlx_ui_toolkit.h"
# include "./mlx_utils_toolkit.h"

#endif
