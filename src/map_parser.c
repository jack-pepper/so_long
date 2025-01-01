/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:26:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/02 00:46:08 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// NB: need to implement 	*ft_strpbrk(const char *s1, const char *s2)
// and size_t	ft_strcspn(const char *s, const char *reject);
/*int	check_chars(t_game *game, char *set)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while ()
}*/

void	init_map(t_game *game, char *filepath, size_t line_len, size_t nb_lines)
{
	t_map	*map;
	char	**tilemap;
	char	*tilemap_line;
	size_t	i;
	int	file;

	file = open(filepath, O_RDONLY);
	map = malloc(sizeof(t_map));
        if (!map)
                return ;
        game->map = map;
	game->map->filepath = filepath;
	tilemap = malloc(sizeof(char *) * (nb_lines));
	if (!tilemap)
		return ;
	game->map->tilemap = tilemap;
	game->map->tm_rows = nb_lines;
	game->map->tm_cols = line_len;
	i = 0;
	while (i <= nb_lines)
	{
		tilemap_line = ft_gnl(file);
//		ft_printf("%s", tilemap_line);
		if (!tilemap_line)
			return ;
		game->map->tilemap[i] = tilemap_line;
		ft_printf("%s", game->map->tilemap[i]);
		i++;
		//free(tilemap_line);
	//	ft_printf("mallocated %d lines\n", i);
	}
}

// Parsing settings: 
//	argc = 2
//	extension = .ber
//	shape = rect
//	components = 3 (wall, coll, empty)
//	char = 0 (empty); 1 (wall); C (coll); E (exit); P (hero's start pos)
//	map closed by wall
//	valid path!!!
int	map_parser(t_game *game, int argc, char **argv)
{	
	char	filepath[256]; // CHANGE TO MALLOC
	size_t	line_len;
	size_t	nb_lines;

	if (argc != 2)
        {
                ft_printf("Invalid args (needed .ber map)!\n");
                return (1);
        }
	ft_strlcpy(filepath, argv[1], ft_strlen(argv[1]) + 1);
	ft_printf("FILEPATH: %s\n", filepath);
        if (check_extension(filepath, ".ber") != 0)
        {
                ft_printf("Not a .ber file!\n");
                return (1);
        }
        ft_printf("Correct filetype .ber!\n");
	line_len = 0;
	nb_lines = 0;
	if (check_shape(filepath, &line_len, &nb_lines) != 0)
	{
//		ft_printf("Map IS NOT rectangular!\n");
		return (1);
	}
	ft_printf("Map IS rectangular!\n");
	init_map(game, filepath, line_len, nb_lines);
	check_chars(game, "01CEP");
	check_closed(game, line_len, nb_lines);
	return (0);
}

int     check_extension(char *filepath, char *extension)
{
        int     i;
        int     j;

        i = ft_strlen(extension) - 1;
        j = ft_strlen(filepath) - 1;
        printf("ext index: %d - filepath index: %d\n", i, j);
        while (i >= 0)
        {
                if (filepath[j] != extension[i])
                        return (1);
                printf("filepath[j]: %c - extension[i]: %c\n", filepath[j], extension[i]);
                i--;
                j--;
        }
        ft_printf("Matching extensions!\n");
        return (0);
}

int	check_shape(char *filepath, size_t *line_len, size_t *nb_lines)
{
	int	file;
	char	*line;
	
	file = open(filepath, O_RDONLY);
	line = ft_gnl(file);
	(*nb_lines)++;
	if (line == NULL)
	{
		close(file);
		return (1);
	}
	ft_printf("%s", line);
	*line_len = ft_strlen(line);
	ft_printf("[ft check_shape] line_len: %d\n", ft_strlen(line));
	while (1)
	{
		line = ft_gnl(file);
		if (line == NULL)
		{
			close(file);
			break ;
		}
		ft_printf("%s", line);
		if (ft_strlen(line) != *line_len)
		{
			ft_printf("Non-rectangular map!\n");
			close(file);
			return (1);
		}
		(*nb_lines)++;
	}
//	ft_printf("The map is rectangular!\n");
	close(file);
	return (0);
}

int	check_closed(t_game *game, size_t line_len, size_t nb_lines)
{	
	char	**tilemap;
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	ft_printf("line_len: %d - nb_lines: %d\n", line_len, nb_lines);
	tilemap = game->map->tilemap;
	line_len--;
	nb_lines--;
	while (col < line_len)
	{	
		//ft_printf("[%d, %d] %c\n", row, col, tilemap[0][col]);
		//ft_printf("[%d, %d] %c\n", row, col, tilemap[nb_lines][col]);
		if ((tilemap[0][col] != '1')
			|| (tilemap[nb_lines][col] != '1'))
		{
			ft_printf("1/Map not closed: tilemap[%d][%d]!\n", row, col);
			return (1);
		}
		col++;
	}
	col = 0;
	while (row <= nb_lines)
	{	
		//ft_printf("[%d,%d] %c\n", row, col, tilemap[row][0]);	
		//ft_printf("[%d,%d] %c\n", row, col, tilemap[row][line_len - 1]);
		if ((tilemap[row][0] != '1')
			|| (tilemap[row][line_len - 1] != '1'))
		{
			ft_printf("2/Map not closed: tilemap[%d][%d]!\n", row, col);
			return (1);
		}
		row++;
	}
	ft_printf("Map is closed, good!\n");
	return (0);
}
