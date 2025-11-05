/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:24:59 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/02 19:25:00 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
}

int	main(int ac, char **av)
{
	char	*map_str;
	char	**map;
	t_game	*game;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long <map.ber>\n");
		return (1);
	}
	check_extension(av[1]);
	map_str = read_map_file(av[1]);
	map = parse_map(map_str);
	free(map_str);
	validate_map(map);
	game = init_game(map);
	render_game(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
	return (0);
}
