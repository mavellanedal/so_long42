/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:16:26 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 11:30:15 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_columns(char **map)
{
	int	cols;

	if (!map || !map[0])
		return (0);
	cols = 0;
	while (map[0][cols])
		cols++;
	return (cols);
}

void	init_game_struct(t_game *game)
{
	game->mlx = mlx_init(game->cols * TILE_SIZE, \
	game->rows * TILE_SIZE, "so_long", true);
	game->coins = 0;
	game->total_coins = cont_coins(game);
	game->moves = 0;
	game->enemy_count = 0;
	game->player_image = NULL;
	game->floor_image = NULL;
	game->wall_image = NULL;
	game->coin_image = NULL;
	game->exit_image = NULL;
	game->enemy_image = NULL;
}

int	make_renders(t_game *game)
{
	if (render_walls(game) != 1)
		return (0);
	if (render_floor(game) != 1)
		return (0);
	if (render_coin(game) != 1)
		return (0);
	if (render_exit(game) != 1)
		return (0);
	if (render_player(game) != 1)
		return (0);
	if (render_menu(game) != 1)
		return (0);
	ft_printf("rows: %d, cols: %d\n", game->rows, game->cols);
	if (game->rows >= 10 && game->cols >= 10)
	{
		if (render_enemies(game) != 1)
			return (0);
		if (render_animation1(game) != 1)
			return (0);
		if (render_animation2(game) != 1)
			return (0);
		if (render_animation3(game) != 1)
			return (0);
	}
	return (1);
}

int	start_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (!game->mlx)
		return (ft_error(12));
	if (!make_renders(game))
		return (0);
	update_game_info(game);
	mlx_key_hook(game->mlx, &handle_player_move, game);
	if (game->enemy_count > 0)
	{
		mlx_loop_hook(game->mlx, &hook_loop, game);
	}
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error(1));
	game.rows = count_lines(av[1]);
	game.map = read_map(av[1], &game);
	game.cols = count_columns(game.map);
	init_game_struct(&game);
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
