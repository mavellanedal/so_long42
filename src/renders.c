/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:09:53 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/17 11:18:52 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_walls(mlx_t *mlx, char **map, int rows, int cols)
{
	mlx_texture_t	*wall_texture;
	mlx_image_t		*wall_image;
	int				x;
	int				y;

	wall_texture = mlx_load_png("assets/wall.png");
	if (!wall_texture)
		return(ft_error2(13));
	wall_image = mlx_texture_to_image(mlx, wall_texture);
	mlx_delete_texture(wall_texture);
	if (!wall_image)
		return(ft_error2(14));
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(mlx, wall_image, x * TILE_SIZE, y * TILE_SIZE) < 0)
					return(ft_error2(15));
			}
			x++;
		}
		y++;
	}
	return (1);
}
