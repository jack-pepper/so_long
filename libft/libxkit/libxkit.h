/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxkit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:16:07 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/15 10:24:27 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXKIT_H
# define LIBXKIT_H

# define WIN_WIDTH 1620
# define WIN_HEIGHT 780
# define RES_PIX 64
# define FRAME_RATE 60

// Up to 5 enemies
# define NB_ENEMIES 0

// Enemy collision radius
# define DIFFICULTY 0

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

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

	/* mlx_background_render_toolkit.c */
void	render_background(t_state *state);

	/* mlx_camera_toolkit.c */
int		set_cam(t_state *state);
void	check_cam_bounds(t_cam *cam, t_env *env);
void	center_cam_on_hero(t_cam *cam, t_pos *hero_pos, t_env *env);
void	update_cam_pos(t_cam *cam, int y_move, int x_move, t_env *env);

	/* mlx_collisions_toolkit.c */
int		check_collision_tile(t_pos *p1, t_pos *p2);
int		check_collision_radius(t_pos *p1, t_pos *p2, int rad);
int		check_coll_mult(t_pos *p1, t_enemy **enemies, int rad);

	/* mlx_color_toolkit.c */
int		set_color(t_mlx_color *color);
int		get_color(t_mlx_color *color, char param);
int		rev_color(t_mlx_color *color);

	/* mlx_draw_toolkit.c */
void	draw_mlx_line(t_env *env, t_mlx_line *line);
void	draw_bresenham_line(t_env *env, t_mlx_line *line, t_bres_data *img);
void	draw_mlx_circle(t_env *env, t_mlx_circle *circle);
void	draw_mlx_rect(t_env *env, t_mlx_rect *rect);
void	map_mlx_rect(t_mlx_rect *rect, int sides[4][4]);

	/* mlx_enemy_init_toolkit.c */
int		init_enemy(t_state *state, int nb_enemies);
int		upload_enemy(t_state *state, int nb_enemies);
void	set_enemy_data(t_enemy *enemy);
void	set_enemy_pos(t_state *state);
void	spawn_enemy(t_state *state);

	/* mlx_enemy_movement_toolkit.c */
void	move_to_left(t_state *state, t_enemy *enemy);
void	move_to_right(t_state *state, t_enemy *enemy);
void	move_to_down(t_state *state, t_enemy *enemy);
void	move_to_up(t_state *state, t_enemy *enemy);

	/* mlx_enemy_render_toolkit.c */
void	render_enemy(t_state *state);
void	move_enemy(t_state *state, t_enemy *enemy);

	/* mlx_event_on_motion.c */
void	on_motion_up(t_state *state);
void	on_motion_down(t_state *state);
void	on_motion_left(t_state *state);
void	on_motion_right(t_state *state);

	/* mlx_hero_init_toolkit.c */
int		init_hero(t_state *state);
void	set_hero_pos(t_state *state);
int		upload_hero(t_state *state);

	/* mlx_hero_render_toolkit.c */
void	render_hero(t_state *state);

	/* mlx_input_toolkit.c */
int		on_keypress(int keysym, t_state *state);
void	kp_motion(int keysym, t_state *state);
int		on_destroy(t_state *state);

	/* mlx_loop_toolkit.c */
void	update_render(t_state *state);

	/* mlx_map_init_toolkit.c */
int		init_map(t_state *state, char *fpath, char *ext);
int		check_extension(char *fpath, char *ext);
int		set_map_data(t_map *map, char *fpath);
int		get_map_size(t_map *map, int *line_len, int *nb_lines);
int		fconv_arr_chr(char **arr, char *fpath, int nb_lines);

	/* mlx_map_parser_toolkit.c */
int		check_border(char **arr, int line_len, int nb_lines, char b_chr);
int		check_chars(char **arr, int nb_lines, char *set);
int		check_count(char **arr, int nb_lines, char *set, t_count_req *counter);
void	count_chars(char *str, char *set, int *counter);

	/* mlx_map_render_toolkit.c */
void	render_map(t_state *state);
void	rm_put_tiles(t_state *state, int row, int col, int cell_size);

	/* mlx_map_validator_toolkit.c */
char	**copy_map(char **src, t_pos size);
void	set_start_pos(t_state *state, t_pos *start_pos);
int		map_validator(t_state *state);
void	update_flood_count(char tile, int reached[2]);

	/* mlx_map_validator_flood_count.c */
void	flood_count(char **tab, t_pos size, t_pos begin, int reached[2]);
void	flood_count_up(char **tab, t_pos size, t_pos begin, int reached[2]);
void	flood_count_down(char **tab, t_pos size, t_pos begin, int reached[2]);
void	flood_count_left(char **tab, t_pos size, t_pos begin, int reached[2]);
void	flood_count_right(char **tab, t_pos size, t_pos begin, int reached[2]);

	/* mlx_memfree_toolkit.c */
void	sl_memfree(t_state *state);
void	sl_destroy_imgs(t_state *state);
void	sl_free_map(t_state *state);
void	sl_free_all(char **arr);
void	free_paths(t_state *state);

	/* mlx_memfree_enemies_toolkit.c */
void	sl_destroy_imgs_enemy(t_state *state);
void	sl_free_enemies(t_state *state);
void	free_paths_enemy(t_state *state);

	/* mlx_paths_to_assets_toolkit.c */
void	init_assets_to_null(t_state *state);
int		load_paths_tiles(t_state *state, char *level);
int		load_paths_hero(t_state *state, char *level);
int		load_paths_enemy(t_state *state, char *level);
int		load_paths(t_state *state, char *level);

	/* mlx_pixel_toolkit.c */
void	mlx_fast_pixel_put(t_img *img, int x, int y, int color);

	/* mlx_state_init_toolkit.c */
int		init_state(t_state **state);
int		set_state(t_state *state);
int		set_window(t_state *state);
int		set_hooks(t_state *state);
int		set_canvas(t_env *env);

	/* mlx_tileset_toolkit.c */
int		set_map(t_state *state);
int		upload_assets(t_state *state, char *level);
int		upload_tiles(t_state *state);

	/* mlx_ui_toolkit.c */
void	display_steps_on_screen(t_state *state);
void	display_steps_on_terminal(t_state *state);

	/* mlx_utils_toolkit.c */
void	mlx_show(void *xvar, void *win, void *img, t_pos pos);
int		ft_err(int return_val, char *error_msg);
char	*join_path(char *level, char *file);

#endif
