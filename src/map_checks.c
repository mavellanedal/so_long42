/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:17:11 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/17 09:57:38 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[x][y] || map[x][y] == '1')
		return (0);
	if (map[x][y] == 'E')
	{
		return (1);
	}
	if (map[x][y] == 'V' || map[x][y] == '1')
	{
		return (0);
	}
	else
	{
		map[x][y] = 'V';
		return (flood_fill(map, x + 1, y) + flood_fill(map, x - 1, y) + \
			flood_fill(map, x, y + 1) + flood_fill(map, x, y - 1));
		/*
		if (flood_fill(map, x + 1, y))
			return (1);
		if (flood_fill(map, x - 1, y))
			return (1);
		if (flood_fill(map, x, y + 1))
			return (1);
		if (flood_fill(map, x, y - 1))
			return (1);
		*/
	}
	return (0);
}

int	find_player_position(char **map, int rows, int *px, int *py)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*px = i;
				*py = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**copy_map(char **map, int rows)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (rows + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i-- > 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[rows] = NULL;
	return (map_copy);
}

int	is_accesible(char **map, int rows)
{
	int		px;
	int		py;
	char	**map_copy;

	if (!find_player_position(map, rows, &px, &py))
		return (0);
	map_copy = copy_map(map, rows);
	if (!map_copy)
		return (0);
	if (flood_fill(map_copy, px, py))
	{
		free_map(map_copy);
		return (1);
	}
	free_map(map_copy);
	return (0);
}

int	map_checks(char **map, int rows, char *file_name)
{
	if (!check_file_extension(file_name))
		return (ft_error(7));
	if (!is_valid_chars(map))
		return (ft_error(4));
	if (!is_closed(map, rows))
		return (ft_error(6));
	if (!is_rectangular(map))
		return (ft_error(5));
	if (!is_exit(map))
		return (ft_error(8));
	if (!is_accesible(map, rows))
		return (ft_error(11));
	if (!is_colectionables(map))
		return (ft_error(9));
	if (!is_initial_pos(map))
		return (ft_error(10));
	return (0);
}
