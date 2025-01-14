/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:36:45 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/14 18:20:27 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	store_line_in_map(char ***map, int *rows, int *capacity, char *line)
{
	if (*rows >= *capacity)
	{
		*map = resize_map(*map, *capacity, *rows);
		if (!*map)
		{
			free(line);
			return (-1);
		}
		*capacity *= 2;
	}
	(*map)[*rows] = line;
	(*rows)++;
	return (0);
}

int	read_line_from_file(int fd, char ***map, int *rows, int *capacity)
{
	ft_printf("read line from file\n");
	char	*line;
	int		line_width;

	line = get_next_line(fd);
	if (!line)
		return (0);
	line_width = validate_line(line, -1);
	if (line_width <= 0)
	{
		free(line);
		return (-1);
	}
	if (*rows >= *capacity)
	{
		*map = resize_map(*map, *capacity, *rows);
		if (!*map)
		{
			free(line);
			return (-1);
		}
		*capacity *= 2;
	}
	(*map)[*rows] = line;
	(*rows)++;
	return (1);
}
