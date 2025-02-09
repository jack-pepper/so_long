/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_parser_toolkit.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:38:29 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 11:38:35 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MAP_PARSER_TOOLKIT_H
# define MLX_MAP_PARSER_TOOLKIT_H

# include "./libxkit.h"

int		check_border(char **arr, int line_len, int nb_lines, char b_chr);
int		check_chars(char **arr, int nb_lines, char *set);
int		check_count(char **arr, int nb_lines, char *set, t_count_req *counter);
void	count_chars(char *str, char *set, int *counter);

#endif
