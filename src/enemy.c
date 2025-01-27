/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:44 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/27 17:58:04 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemy_instances(t_game *game, int instance_index)
{
	int	dx[4];
	int	dy[4];
	int	direction;
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
	direction = rand() % 4;
	new_x = (game->enemy_image->instances[instance_index].x / TILE_SIZE) \
	+ dx[direction];
	new_y = (game->enemy_image->instances[instance_index].y / TILE_SIZE) \
	+ dy[direction];
	if (new_x >= 0 && new_x < game->cols && new_y >= 0 && \
		new_y < game->rows && game->map[new_y][new_x] == '0' && \
		new_x != game->player_image->instances[0].x &&
		new_y != game->player_image->instances[0].y)
	{
		game->enemy_image->instances[instance_index].x = new_x * TILE_SIZE;
		game->enemy_image->instances[instance_index].y = new_y * TILE_SIZE;
	}
}

int	count_empty_positions(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == '0')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	find_empty_positions(t_game *game, t_pos *positions)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == '0')
			{
				positions[index].x = x;
				positions[index].y = y;
				index++;
			}
			x++;
		}
		y++;
	}
}

void	place_enemies(t_game *game)
{
	t_pos	*position;
	int		count;
	int		index1;
	int		index2;

	index1 = 0;
	index2 = 0;
	count = count_empty_positions(game);
	if (count < 2)
		return ;
	position = malloc(sizeof(t_pos) * count);
	if (!position)
		return ;
	find_empty_positions(game, position);
	index1 = rand() % count;
	while (index2 == index1)
	{
		index2 = rand() % count;
	}
	game->enemies[0] = position[index1];
	game->enemies[1] = position[index2];
	free(position);
}

int	render_enemies(t_game *game)
{
	place_enemies(game);
	game->enemy_image = create_image(game, 'v');
	if (!game->enemy_image)
		return (0);
	if (mlx_image_to_window(game->mlx, game->enemy_image, \
		game->enemies[0].x * TILE_SIZE, game->enemies[0].y * TILE_SIZE) < 0)
		return (ft_error3(32));
	if (mlx_image_to_window(game->mlx, game->enemy_image, \
		game->enemies[1].x * TILE_SIZE, game->enemies[1].y * TILE_SIZE) < 0)
		return (ft_error3(32));
	return (1);
}
