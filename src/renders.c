/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:09:53 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/17 18:13:36 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_walls(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_image_t		*wall_image;
	int				x;
	int				y;

	wall_image = create_image(mlx, 'w');
	if (!wall_image)
		return (0);
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(mlx, wall_image, x * TILE_SIZE, \
					y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	render_floor(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_image_t		*floor_image;
	int				x;
	int				y;

	floor_image = create_image(mlx, 'f');
	if (!floor_image)
		return (0);
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(mlx, floor_image, x * TILE_SIZE, \
					y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	render_player(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_image_t		*player_image;
	int				x;
	int				y;

	player_image = create_image(mlx, 'p');
	if (!player_image)
		return (0);
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(mlx, player_image, x * TILE_SIZE, \
					y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	render_coin(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_image_t		*coin_image;
	int				x;
	int				y;

	coin_image = create_image(mlx, 'c');
	if (!coin_image)
		return (0);
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(mlx, coin_image, x * TILE_SIZE, \
					y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	render_exit(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_image_t		*exit_image;
	int				x;
	int				y;

	exit_image = create_image(mlx, 'e');
	if (!exit_image)
		return (0);
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(mlx, exit_image, x * TILE_SIZE, \
					y * TILE_SIZE) < 0)
					return (ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}
