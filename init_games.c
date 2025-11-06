/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_games.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:00:00 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/06 13:43:50 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_map_dimensions(char **map, int *width, int *height)
{
	*height = 0;
	while (map[*height])
		(*height)++;
	*width = ft_strlen(map[0]);
}

static void	init_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	game->collectibles = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			x++;
		}
		y++;
	}
}

t_game	*init_game(char **map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error_exit("Error\nMemory allocation failed\n");
	game->map = map;
	get_map_dimensions(map, &game->map_width, &game->map_height);
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error\nFailed to initialize MiniLibX\n");
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
		error_exit("Error\nFailed to create window\n");
	init_player_position(game);
	count_collectibles(game);
	load_image(game);
	game->moves = 0;
	game->collected = 0;
	return (game);
}
