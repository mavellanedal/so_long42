/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:55:55 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/19 14:54:40 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game, int j)
{
	int	i;

	i = 0;
	if (j == 1)
	{
		if (!game->map)
			return ;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	if (j == 2)
	{
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
}
