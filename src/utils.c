/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:55:55 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 17:37:49 by mavellan         ###   ########.fr       */
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

void	update_enemy_instances(t_game *game)
{
	move_enemy_instances(game);
	move_enemy_instances(game);
}

void	free_images(t_game *game)
{
	if (game->player_image)
		mlx_delete_image(game->mlx, game->player_image);
	if (game->floor_image)
		mlx_delete_image(game->mlx, game->floor_image);
	if (game->wall_image)
		mlx_delete_image(game->mlx, game->wall_image);
	if (game->coin_image)
		mlx_delete_image(game->mlx, game->coin_image);
	if (game->exit_image)
		mlx_delete_image(game->mlx, game->exit_image);
	if (game->enemy_image)
		mlx_delete_image(game->mlx, game->enemy_image);
}
