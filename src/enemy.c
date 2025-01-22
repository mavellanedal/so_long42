/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:44 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/22 16:40:15 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_enemy(t_game *game)
{
	int				x;
	int				y;

	game->enemy_image = create_image(game, 'v');
	if (!game->enemy_image)
		return (0);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'M')
			{
				if (mlx_image_to_window(game->mlx, game->enemy_image, \
				x * TILE_SIZE, y * TILE_SIZE) < 0)
					return (ft_error2(31));
			}
			x++;
		}
		y++;
	}
	return (1);
}
