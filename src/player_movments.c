/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:21:32 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/04 10:27:27 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->images->player_image->instances->y / TILE_SIZE - 1]
	[game->images->player_image->instances->x / TILE_SIZE] != '1')
	{
		game->images->player_image->instances->y -= TILE_SIZE;
		game->moves++;
		if (game->enemy_count != 0)
			move_enemy(game);
		ft_printf("Moves: %i\n", game->moves);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->images->player_image->instances->y / TILE_SIZE + 1]
	[game->images->player_image->instances->x / TILE_SIZE] != '1')
	{
		game->images->player_image->instances->y += TILE_SIZE;
		game->moves++;
		if (game->enemy_count != 0)
			move_enemy(game);
		ft_printf("Moves: %i\n", game->moves);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->images->player_image->instances->y / TILE_SIZE]
	[game->images->player_image->instances->x / TILE_SIZE - 1] != '1')
	{
		game->images->player_image->instances->x -= TILE_SIZE;
		game->moves++;
		if (game->enemy_count != 0)
			move_enemy(game);
		ft_printf("Moves: %i\n", game->moves);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->images->player_image->instances->y / TILE_SIZE]
	[game->images->player_image->instances->x / TILE_SIZE + 1] != '1')
	{
		game->images->player_image->instances->x += TILE_SIZE;
		game->moves++;
		if (game->enemy_count != 0)
			move_enemy(game);
		ft_printf("Moves: %i\n", game->moves);
	}
}

void	handle_player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	ft_write_counter(game);
	if (game->enemy_count != 0)
		ft_enemy_detection(game);
	ft_collector(game);
}
