/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:19:01 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/27 18:09:30 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_animation1(t_game *game)
{
	int	x;
	int	y;

	game->animation_image1 = create_image(game, 'l');
	if (!game->animation_image1)
		return (0);
	x = (rand() % game->cols) / TILE_SIZE;
	y = (rand() % game->rows) / TILE_SIZE;
	if (game->map[y][x] != '0' || \
	(x == game->enemy_image->instances[0].x \
	&& y == game->enemy_image->instances[0].y) \
	|| (x == game->enemy_image->instances[1].x \
	&& y == game->enemy_image->instances[1].y))
	{
		if (mlx_image_to_window(game->mlx, game->animation_image1, \
		x * TILE_SIZE, y * TILE_SIZE) < 0)
			return (ft_error2(15));
	}
	return (1);
}

int	render_animation2(t_game *game)
{
	int	x;
	int	y;

	game->animation_image2 = create_image(game, 'u');
	if (!game->animation_image2)
		return (0);
	x = game->animation_image1->instances[0].x;
	y = game->animation_image1->instances[0].y;
	if (game->map[y][x] != '0' || \
	(x == game->enemy_image->instances[0].x \
	&& y == game->enemy_image->instances[0].y) \
	|| (x == game->enemy_image->instances[1].x \
	&& y == game->enemy_image->instances[1].y))
	{
		if (mlx_image_to_window(game->mlx, game->animation_image2, \
		x * TILE_SIZE, y * TILE_SIZE) < 0)
			return (ft_error2(15));
	}
	return (1);
}

int	render_animation3(t_game *game)
{
	int	x;
	int	y;

	game->animation_image3 = create_image(game, 't');
	if (!game->animation_image3)
		return (0);
	x = game->animation_image1->instances[0].x;
	y = game->animation_image1->instances[0].y;
	if (game->map[y][x] != '0' || \
	(x == game->enemy_image->instances[0].x \
	&& y == game->enemy_image->instances[0].y) \
	|| (x == game->enemy_image->instances[1].x \
	&& y == game->enemy_image->instances[1].y))
	{
		if (mlx_image_to_window(game->mlx, game->animation_image3, \
		x * TILE_SIZE, y * TILE_SIZE) < 0)
			return (ft_error2(15));
	}
	return (1);
}
