/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:21:32 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/27 17:34:48 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_enemies(t_game *game, int px, int py)
{
	if (game->enemy_image->instances[0].x == px \
	&& game->enemy_image->instances[0].y == py \
	&& game->enemy_image->instances[0].enabled)
		mlx_close_window(game->mlx);
	if (game->enemy_image->instances[1].x == px \
	&& game->enemy_image->instances[1].y == py \
	&& game->enemy_image->instances[1].enabled)
		mlx_close_window(game->mlx);
}

void	check_exit(t_game *game, int px, int py)
{
	if (game->exit_image->instances[0].x == px \
	&& game->exit_image->instances[0].y == py \
	&& game->exit_image->instances[0].enabled)
		mlx_close_window(game->mlx);
}

void	check_coins(t_game *game, int px, int py)
{
	int	i;

	i = 0;
	while (i < game->total_coins)
	{
		if (game->coin_image->instances[i].x == px && \
		game->coin_image->instances[i].y == py && \
		game->coin_image->instances[i].enabled)
		{
			game->coin_image->instances[i].enabled = false;
			game->coins++;
			if (game->coins == game->total_coins)
				game->exit_image->instances[0].enabled = true;
			ft_printf("El jugador lleva %d moneda\n", game->coins);
		}
		i++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_image->instances[0].x + dx * TILE_SIZE;
	new_y = game->player_image->instances[0].y + dy * TILE_SIZE;
	if (game->map[new_y / TILE_SIZE][new_x / TILE_SIZE] == '1')
		return ;
	game->player_image->instances[0].x = new_x;
	game->player_image->instances[0].y = new_y;
	check_coins(game, new_x, new_y);
	check_exit(game, new_x, new_y);
	check_enemies(game, new_x, new_y);
	update_enemy_instances(game);
	game->moves++;
}

void	handle_player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;

	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_S)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_A)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_D)
			move_player(game, 1, 0);
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	}
}
