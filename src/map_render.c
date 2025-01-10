/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:34:35 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/10 18:32:22 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_line(const char *line, int expected_width)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	if (expected_width != -1 && len != expected_width)
	{
		ft_error(4);
		return (0);
	}
	while (i < len)
	{
		if (line[i] != '1' && line[i] != '0')
		{
			ft_printf(INVALID_CHAR_MAP, line[i]);
			return (0);
		}
	}
	return (len);
}

char	**resize_map(char **map, int capacity, int rows)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * capacity * 2);
	if (!new_map)
	{
		perror("Error resizing map");
		free_map(map, rows);
		return (NULL);
	}
	while (i < rows)
	{
		new_map[i] = map[i];
		i++;
	}
	free(map);
	return (new_map);
}

int	load_map_lines(int fd, char ***map, int *width, int *rows)
{
	int		capacity;
	char	**temp_map;
	int		result;

	capacity = 10;
	temp_map = malloc(sizeof(char *) * capacity);
	*rows = 0;
	*width = -1;
	if (!temp_map)
	{
		free(temp_map);
		return (-1);
	}
	while (1)
	{
		result = read_line_from_file(fd, map, rows, &capacity);
		if (result == 0)
			break ;
		if (result < 0)
		{
			free_map(*map, *rows);
			return (-1);
		}
	}
	return (0);
}

int	load_and_validate_map(const char *file_path, char ***map, int *w, int *h)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	if (load_map_lines(fd, map, w, h) < 0)
	{
		close(fd);
		return (-1);
	}
	if (!validate_map(*map, *w, *h))
	{
		free_map(*map, *h);
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
}
