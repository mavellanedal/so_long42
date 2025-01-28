/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:09:53 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 11:02:27 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_walls(t_game *game)
{
	int	y;
	int	x;

	game->wall_image = create_image(game, 'w');
	if (!game->wall_image)
		return (0);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->wall_image, \
				x * TILE_SIZE, y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	render_floor(t_game *game)
{
	int				x;
	int				y;

	game->floor_image = create_image(game, 'f');
	if (!game->floor_image)
		return (0);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] != '1')
			{
				if (mlx_image_to_window(game->mlx, game->floor_image, \
				x * TILE_SIZE, y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	render_player(t_game *game)
{
	int				x;
	int				y;

	game->player_image = create_image(game, 'p');
	if (!game->player_image)
		return (0);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->player_image, \
				x * TILE_SIZE, y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	render_coin(t_game *game)
{
	int				x;
	int				y;

	game->coin_image = create_image(game, 'c');
	if (!game->coin_image)
		return (0);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->coin_image, \
				x * TILE_SIZE, y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	render_exit(t_game *game)
{
	game->exit_x = find_exit_x(game);
	game->exit_y = find_exit_y(game);
	game->exit_image = create_image(game, 'e');
	if (!game->exit_image)
		return (0);
	if (mlx_image_to_window(game->mlx, game->exit_image, \
	game->exit_x * TILE_SIZE, game->exit_y * TILE_SIZE) < 0)
		return (ft_error3(27));
	game->exit_image->instances[0].enabled = false;
	return (1);
}
