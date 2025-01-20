/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:21:32 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/20 17:55:18 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_player_pos(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = get_player_pos_x(game);
	player_y = get_player_pos_y(game);
	if (game->map[player_x][player_y] == '1')
		return (0);
	else if (game->map[game->player_x][game->player_y] == 'C')
		game->coins ++;
	return (1);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		prev_x;
	int		prev_y;

	game = (t_game *) param;
	prev_x = game->player_x;
	prev_y = game->player_y;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		prev_x = game->player_x;
		prev_y = game->player_y;
		if (keydata.key == MLX_KEY_W)
			game->player_y -= 32;
		else if (keydata.key == MLX_KEY_S)
			game->player_y += 32;
		else if (keydata.key == MLX_KEY_A)
			game->player_x -= 32;
		else if (keydata.key == MLX_KEY_D)
			game->player_x += 32;
	}
	if (check_player_pos(game))
	{
		mlx_image_to_window(game->mlx, game->floor_image, prev_x, prev_y);
		mlx_image_to_window(game->mlx, game->player_image, \
		game->player_x, game->player_y);
	}
	else
	{
		game->player_x = prev_x;
		game->player_y = prev_y;
	}
}

int	get_player_pos_x(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->rows)
	{
		y = 0;
		while (y < game->cols)
		{
			if (game->map[x][y] == 'P')
				return (x * TILE_SIZE);
			y++;
		}
		x++;
	}
	return (0);
}

int	get_player_pos_y(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->rows)
	{
		y = 0;
		while (y < game->cols)
		{
			if (game->map[x][y] == 'P')
				return (y * TILE_SIZE);
			y++;
		}
		x++;
	}
	return (0);
}
