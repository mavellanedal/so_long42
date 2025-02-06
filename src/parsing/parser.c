/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:16:47 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/06 13:40:31 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_read_trimmed_line(int fd)
{
	char	*line;
	char	*trim;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trim = ft_strtrim(line, "\r\n");
	free(line);
	return (trim);
}

int	handle_overflow(char *trim, char **map, int fd, int *rows)
{
	if (*rows >= 1024)
	{
		free(trim);
		ft_free(map);
		close(fd);
		return (1);
	}
	return (0);
}

int	read_map(int fd, char **map, int *rows, int *cols)
{
	char	*trim;

	trim = ft_read_trimmed_line(fd);
	if (trim == NULL)
	{
		free(trim);
		ft_free(map);
		return (-1);
	}
	while (trim)
	{
		if (handle_overflow(trim, map, fd, rows))
		{
			ft_free(map);
			return (-1);
		}
		map[*rows] = trim;
		*cols = ft_strlen(trim);
		(*rows)++;
		trim = ft_read_trimmed_line(fd);
	}
	return (0);
}

char	**make_map(char *path, char **map, int *rows, int *cols)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_free(map);
		return (NULL);
	}
	if (read_map(fd, map, rows, cols) == -1)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}

char	**map_checks(char *path, int *rows, int *cols)
{
	int		invalid_map;
	char	**map;

	if (!ft_strnstr(path + (ft_strlen(path) - 4), ".ber", 4))
		return (ft_error(5), NULL);
	map = ft_calloc(1024, sizeof(char *));
	if (!map)
		return (ft_error(10), NULL);
	map = make_map(path, map, rows, cols);
	if (!map)
	{
		ft_free(map);
		return (ft_error(11), NULL);
	}
	invalid_map = ft_checker(map, *rows, *cols);
	if (invalid_map)
	{
		ft_free(map);
		return (NULL);
	}
	return (map);
}
