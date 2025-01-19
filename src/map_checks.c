/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:17:11 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/19 14:29:20 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || !game->map_copy[x][y] || game->map_copy[x][y] == '1')
		return (0);
	if (game->map_copy[x][y] == 'E')
		return (1);
	if (game->map_copy[x][y] == 'V' || game->map_copy[x][y] == '1')
		return (0);
	else
	{
		game->map_copy[x][y] = 'V';
		return (flood_fill(game, x + 1, y) + flood_fill(game, x - 1, y) + \
			flood_fill(game, x, y + 1) + flood_fill(game, x, y - 1));
	}
	return (0);
}

int	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
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

int	is_accesible(t_game *game)
{
	game->map_copy = copy_map(game->map, game->rows);
	if (!game->map_copy)
		return (0);
	if (!find_player_position(game))
	{
		free_map(game, 2);
		return (1);
	}
	if (flood_fill(game, game->player_x, game->player_y))
	{
		free_map(game, 2);
		return (1);
	}
	free_map(game, 2);
	return (0);
}

int	map_checks(t_game *game, char *file_name)
{
	if (!check_file_extension(file_name))
		return (ft_error(7));
	if (!is_valid_chars(game))
		return (ft_error(4));
	if (!is_closed(game))
		return (ft_error(6));
	if (!is_rectangular(game))
		return (ft_error(5));
	if (!is_exit(game))
		return (ft_error(8));
	if (!is_accesible(game))
		return (ft_error(11));
	if (!is_colectionables(game))
		return (ft_error(9));
	if (!is_initial_pos(game))
		return (ft_error(10));
	return (0);
}
