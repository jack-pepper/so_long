/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:26:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/09 15:33:56 by mmalie           ###   ########.fr       */
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


void	count_tiles(char *line, char *set, int *counter)
{
	size_t	i;
	size_t	j;
	size_t	set_len;
	size_t	line_len;

	set_len = ft_strlen(set);
	line_len = ft_strlen(line) - 1;
	//ft_printf("line_len: %d - set_len: %d\n", line_len, set_len);
	i = 0;
	while (i < line_len)
	{
		j = 0;
		while (j < set_len)
		{	
			//ft_printf("line[%d] = %c - set[%d] = %c\n", i, line[i], j, set[j]);
			if (line[i] == set[j])
			{
				counter[j] = counter [j] + 1;
				//ft_printf("counter[%d] incremented: now %d\n", j, counter[j]);
				break ;
			}
			j++;
		}
		i++;
	}
}

int	check_extension(char *fpath, char *ext)
{
	int     i;
        int     j;

        i = ft_strlen(ext) - 1;
        j = ft_strlen(fpath) - 1;
        while (i >= 0)
        {
                if (fpath[j] != ext[i])
		{
			ft_printf("Error\nInvalid extension (req: %s)\n", ext); // Should be displayed to stderror!
                        return (1);
		}
                i--;
                j--;
        }
        return (0);
}

int	check_shape(char *fpath, size_t *line_len, size_t *nb_lines)
{
	int	file;
	char	*line;

	file = ft_open_file(fpath, "O_RDONLY", "Error\nError opening file\n");
	if (file == -1)
		return (1);
	line = NULL;
	while (ft_read_line(file, &line, "no") != 1)
	{
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

int	check_closed(char *fpath, size_t line_len, size_t nb_lines)
{
	int	file;
	char	*line;
	size_t	line_nb;

	file = ft_open_file(fpath, "O_RDONLY", "Error\nError opening file\n");
	if (file == -1)
		return (1);
	line_nb = 0;
	line_len = line_len - 2;
	line = NULL;
	while (ft_read_line(file, &line, "no") != 1)
	{
		ft_printf("line: %s\n", line); // DEBUG
		line_nb++;
		if ((line_nb == 1 && ft_strnopbrk(line, "1\n") != NULL)
			|| (line_nb == nb_lines && ft_strnopbrk(line, "1\n") != NULL)
			|| ((line_nb > 1 && line_nb < nb_lines)
				&& (line[0] != '1' || line[line_len] != '1')))
		{
			perror("Error\nInvalid: map not closed\n");
			close(file);
			return (1);
		}
	}
	ft_printf("Map closed!\n"); // DEBUG
	return (0);
}


int	check_chars(char *fpath, char *set)
{
	int	file;
	char	*line;

	file = ft_open_file(fpath, "O_RDONLY", "Error\nError opening file\n");
	if (file == -1)
		return (1);
	line = NULL;
	while (ft_read_line(file, &line, "no") != 1)
	{
		if (ft_strnopbrk(line, set) != NULL)
		{
			perror("Error\nInvalid char (req: set)\n");
			close(file);
			return (1);
		}
	}
	ft_printf("All chars valid\n"); // DEBUG
	return (0);
}
 
//	[0]=empty | [1]=wall | [2]=C (coll) | [3]=E (exit) | [4] =P (start pos)
int	check_count(char *fpath, char *set)
{
	int	file;
	char	*line;
	int	occ[5];

	file = ft_open_file(fpath, "O_RDONLY", "Error\nError opening file\n");
	if (file == -1)
		return (1);
	ft_memset(occ, 0, 5 * sizeof(int));
	line = NULL;

// DEBUG
	int i = 0;
	while (i < 5)
	{
		ft_printf("Bef/occ[%d] : %d\n", i, occ[i]);
		i++;
	}
//
	while (ft_read_line(file, &line, "no") != 1 && occ[3] <= 1 && occ[4] <= 1)
	{
		ft_printf("line: %s\n", line); // DEBUG
		count_tiles(line, set, occ);
	}
// DEBUG
	i = 0;
	while (i < 5)
	{
		ft_printf("Aft/occ[%d] : %d\n", i, occ[i]);
		i++;
	}
//

	if (occ[2] < 1 || occ[3] != 1 || occ[4] != 1)
	{
		perror("Error\nInvalid chars (req: C>1, Ex1, Px1)\n");
		return (1);
	}
	ft_printf("The map contains only approved characters.\n"); // DEBUG
	return (0);
}
