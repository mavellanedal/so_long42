/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:58:30 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/16 16:38:47 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_map(const char *path, int *rows)
{
	int		fd;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	*rows = count_lines(path);
	if (*rows <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (*rows + 1));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	if (!process_lines(fd, map))
		return (NULL);
	close(fd);
	return (map);
}

int	process_lines(int fd, char **map)
{
	char	*line;
	int		i;
	size_t	len;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		map[i] = ft_strndup(line, len - 1);
		free(line);
		if (!map[i])
		{
			free_map(map);
			return (0);
		}
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (1);
}

int	check_file_extension(char *file_name)
{
	if (!ft_strnstr(file_name + (ft_strlen(file_name) - 4), ".ber", 4))
		return (0);
	return (1);
}

int	is_initial_pos(char **map)
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
			if (map[i][j] == 'P')
				cont++;
			j++;
		}
		i++;
	}
	if (cont != 1)
		return (0);
	return (1);
}

int	is_colectionables(char **map)
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
			if (map[i][j] == 'C')
				cont++;
			j++;
		}
		i++;
	}
	if (cont < 1)
		return (0);
	return (1);
}
