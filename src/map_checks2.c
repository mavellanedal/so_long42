/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:30 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 09:59:31 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_map(const char *path, t_game *game)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (game->rows <= 0)
		return (NULL);
	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
	{
		close(fd);
		return (NULL);
	}
	if (!process_lines(fd, game))
		return (NULL);
	close(fd);
	return (game->map);
}

int	process_lines(int fd, t_game *game)
{
	char	*line;
	int		i;
	size_t	len;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		game->map[i] = ft_strndup(line, len - 1);
		free(line);
		if (!game->map[i])
		{
			free_map(game);
			return (0);
		}
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	return (1);
}

int	check_file_extension(char *file_name)
{
	if (!ft_strnstr(file_name + (ft_strlen(file_name) - 4), ".ber", 4))
		return (0);
	return (1);
}

int	is_initial_pos(t_game *game)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	cont = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				cont++;
			j++;
		}
		i++;
	}
	if (cont != 1)
		return (0);
	return (1);
}

int	is_colectionables(t_game *game)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	cont = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				cont++;
			j++;
		}
		i++;
	}
	if (cont < 1)
		return (0);
	return (1);
}
