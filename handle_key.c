/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:00:00 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/06 13:31:36 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
