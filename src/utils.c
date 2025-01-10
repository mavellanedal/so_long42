/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:17:30 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/10 17:22:16 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(map[i]);
	free(map);
}

void	cleanup(t_game *game, mlx_texture_t *wall, mlx_texture_t *floor)
{
	free_map(game->map, game->height);
	mlx_delete_texture(wall);
	mlx_delete_texture(floor);
	mlx_terminate(game->mlx);
}
