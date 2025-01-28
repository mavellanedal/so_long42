/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:44 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 11:29:11 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemy_instances(t_game *game)
{
	int	dx[4];
	int	dy[4];
	int	direction1;
	int direction2;
	int	new_x;
	int	new_y;

	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
	srand(time(NULL));
	direction1 = rand() % 4;
	direction2 = rand() % 4;
	new_x = (game->enemy_image->instances[0].x / TILE_SIZE) \
	+ dx[direction1];
	new_y = (game->enemy_image->instances[0].y / TILE_SIZE) \
	+ dy[direction1];
	if (new_x >= 0 && new_x < game->cols && new_y >= 0 && \
		new_y < game->rows && game->map[new_y][new_x] == '0' && \
		new_x != game->player_image->instances[0].x &&
		new_y != game->player_image->instances[0].y && game->enemies[1].x != new_x && game->enemies[1].y != new_y)
	{
		game->enemy_image->instances[0].x = new_x * TILE_SIZE;
		game->enemy_image->instances[0].y = new_y * TILE_SIZE;
	}
	new_x = (game->enemy_image->instances[1].x / TILE_SIZE) \
	+ dx[direction2];
	new_y = (game->enemy_image->instances[1].y / TILE_SIZE) \
	+ dy[direction2];
	if (new_x >= 0 && new_x < game->cols && new_y >= 0 && \
		new_y < game->rows && game->map[new_y][new_x] == '0' && \
		new_x != game->player_image->instances[0].x &&
		new_y != game->player_image->instances[0].y && game->enemies[0].x != new_x && game->enemies[0].y != new_y)
	{
		game->enemy_image->instances[1].x = new_x * TILE_SIZE;
		game->enemy_image->instances[1].y = new_y * TILE_SIZE;
	}
}

int	render_enemies(t_game *game)
{
	int	is_valid;

	is_valid = 0;
	game->enemy_image = create_image(game, 'v');
	if (!game->enemy_image)
		return (0);
	srand(time(NULL));
	while (!is_valid)
	{
		game->enemies[0].x = rand() % game->cols;
		game->enemies[0].y = rand() % game->rows;
		if (game->map[game->enemies[0].y][game->enemies[0].x] == '0')
			is_valid = 1;
	}
	is_valid = 0;
	while (!is_valid)
	{
		game->enemies[1].x = rand() % game->cols;
		game->enemies[1].y = rand() % game->rows;
		if (game->map[game->enemies[1].y][game->enemies[1].x] == '0')
			is_valid = 1;
	}
	if (mlx_image_to_window(game->mlx, game->enemy_image, \
		game->enemies[0].x * TILE_SIZE, game->enemies[0].y * TILE_SIZE) < 0)
		return (ft_error3(32));
	game->enemy_count = 1;
	if (mlx_image_to_window(game->mlx, game->enemy_image, \
		game->enemies[1].x * TILE_SIZE, game->enemies[1].y * TILE_SIZE) < 0)
		return (ft_error3(32));
	game->enemy_count = 2;
	return (1);
}
