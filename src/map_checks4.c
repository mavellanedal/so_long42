/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:27:54 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 11:22:32 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_exit_x(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'E')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	find_exit_y(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'E')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int	count_empty_positions(t_game *game)
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
			if (game->map[i][j] == '0')
				cont++;
			j++;
		}
		i++;
	}
	return (cont);
}
