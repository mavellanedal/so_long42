/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:44 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/06 13:08:04 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_detect_move(t_game *game)
{
	if ((game->images->enemy_image->instances->x \
	< game->images->player_image->instances->x) \
	&& (game->map[game->images->enemy_image->instances->y / TILE_SIZE] \
	[game->images->enemy_image->instances->x / TILE_SIZE + 1] != '1'))
		return ('r');
	else if ((game->images->enemy_image->instances->x > \
	game->images->player_image->instances->x) \
	&& (game->map[game->images->enemy_image->instances->y / TILE_SIZE] \
	[game->images->enemy_image->instances->x / TILE_SIZE - 1] != '1'))
		return ('l');
	else if ((game->images->enemy_image->instances->y < \
	game->images->player_image->instances->y) \
	&& (game->map[game->images->enemy_image->instances->y / TILE_SIZE + 1] \
	[game->images->enemy_image->instances->x / TILE_SIZE] != '1'))
		return ('d');
	else if ((game->images->enemy_image->instances->y > \
	game->images->player_image->instances->y) \
	&& (game->map[game->images->enemy_image->instances->y / TILE_SIZE - 1] \
	[game->images->enemy_image->instances->x / TILE_SIZE] != '1'))
		return ('u');
	else
		return ('x');
}

void	move_enemy(t_game *game)
{
	if (ft_detect_move(game) == 'u')
		game->images->enemy_image->instances->y -= TILE_SIZE;
	else if (ft_detect_move(game) == 'd')
		game->images->enemy_image->instances->y += TILE_SIZE;
	else if (ft_detect_move(game) == 'l')
		game->images->enemy_image->instances->x -= TILE_SIZE;
	else if (ft_detect_move(game) == 'r')
		game->images->enemy_image->instances->x += TILE_SIZE;
}

void	ft_enemy_detection(t_game *game)
{
	if (game->images->enemy_image->instances->x \
	== game->images->player_image->instances->x \
	&& game->images->enemy_image->instances->y \
	== game->images->player_image->instances->y)
		ft_game_over(game);
}

void	ft_place_random_enemy(t_game *game, t_images *img, int rows, int cols)
{
	int	random_x;
	int	random_y;

	random_x = 0;
	random_y = 0;
	srand(time(NULL));
	while (game->map[random_y][random_x] != '0')
	{
		random_y = rand() % rows;
		random_x = rand() % cols;
	}
	mlx_image_to_window(game->mlx, img->enemy_image, random_x * \
	TILE_SIZE, random_y * TILE_SIZE);
	game->enemy_count++;
}
