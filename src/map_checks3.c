/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:35:49 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/20 15:46:52 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(const char *path)
{
	int		fd;
	char	*line;
	int		lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		lines++;
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	is_valid_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && \
			game->map[i][j] != 'E' && game->map[i][j] != 'P' && \
				game->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_exit(t_game *game)
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
			if (game->map[i][j] == 'E')
				cont++;
			j++;
		}
		i++;
	}
	if (cont != 1)
		return (0);
	return (1);
}

int	is_rectangular(t_game *game)
{
	size_t	len;
	int		i;

	len = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_closed(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	game->cols = ft_strlen(game->map[0]);
	while (j < game->cols)
	{
		if (game->map[0][j] != '1' || game->map[game->rows - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
