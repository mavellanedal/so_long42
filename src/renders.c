/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:08:16 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/10 17:19:30 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_title(t_game *game, int x, int y, char tile)
{
	int	screen_x;
	int	screen_y;

	screen_x = x * TILE_SIZE;
	screen_y = y * TILE_SIZE;
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->wall_img, screen_x, screen_y);
	else if (tile == '0')
		mlx_image_to_window(game->mlx, game->floor_img, screen_x, screen_y);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
			render_title(game, x, y, game->map[y][x]);
	}
}
