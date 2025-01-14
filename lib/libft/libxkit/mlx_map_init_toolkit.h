/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_init_toolkit.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:16:06 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/13 11:28:45 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MAP_INIT_TOOLKIT_H
# define MLX_MAP_INIT_TOOLKIT_H

# include "./libxkit.h"

int	init_map(t_state *state, char *fpath, char *ext);
int	check_extension(char *fpath, char *ext);
int	set_map_data(t_state *state, t_map *map, char *fpath);
int	get_map_size(t_state *state, int *line_len, int *nb_lines);
int	fconv_arr_chr(char **arr, char *fpath, int nb_lines);

#endif
