/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:30:49 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/17 17:59:28 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*create_image(mlx_t *mlx, char asset)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (asset == 'w')
		texture = mlx_load_png("assets/wall.png");
	else if (asset == 'f')
		texture = mlx_load_png("assets/floor.png");
	else if (asset == 'c')
		texture = mlx_load_png("assets/snitch.png");
	else if (asset == 'p')
		texture = mlx_load_png("assets/harryPotter.png");
	else if (asset == 'e')
		texture = mlx_load_png("assets/door.png");
	if (!texture)
		return (check_error(asset, 1));
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (check_error(asset, 2));
	return (image);
}
