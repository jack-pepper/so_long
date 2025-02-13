/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_map_init_toolkit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:16:14 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/13 14:01:39 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libxkit.h"

/* Init a t_map from a file if the file's name matches the param extension.
 * Defines map, fpath, line_len, nb_lines et tilemap.
 * tilemap will hold the file's content (line as strings).  
 * Handles only rectangular maps in its current form.
 */
int	init_map(t_state *state, char *fpath, char *ext)
{
	t_map	*map;

	state->error_code = 1;
	if (check_extension(fpath, ext) != 0)
		return (1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_err(1, "Error\n[init_map] map alloc fail ❌\n"));
	ft_memset(map, 0, sizeof(t_map));
	state->map = map;
	if (set_map_data(map, fpath) != 0)
	{
		free(map);
		return (ft_err(1, "Error\n[init_map] set map data fail ❌\n"));
	}
	ft_printf("\n🏞️  [init_map] game map [%s]:\n\n", fpath);
	if (fconv_arr_chr(map->tilemap, map->fpath, map->tm_rows) != 0)
	{
		free(map);
		return (ft_err(1, "Error\n[init_map] tilemap conv fail ❌\n"));
	}
	return (0);
}

// Check if a file's extension matches ext pattern.
int	check_extension(char *fpath, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(ext) - 1;
	j = ft_strlen(fpath) - 1;
	if (j < i)
		return (ft_err(1, "Error\n[check_ext] short fpath ❌\n"));
	while (i >= 0)
	{
		if (fpath[j] != ext[i])
			return (ft_err(1, "Error\n[check_ext] bad ext ❌\n"));
		i--;
		j--;
	}
	ft_printf("✅ [check_ext] extension is valid\n");
	return (0);
}

// Set map data. get_map_size only handles only rect maps.
// NB: tile_count is mallocated space for 5 possible chars: find improvement
int	set_map_data(t_map *map, char *fpath)
{
	int		line_len;
	int		nb_lines;

	ft_init_two_ints(0, &line_len, &nb_lines);
	map->fpath = fpath;
	if (get_map_size(map, &line_len, &nb_lines) != 0)
		return (1);
	map->tm_rows = nb_lines;
	map->tm_cols = line_len;
	map->tilemap = malloc(sizeof(char *) * (nb_lines));
	if (!map->tilemap)
		return (ft_err(1, "Error\n[set_map_data] tilemap fail ❌\n"));
	map->tile_count = malloc(sizeof(int) * 6);
	if (!map->tile_count)
	{
		free(map->tilemap);
		return (ft_err(1, "Error\n[set_map_data] tile_count fail ❌\n"));
	}
	ft_memset(map->tile_count, 0, sizeof(int) * 6);
	map->width = (map->tm_rows * RES_PIX);
	map->height = (map->tm_cols * RES_PIX);
	return (0);
}

/* Get line_len and nb_lines. Handles only rect maps.
 * The loop has to reach the end in all cases so the stash
 * in GNL will be freed.
 */
int	get_map_size(t_map *map, int *line_len, int *nb_lines)
{
	char	*line;
	char	*fpath;
	int		file;
	int		not_rect;

	not_rect = 0;
	line = NULL;
	fpath = map->fpath;
	file = ft_open_file(fpath, "O_RDONLY", "Error\nError opening file\n");
	if (file == -1)
		return (1);
	while (ft_read_line(file, &line, "no") != 1)
	{
		if (*nb_lines == 0)
			*line_len = ft_strlen(line);
		if (ft_strlen(line) != (size_t)(*line_len))
			not_rect = 1;
		(*nb_lines)++;
		free(line);
	}
	close(file);
	if (not_rect == 1)
		return (ft_err(1, "Error\nmap not rectangular\n"));
	return (0);
}

// Copy .ber file to tilemap array.
int	fconv_arr_chr(char **arr, char *fpath, int nb_lines)
{
	char	*line;
	int		file;
	int		i;

	file = ft_open_file(fpath, "O_RDONLY", "Error\nError opening file\n");
	if (file == -1)
		return (1);
	i = 0;
	while (i < nb_lines)
	{
		line = ft_gnl(file);
		ft_printf("%s", line);
		if (!line)
		{
			while (i-- > 0)
				free(arr[i - 1]);
			close(file);
			return (ft_err(1, "Error\nline alloc fail\n"));
		}
		arr[i] = line;
		i++;
	}
	close(file);
	ft_printf("\n");
	return (0);
}
