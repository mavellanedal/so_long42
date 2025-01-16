/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:35:49 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/16 16:38:29 by mavellan         ###   ########.fr       */
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

int	is_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_exit(char **map)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	cont = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				cont++;
			j++;
		}
		i++;
	}
	if (cont != 1)
		return (0);
	return (1);
}

int	is_rectangular(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_closed(char **map, int rows)
{
	int	cols;
	int	i;
	int	j;

	j = 0;
	i = 0;
	cols = ft_strlen(map[0]);
	while (j < cols)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
