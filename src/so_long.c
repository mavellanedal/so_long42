/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:16:26 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/20 16:30:14 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	start_game(t_game *game)
{
	game->mlx = mlx_init(game->cols * TILE_SIZE, \
	game->rows * TILE_SIZE, "so_long", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (!game->mlx)
		return (ft_error(12));
	if (render_walls(game) != 1)
		return (0);
	if (render_floor(game) != 1)
		return (0);
	if (render_coin(game) != 1)
		return (0);
	if (render_player(game) != 1)
		return (0);
	if (game->coins == 3)
	{
		if (render_exit(game) != 1)
			return (0);
	}
	mlx_key_hook(game->mlx, handle_key, &game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error(1));
	game.map = read_map(av[1], &game);
	if (!game.map)
		return (ft_error(3));
	game.cols = ft_strlen(game.map[0]);
	if (map_checks(&game, av[1]) != 0)
	{
		free_map(&game);
		return (0);
	}
	if (start_game(&game) != 1)
	{
		free_map(&game);
		return (0);
	}
	free_map(&game);
	return (1);
}
