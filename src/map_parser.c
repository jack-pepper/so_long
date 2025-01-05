/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:26:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/05 15:18:40 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
                perror("Error\nInvalid number of arguments (req: 1)\n");
                return (1);
        }
	ft_strlcpy(filepath, argv[1], ft_strlen(argv[1]) + 1);
	ft_printf("FILEPATH: %s\n", filepath);
        if (check_extension(filepath, ".ber") != 0)
                return (1);
        ft_printf("Correct extension (req: .ber)\n"); // DEBUG
	line_len = 0;
	nb_lines = 0;
	if (check_shape(filepath, &line_len, &nb_lines) != 0)
		return (1);
	ft_printf("Correct map shape (req: rect)!\n"); // DEBUG
	if (check_closed(filepath, line_len, nb_lines) != 0)
		return (1);
	if (check_chars(filepath, line_len, nb_lines, "01CEP\n") != 0) // Should the nl char be accepted?
		return (1);
	ft_printf("Correct chars (req: 0, 1, C>1, Ex1, Px1)\n"); // DEBUG
	init_map(game, filepath, line_len, nb_lines);
	return (0);
}

int	check_extension(char *filepath, char *ext)
{
	int     i;
        int     j;

        i = ft_strlen(ext) - 1;
        j = ft_strlen(filepath) - 1;
        while (i >= 0)
        {
                if (filepath[j] != ext[i])
		{
			ft_printf("Error\nInvalid extension (req: %s)\n", ext); // Should be displayed to stderror!
                        return (1);
		}
                i--;
                j--;
        }
        return (0);
}

int	check_shape(char *filepath, size_t *line_len, size_t *nb_lines)
{
	int	file;
	char	*line;

	file = open(filepath, O_RDONLY);
	if (file == -1)
	{
		perror("Error\nError opening file\n");
		return (1);
	}
	while (1)
	{
		line = ft_gnl(file);
		if (line == NULL)
			break ;
		if (*nb_lines == 0)
			*line_len = ft_strlen(line);
		if (ft_strlen(line) != *line_len)
		{
			perror("Error\nInvalid map shape (req: rect)\n");
			close(file);
			return (1);
		}
		(*nb_lines)++;
	}
	close(file);
	return (0);
}

int	check_closed(char *filepath, size_t line_len, size_t nb_lines)
{
	int	file;
	char	*line;
	size_t	line_nb;

	file = open(filepath, O_RDONLY);
	line_nb = 0;
	line_len = line_len - 2;
	while (line_nb < nb_lines)
	{
		line = ft_gnl(file);
		if (line == NULL)
		{
			close(file);
			break ;
		}
		line_nb++;
		if ((line_nb == 1 && ft_strnopbrk(line, "1\n") != NULL)
			|| (line_nb == nb_lines && ft_strnopbrk(line, "1\n") != NULL)
			|| ((line_nb > 1 && line_nb < nb_lines)
				&& (line[0] != '1' || line[line_len] != '1')))
		{
			ft_printf("Error at line %d\n", line_nb);
			ft_printf("line[0] = %c - line[line_len] = %c\n", line[0], line[line_len]);
			perror("Error\nInvalid: map not closed\n");
			close(file);
			return (1);
		}
	}
	close(file);
	ft_printf("Map closed!\n");
	return (0);
}

int	check_chars(char *filepath, size_t line_len, size_t nb_lines, char *set)
{
	int	file;
	char	*line;
	size_t	line_nb;

	file = open(filepath, O_RDONLY);
	line_nb = 0;
	line_len = line_len - 2;
	while (line_nb < nb_lines)
	{
		line = ft_gnl(file);
		if (line == NULL)
		{
			close(file);
			break ;
		}
		line_nb++;
		if (ft_strnopbrk(line, set) != NULL)
		{
			ft_printf("Error at line %d\n", line_nb);
			perror("Error\nInvalid char (req: set)\n");
			close(file);
			return (1);
		}
	}
	close(file);
	ft_printf("All chars valid\n");
	return (0);
}

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

/* Previous version
int	check_chars(t_game *game, char *set)
{
	size_t	row;
	size_t	col;
	int	nb_coll;
	int	nb_exit;
	int	nb_start;

	nb_coll = 0;
	nb_exit = 0;
	nb_start = 0;
	row = 0;
	while (row < game->map->tm_rows)
	{
		ft_printf("row: %d - tm_rows: %d\n", row, game->map->tm_rows);
		ft_printf("%s\n", game->map->tilemap[row]);
		if (ft_strnopbrk(game->map->tilemap[row], set) != NULL)
		{
			perror("Error\nInvalid chars (req: 01CEP)\n");
			ft_printf("The map contains non-accepted characters!\n");
			return (1);
		}
		col = 0;
		while (col < game->map->tm_cols)
		{
			if (game->map->tilemap[row][col] == 'P')
				nb_start++;
			else if (game->map->tilemap[row][col] == 'E')
				nb_exit++;
			else if (game->map->tilemap[row][col] == 'C')
				nb_coll++;
			col++;
		}
		row++;
	}
	if (nb_start != 1 || nb_exit != 1 || nb_coll < 1)
	{
		perror("Error\nInvalid chars (req: C>1, Ex1, Px1)\n");
		return (1);
	}
	ft_printf("The map contains only approved characters.\n");
	return (0);
}
*/
/* Previous version
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
}*/
