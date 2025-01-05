/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:29:47 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/05 14:43:53 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	map_parser(t_game *game, int argc, char **argv);
int     check_extension(char *filepath, char *ext);
int	check_shape(char *filepath, size_t *line_len, size_t *nb_lines);
int	check_closed(char *filepath, size_t line_len, size_t nb_lines);
void	init_map(t_game *game, char *filepath, size_t line_len, size_t nb_lines);
int	check_chars(char *filepath, size_t line_len, size_t nb_lines, char *set);
