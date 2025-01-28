/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:44 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 16:30:12 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_if_valid_pos(t_game *game, int *new_y, int *new_x, int enemy_index)
{
	if (*new_x >= 0 && *new_x < game->cols && *new_y >= 0 \
		&& *new_y < game->rows \
		&& game->map[*new_y][*new_x] == '0' &&
		*new_x != game->player_image->instances[0].x / TILE_SIZE &&
		*new_y != game->player_image->instances[0].y / TILE_SIZE &&
		(*new_x != game->enemies[1 - enemy_index].x \
		|| *new_y != game->enemies[1 - enemy_index].y))
		return (1);
	return (0);
}

int	new_enemy_position(t_game *game, int index, int *new_x, int *new_y)
{
	int	dx[4];
	int	dy[4];
	int	direction;

	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
	direction = rand() % 4;
	*new_x = (game->enemy_image->instances[index].x / TILE_SIZE) \
	+ dx[direction];
	*new_y = (game->enemy_image->instances[0].y / TILE_SIZE) \
	+ dy[direction];
	if (check_if_valid_pos(game, new_y, new_x, index))
		return (1);
	return (0);
}

void	move_enemy_instances(t_game *game)
{
	int	new_x;
	int	new_y;

	srand(time(NULL));
	if (new_enemy_position(game, 0, &new_x, &new_y))
	{
		game->enemy_image->instances[0].x = new_x * TILE_SIZE;
		game->enemy_image->instances[0].y = new_y * TILE_SIZE;
	}
	if (new_enemy_position(game, 1, &new_x, &new_y))
	{
		game->enemy_image->instances[1].x = new_x * TILE_SIZE;
		game->enemy_image->instances[1].y = new_y * TILE_SIZE;
	}
}

int	init_enemy_pos(t_game *game, t_pos *enemy)
{
	int	is_valid;

	is_valid = 0;
	while (!is_valid)
	{
		srand(time(NULL));
		enemy->x = (rand() % game->cols);
		enemy->y = (rand() % game->rows);
		if (game->map[enemy->y][enemy->x] == '0')
			is_valid = 1;
	}
	return (1);
}

int	render_enemies(t_game *game)
{
	game->enemy_image = create_image(game, 'v');
	if (!game->enemy_image)
		return (0);
	if (!init_enemy_pos(game, &game->enemies[0]) \
	|| mlx_image_to_window(game->mlx, game->enemy_image, \
	game->enemies[0].x * TILE_SIZE, game->enemies[0].y * TILE_SIZE) < 0)
		return (ft_error3(32));
	if (!init_enemy_pos(game, &game->enemies[1]) \
	|| mlx_image_to_window(game->mlx, game->enemy_image, \
	game->enemies[1].x * TILE_SIZE, game->enemies[1].y * TILE_SIZE) < 0)
		return (ft_error3(32));
	game->enemy_count = 2;
	return (1);
}
