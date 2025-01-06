/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:29:47 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/06 01:00:12 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "./so_long.h"

int     check_extension(char *fpath, char *ext);
int	check_shape(char *fpath, size_t *line_len, size_t *nb_lines);
int	check_closed(char *fpath, size_t line_len, size_t nb_lines);
int	check_chars(char *fpath, char *set);
int	check_count(char *fpath, char *set);

#endif
