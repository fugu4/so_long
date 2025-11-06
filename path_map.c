/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:05:56 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/06 13:43:59 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map)
{
	char	**copy;
	int		height;
	int		i;

	height = 0;
	while (map[height])
		height++;
	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		error_exit("Error\nMemory allocation failed\n");
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			error_exit("Error\nMemory allocation failed\n");
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

static void	find_player_pos(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

static void	flood_fill(char **map, int x, int y, t_path_check *check)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		check->collectibles++;
	if (map[y][x] == 'E')
		check->exit_found = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, check);
	flood_fill(map, x - 1, y, check);
	flood_fill(map, x, y + 1, check);
	flood_fill(map, x, y - 1, check);
}

static void	check_result(char **map, t_path_check *check, int collectibles)
{
	free_map(map);
	if (check->collectibles != collectibles)
	{
		free_map(map);
		error_exit("Error\nSome collectibles are not reachable\n");
	}
	if (!check->exit_found)
	{
		free_map(map);
		error_exit("Error\nExit is not reachable\n");
	}
}

void	check_valid_path(char **map, int collectible_count)
{
	char			**map_copy;
	t_path_check	check;
	int				player_x;
	int				player_y;

	map_copy = copy_map(map);
	find_player_pos(map_copy, &player_x, &player_y);
	check.collectibles = 0;
	check.exit_found = 0;
	flood_fill(map_copy, player_x, player_y, &check);
	check_result(map_copy, &check, collectible_count);
}
