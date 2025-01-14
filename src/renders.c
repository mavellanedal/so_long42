/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:08:16 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/14 18:18:37 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_title(t_game *game, int x, int y, char tile)
{
	int	screen_x;
	int	screen_y;

	screen_x = x * TIT_SIZE;
	screen_y = y * TIT_SIZE;
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->wall_img, screen_x, screen_y);
	else if (tile == '0')
		mlx_image_to_window(game->mlx, game->floor_img, screen_x, screen_y);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	if (!game || !game->map)
		return ;
	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			render_title(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

int	initialize_game(t_game *game, const char *file_path)
{
	ft_printf("Entro dentro de initialize_game\n");
	if (load_and_validate_map(file_path, &game->map, &game->w, &game->h) < 0)
		return (-1);
	game->mlx = mlx_init(game->w * TIT_SIZE, game->h * TIT_SIZE, "so_long", false);
	if (!game->mlx)
	{
		free_map(game->map, game->h);
		return (-1);
	}
	return (0);
}

int	load_textures(t_game *game, mlx_texture_t **wall, mlx_texture_t **floor)
{
	*wall = mlx_load_png("../assets/wall.png");
	*floor = mlx_load_png("../assets/floor.png");
	if (!*wall || !*floor)
	{
		ft_printf(LOAD_TEXTURES);
		return (-1);
	}
	game->wall_img = mlx_texture_to_image(game->mlx, *wall);
	game->floor_img = mlx_texture_to_image(game->mlx, *floor);
	if (!game->wall_img || !game->floor_img)
	{
		ft_printf(FILED_CONVERT);
		return (-1);
	}
	return (0);
}
