/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:55:55 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/21 17:54:29 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_map_copy(t_game *game)
{
	int	i;

	if (!game->map_copy)
		return ;
	i = 0;
	while (game->map_copy[i])
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
	game->map_copy = NULL;
}

int	cont_coins(t_game *game)
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
	return (cont);
}
