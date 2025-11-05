/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:06:51 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/05 17:01:35 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_w, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_f, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_c, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_e, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_game(t_game *game)
{
	int	y;
	int	x;
	char tile;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map[y][x];
			put_tile(game, x, y, tile);
			x++;
		}
		y++;
	}
}

void	load_image(t_game *game)
{
	int	w;
	int	h;

	w = 16;
	h = 16;

	game->img_w = mlx_xpm_file_to_image(game->mlx, "texture/w.xpm", &w, &h);
	game->img_f = mlx_xpm_file_to_image(game->mlx, "texture/f.xpm", &w, &h);
	game->img_p = mlx_xpm_file_to_image(game->mlx, "texture/p.xpm", &w, &h);
	game->img_e = mlx_xpm_file_to_image(game->mlx, "texture/e.xpm", &w, &h);
	game->img_c = mlx_xpm_file_to_image(game->mlx, "texture/c.xpm", &w, &h);
	if (!game->img_w || !game->img_f || !game->img_p || !game->img_e
		|| !game->img_c )
		error_exit("Error\nFailed to load image files\n");
}
