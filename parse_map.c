/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:23:27 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/06 15:52:59 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_len(char **map)
{
	int	x;
	int	y;

	x = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) != x)
		{
			free_map(map);
			error_exit("Error\nMap is not rectangular\n");
		}
		y++;
	}
}

static void	check_invalid_chars(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr("01CEP", map[y][x]))
			{
				free_map(map);
				error_exit("Error\nInvalid character in map\n");
			}
			x++;
		}
		y++;
	}
}

char	**parse_map(char *map_str)
{
	char	**map;

	map = ft_split(map_str, '\n');
	if (!map || !map[0])
	{
		if (map)
			free_map(map);
		error_exit("Error\nEmpty map\n");
	}
	check_len(map);
	check_invalid_chars(map);
	return (map);
}
