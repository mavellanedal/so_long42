/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:30:49 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/22 16:39:37 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*create_image(t_game *game, char asset)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	char			*path;

	path = check_asset(asset);
	texture = mlx_load_png(path);
	if (!texture)
	{
		check_error(asset, 1);
		return (NULL);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (NULL);
	return (image);
}

char	*check_asset(char asset)
{
	if (asset == 'w')
		return ("assets/wall.png");
	else if (asset == 'f')
		return ("assets/floor.png");
	else if (asset == 'c')
		return ("assets/snitch.png");
	else if (asset == 'p')
		return ("assets/harryPotter.png");
	else if (asset == 'e')
		return ("assets/door.png");
	else if (asset == 'm')
		return ("assets/MenuNormalSize.png");
	else if (asset == 'v')
		return ("assets/voldemort.png");
	return (NULL);
}
