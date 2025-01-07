/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:25:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/07 20:08:12 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_env	env;
	t_img	canvas;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	env.canvas = &canvas;
	game->env = &env;
	if (map_parser(game, argc, argv) != 0)
		return (1);
	if (init_game(game) != 0)
		return (1);
	mlx_loop_hook(game->env->mlx, &render, game);
	mlx_loop(game->env->mlx);
	return (0);
}

int     map_parser(t_game *game, int argc, char **argv)
{
        char    filepath[256]; // CHANGE TO MALLOC
        size_t  line_len;
        size_t  nb_lines;

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
        if (check_chars(filepath, "01CEP\n") != 0) // Should the nl char be accepted?
                return (1);
        ft_printf("Correct chars (req: 01CEP)\n"); // DEBUG
        if (check_count(filepath, "01CEP\n") != 0) // Should the nl char be accepted?
                return (1);
        ft_printf("Correct counts (req: 0, 1, C>1, Ex1, Px1)\n"); // DEBUG
        
	init_map(game, filepath, line_len, nb_lines);
        return (0);
}

void    init_map(t_game *game, char *fpath, size_t line_len, size_t nb_lines)
{
        t_map   *map;
        char    **tilemap;
        char    *tilemap_line;
        size_t  i;
        int     file;

        file = open(fpath, O_RDONLY);
        map = malloc(sizeof(t_map));
        if (!map)
                return ;
        game->map = map;
        game->map->fpath = fpath;
        tilemap = malloc(sizeof(char *) * (nb_lines));
        if (!tilemap)
                return ;
        game->map->tilemap = tilemap;
        game->map->tm_rows = nb_lines;
        game->map->tm_cols = line_len;
	calc_cell_size(game);
        i = 0;
        while (i <= nb_lines)
        {
                tilemap_line = ft_gnl(file);
//              ft_printf("%s", tilemap_line);
                if (!tilemap_line)
                        return ;
                game->map->tilemap[i] = tilemap_line;
                ft_printf("%s", game->map->tilemap[i]);
                i++;
                //free(tilemap_line);
        //      ft_printf("mallocated %d lines\n", i);
        }
}

int	init_game(t_game *game)
{	
	game->env->mlx = mlx_init();
	if (!game->env->mlx)
		return (1);
	game->env->win = mlx_new_window(game->env->mlx, WIN_WIDTH, WIN_HEIGHT, "So Long");
	set_hooks(game);
	set_canvas(game->env);
	set_map(game);
	upload_assets(game);
	return (0);
}
