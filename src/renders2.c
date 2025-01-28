/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:19:01 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 16:33:25 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	generate_random_position(t_game *game, int *x, int *y)
{
	int	valid_pos;

	srand(time(NULL));
	valid_pos = 0;
	while (!valid_pos)
	{
		*x = (rand() % game->cols);
		*y = (rand() % game->rows);
		if (game->map[*y][*x] == '0' && *x \
		!= game->player_image->instances[0].x
		/ TILE_SIZE && *y != game->player_image->instances[0].y / TILE_SIZE \
		&& *x != game->enemies[0].x / TILE_SIZE \
		&& *y != game->enemies[0].y / TILE_SIZE \
		&& *x != game->enemies[1].x / TILE_SIZE \
		&& *y != game->enemies[1].y / TILE_SIZE && *x < game->cols * TILE_SIZE \
		&& *y < game->rows * TILE_SIZE)
			valid_pos = 1;
	}
}

int	render_animation1(t_game *game)
{
	int	x;
	int	y;

	game->animation_image1 = create_image(game, 'l');
	if (!game->animation_image1)
		return (0);
	generate_random_position(game, &x, &y);
	if (mlx_image_to_window(game->mlx, game->animation_image1, \
	x * TILE_SIZE, y * TILE_SIZE) < 0)
		return (ft_error2(15));
	game->animation_pos.x = x;
	game->animation_pos.y = y;
	return (1);
}

int	render_animation2(t_game *game)
{
	game->animation_image2 = create_image(game, 'u');
	if (!game->animation_image2)
		return (0);
	if (mlx_image_to_window(game->mlx, game->animation_image2, \
	game->animation_pos.x * TILE_SIZE, game->animation_pos.y * TILE_SIZE) < 0)
		return (ft_error2(15));
	return (1);
}

int	render_animation3(t_game *game)
{
	game->animation_image3 = create_image(game, 't');
	if (!game->animation_image3)
		return (0);
	if (mlx_image_to_window(game->mlx, game->animation_image3, \
	game->animation_pos.x * TILE_SIZE, game->animation_pos.y * TILE_SIZE) < 0)
		return (ft_error2(15));
	return (1);
}
