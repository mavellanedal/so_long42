/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:08:16 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/12 22:42:51 by mavellan         ###   ########.fr       */
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

int	initialize_game(t_game *game, const char *file_path)
{
	if (load_and_validate_map(file_path, &game->map, &game->width, &game->height) < 0)
		return (-1);
	game->mlx = mlx_init(game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long", false);
	if (game->mlx)
	{
		ft_printf(MLX_INIT);
		free_map(game->map, game->height);
		return (-1);
	}
	return (0);
}

int	load_textures(t_game *game, mlx_texture_t **wall_texture, mlx_texture_t **floor_texture)
{
	*wall_texture = mlx_load_png("../assets/wall.png");
	*floor_texture = mlx_load_png("../assets/floor.png");
	if (!*wall_texture || !*floor_texture)
	{
		ft_printf(LOAD_TEXTURES);
		return (-1);
	}
	game->wall_img = mlx_texture_to_image(game->mlx, *wall_texture);
	game->floor_img = mlx_texture_to_image(game->mlx, *floor_texture);
	if (!game->wall_img || !game->floor_img)
	{
		ft_printf(FILED_CONVERT);
		return(-1);
	}
	return (0);
}
