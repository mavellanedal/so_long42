/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:21:32 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/22 16:47:24 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	is_coin(t_game *game)
{
	game->coins ++;
	if (game->coins == game->total_coins)
		render_exit(game);
}

void	process_player_move(t_game *game, int new_x, int new_y)
{
	int	past_x;
	int	past_y;

	if (new_x < 0 || new_x >= game->cols || new_y < 0 || new_y >= game->rows)
		return ;
	past_x = game->player_x;
	past_y = game->player_y;
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
			is_coin(game);
		if (game->map[new_y][new_x] == 'M' || game->map[new_y][new_x] == 'E')
			mlx_close_window(game->mlx);
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		mlx_image_to_window(game->mlx, game->player_image, new_x * \
		TILE_SIZE, new_y * TILE_SIZE);
		mlx_image_to_window(game->mlx, game->floor_image, past_x * \
		TILE_SIZE, past_y * TILE_SIZE);
		game->player_x = new_x;
		game->player_y = new_y;
		game->moves++;
		update_game_info(game);
	}

}

void	handle_player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;
	int		past_x;
	int		past_y;

	game = (t_game *)param;
	new_x = game->player_x;
	new_y = game->player_y;
	past_y = game->player_y;
	past_x = game->player_x;

	if (keydata.key == MLX_KEY_W)
		new_y--;
	else if (keydata.key == MLX_KEY_S)
		new_y++;
	else if (keydata.key == MLX_KEY_A)
		new_x--;
	else if (keydata.key == MLX_KEY_D)
		new_x++;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	process_player_move(game, new_x, new_y);
}

