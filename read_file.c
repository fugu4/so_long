/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:41:10 by hnogi             #+#    #+#             */
/*   Updated: 2025/11/05 17:13:42 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "so_long.h"

// static void    free_and_close(char *map_str, char *line, int fd)
// {
//     free(map_str);
//     free(line);
//     close(fd);
//     error_exit("Error\nMemory allocation failed\n");
// }

// static char    *join_and_free(char *map_str, char *line, int fd)
// {
//     char    *tmp;

//     tmp = ft_strjoin(map_str, line);
//     if (!tmp)
//         free_and_close(map_str, line, fd);
//     free(map_str);
//     return (tmp);
// }

// char    *read_map_file(char *filename)
// {
//     int        fd;
//     char    *line;
//     char    *map_str;

//     fd = open(filename, O_RDONLY);
//     if (fd < 0)
//         error_exit("Error\nFailed to open map file\n");
//     map_str = ft_strdup("");
//     if (!map_str)
//         error_exit("Error\nMemory allocation failed\n");
//     line = get_next_line(fd);
//     while (line)
//     {
//         map_str = join_and_free(map_str, line, fd);
//         free(line);
//         line = get_next_line(fd);
//     }
//     close(fd);
//     return (map_str);
// }

void	error_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

static void	free_map_line(char *map_str, char *line, int fd)
{
	free(map_str);
	free(line);
	close(fd);
	error_exit("Error\nMemory allocation failed\n");
}

char	*read_map_file(char *filename)
{
	int		fd;
	char	*line;
	char	*map_str;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nFailed to open map file\n");
	map_str = ft_strdup("");
	if (!map_str)
		error_exit("Error\nMemory allocation failed\n");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(map_str, line);
		if (!tmp)
			free_map_line(map_str, line, fd);
		free(map_str);
		map_str = tmp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_str);
}

void	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		error_exit("Error\nInvalid filename\n");
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		error_exit("Error\nInvalid file extension\n");
}
