/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:09:53 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/04 10:31:55 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_has_empty_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_render_floor(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, image->floor_image, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, image->wall_image, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, image->exit_image, x * TILE_SIZE, y * TILE_SIZE);
				game->images->exit_image->instances->enabled = false;
			}
			x++;
		}
		y++;
	}
}

void	ft_render_map(t_game *game, t_images *img)
{
	int	x;
	int	y;
	int	random_y;
	int	random_x;
	int	rows;
	int	cols;

	ft_render_floor(game, img);
	y = -1;
	cols = ft_strlen(game->map[0]);
	rows = ft_array_count(game->map);
	srand(time(NULL));
	if (ft_has_empty_spaces(game->map) && cols >= 10 && rows >= 10)
	{
		random_y = rand() % rows;
		random_x = rand() % cols;
		while (game->map[random_y][random_x] != '0')
		{
			random_y = rand() % rows;
			random_x = rand() % cols;
		}
		mlx_image_to_window(game->mlx, img->enemy_image, random_x * TILE_SIZE, random_y * TILE_SIZE);
		game->enemy_count++;
		random_y = rand() % rows;
		random_x = rand() % cols;
		while (game->map[random_y][random_x] != '0'
		&& random_x == game->images->enemy_image->instances->x
		&& random_y == game->images->enemy_image->instances->y)
		{
			random_y = rand() % rows;
			random_x = rand() % cols;
		}
		mlx_image_to_window(game->mlx, img->animation1_image, random_x * TILE_SIZE, random_y * TILE_SIZE);
		mlx_image_to_window(game->mlx, img->animation2_image, random_x * TILE_SIZE, random_y * TILE_SIZE);
		mlx_image_to_window(game->mlx, img->animation3_image, random_x * TILE_SIZE, random_y * TILE_SIZE);
	}
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, img->player_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, img->coin_image, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

