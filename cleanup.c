/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:00:00 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/06 13:43:37 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *game)
{
	if (game->img_w)
		mlx_destroy_image(game->mlx, game->img_w);
	if (game->img_f)
		mlx_destroy_image(game->mlx, game->img_f);
	if (game->img_p)
		mlx_destroy_image(game->mlx, game->img_p);
	if (game->img_e)
		mlx_destroy_image(game->mlx, game->img_e);
	if (game->img_c)
		mlx_destroy_image(game->mlx, game->img_c);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cleanup_game(t_game *game)
{
	destroy_images(game);
	free_map(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
