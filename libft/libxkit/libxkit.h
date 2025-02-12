/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libxkit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:16:07 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 09:28:49 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBXKIT_H
# define LIBXKIT_H

# define WIN_WIDTH 1620
# define WIN_HEIGHT 780
# define RES_PIX 64
# define FRAME_RATE 60
# define NB_ENEMIES 0

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

	/* mlx_ai_toolkit.c */
//void    ai_move_towards_target(t_hero *hero, t_pos target);
//int     ai_decision_state(t_hero *hero);
//void    ai_patrol_area(t_enemy *enemy, t_area *patrol_zone);
//void    ai_follow_hero(t_enemy *enemy, t_hero *hero);

	/* mlx_anim_toolkit.c */
//void animate_sprite(t_sprite *sprite, int frame);
//void start_animation(t_sprite *sprite, int start_frame, int end_frame, //
//float speed);
//void update_sprite_frame(t_sprite *sprite, float delta_time);
//void reset_animation(t_sprite *sprite);

	/* mlx_audio_toolkit.c */
//void    play_sound(const char *sound_file);
//void    stop_sound(void);
//void    set_audio_volume(float volume);
//void    pause_audio(void);
//void    resume_audio(void);

	/* mlx_background_render_toolkit.c */
void	render_background(t_state *state);
//void  set_parallax_background(t_img *background, float speed);
//void  move_background(t_img *background, int delta_x, int delta_y);

	/* mlx_camera_toolkit.c */
int		set_cam(t_state *state);
void	check_cam_bounds(t_cam *cam, t_env *env);
void	center_cam_on_hero(t_cam *cam, t_pos *hero_pos, t_env *env);
void	update_cam_pos(t_cam *cam, int y_move, int x_move, t_env *env);

	/* mlx_collisions_toolkit.c */
int		check_collision_tile(t_pos *p1, t_pos *p2);
int		check_collision_radius(t_pos *p1, t_pos *p2, int rad);
int		check_collision_mult(t_pos *p1, t_enemy **enemies, int rad);

	/* mlx_color_toolkit.c */
int		set_color(t_mlx_color *color);
int		get_color(t_mlx_color *color, char param);
int		rev_color(t_mlx_color *color);
// int  get_gradient_color(t_mlx_color *start, t_mlx color *end, float t);
// int  blend_colors(t_mlx_color *color_1, t_mlx_color *color_2);
	/* mlx_debug_toolkit.c */
//void  draw_hitbox(t_env *env, t_pos pos, int width, int height, int color);
//void  draw_fps(t_env *env, int fps, t_pos pos, int color);

	/* mlx_draw_toolkit.c */
void	draw_mlx_line(t_env *env, t_mlx_line *line);
void	draw_bresenham_line(t_env *env, t_mlx_line *line, t_bres_data *img);
void	draw_mlx_circle(t_env *env, t_mlx_circle *circle);
void	draw_mlx_rect(t_env *env, t_mlx_rect *rect);
void	map_mlx_rect(t_mlx_rect *rect, int sides[4][4]);

	/* mlx_enemy_init_toolkit.c */
void	set_enemy_pos(t_state *state);
int		init_enemy(t_state *state, int nb_enemies);
void	spawn_enemy(t_state *state);

	/* mlx_enemy_render_toolkit.c */
void	render_enemy(t_state *state);
void	*move_enemy(t_state *state, t_enemy *enemy, void *enemy_sprite);

	/* mlx_event_on_motion.c */
void	on_motion_up(t_state *state);
void	on_motion_down(t_state *state);
void	on_motion_left(t_state *state);
void	on_motion_right(t_state *state);

	/* mlx_hero_init_toolkit.c */
int		init_hero(t_state *state);
void	set_hero_pos(t_state *state);

	/* mlx_hero_render_toolkit.c */
void	render_hero(t_state *state);

	/* mlx_input_toolkit.c */
int		on_keypress(int keysym, t_state *state);
void	kp_motion(int keysym, t_state *state);
int		on_destroy(t_state *state);
int		on_resize(int width, int height, t_state *state);

	/* mlx_loop_toolkit.c */

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
	/* mlx_particles_toolkit.c */

	/* mlx_physics_toolkit.c */

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
int		upload_hero(t_state *state);
int		upload_enemy(t_state *state, int nb_enemies);

	/* mlx_ui_toolkit.c */
void	display_steps_on_screen(t_state *state);
//void  draw_health_bar(t_env *env, t_pos pos, int width, int height,// 
//float percent);
//void  draw_score(t_env *env, t_pos pos, int score, int color);
//void  draw_button(t_env *env, t_pos pos, int width, int height, char *text,//
// int color);
//int   is_button_clicked(int button_x, int button_y, int width, 
//int height, int mouse_x, int mouse_y);

	/* mlx_utils_toolkit.c */
void	mlx_show(void *xvar, void *win, void *img, t_pos pos);
void	mlx_draw_to_canvas(t_img *canvas, t_img *sprite, t_pos pos);
int		ft_err(int return_val, char *error_msg);
char	*join_path(char *level, char *file);
/* If separated header files are prefered

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
*/

#endif
