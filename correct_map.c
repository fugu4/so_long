/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:58:14 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/02 19:25:07 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(char **map)
{
	int	y;
	int	x;
	int	width;
	int	height;

	height = 0;
	while (map[height] != 0)
		height++;
	width = ft_strlen(map[0]);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if ((y == 0 || y == height - 1 || x == 0 || x == width - 1)
				&& map[y][x] != '1')
				error_exit("Error\nMap must be surrounded by walls\n");
			x++;
		}
		y++;
	}
}

static void	count_elements(char **map, int *count)
{
	int	y;
	int	x;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				count[0]++;
			else if (map[y][x] == 'E')
				count[1]++;
			else if (map[y][x] == 'C')
				count[2]++;
			x++;
		}
		y++;
	}
}

static void	check_element_counts(int *count)
{
	if (count[0] != 1)
		error_exit("Error\nMap must have exactly one starting position\n");
	if (count[1] != 1)
		error_exit("Error\nMap must have exactly one exit\n");
	if (count[2] < 1)
		error_exit("Error\nMap must have at least one collectible\n");
}

void	validate_map(char **map)
{
	int	count[3];

	check_walls(map);
	count_elements(map, count);
	check_element_counts(count);
	check_valid_path(map, count[2]);
}
