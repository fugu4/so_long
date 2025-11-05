/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:05:00 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/05 17:14:30 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width || new_y < 0
		|| new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	handle_move(t_game *game, int new_x, int new_y)
{
	if (!is_valid_move(game, new_x, new_y))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collected++;
	}
	if (game->map[new_y][new_x] != 'E')
		game->map[new_y][new_x] = 'P';
	if (game->map[new_y][new_x] == 'E' && game->collected == game->collectibles)
	{
		ft_printf("Congratulations! You won in %d moves!\n", game->moves);
		close_window(game);
	}
	render_game(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		handle_move(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		handle_move(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		handle_move(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		handle_move(game, game->player_x + 1, game->player_y);
	return (0);
}
