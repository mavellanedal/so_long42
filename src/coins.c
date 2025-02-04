/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:45:00 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/03 13:47:59 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	ft_delete_coin(t_game *game)
{
	int	i;
	int	cont;

	i = 0;
	cont = game->total_coins;
	while (i < cont)
	{
		if (((game->images->coin_image->instances[i].y
		== game->images->player_image->instances->y)
		&& (game->images->coin_image->instances[i].x
		== game->images->player_image->instances->x))
		&& game->images->coin_image->instances[i].enabled == true)
		{
			cont--;
			game->images->coin_image->instances[i].enabled = false;
			return;
		}
		i++;
	}
}

void	ft_collector(t_game *game)
{
	if (game->map[game->images->player_image->instances->y / TILE_SIZE]
	[game->images->player_image->instances->x / TILE_SIZE] == 'C')
	{
		ft_delete_coin(game);
		game->map[game->images->player_image->instances->y / TILE_SIZE]
		[game->images->player_image->instances->x / TILE_SIZE] = '1';
		game->coins++;
		ft_printf("Total coins: %d\n", game->total_coins);
		if (game->coins == game->total_coins)
		{
			ft_printf("exit enabled\n");
			game->images->exit_image->instances->enabled = true;
		}
	}
	if (game->map[game->images->player_image->instances->y / TILE_SIZE]
	[game->images->player_image->instances->x / TILE_SIZE] == 'E')
	{
		if (game->coins == game->total_coins)
			ft_cleanup_game(game);
	}
}
