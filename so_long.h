/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:41:40 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/05 17:17:14 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

// # define COLOR_WALL 0x444444        // 濃いグレー（壁）
// # define COLOR_PLAYER 0x00FF00      // 緑（プレイヤー）
// # define COLOR_COLLECTIBLE 0xFFFF00 // 黄色（コイン）
// # define COLOR_EXIT 0xFF0000        // 赤（出口）
// # define COLOR_EMPTY 0xFFFFFF

// ====== Key codes (mac) ======
// # define KEY_W       13
// # define KEY_A       0
// # define KEY_S       1
// # define KEY_D       2
// # define KEY_UP      126
// # define KEY_DOWN    125
// # define KEY_LEFT    123
// # define KEY_RIGHT   124
// # define KEY_ESC     53

// ====== Key codes (Linux) ======
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_path_check
{
	int		collectibles;
	int		exit_found;
}			t_path_check;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		moves;

	void	*img_w;
	void	*img_f;
	void	*img_p;
	void	*img_e;
	void	*img_c;
}	t_game;


void		error_exit(char *msg);
void		check_extension(char *filename);
char		*read_map_file(char *filename);
char		**parse_map(char *map_str);
void		validate_map(char **map);
t_game		*init_game(char **map);
void		check_valid_path(char **map, int collectible_count);
void		render_game(t_game *game);
int			key_press(int keycode, t_game *game);
int			close_window(t_game *game);
void		cleanup_game(t_game *game);
void 		load_image(t_game *game);

#endif
