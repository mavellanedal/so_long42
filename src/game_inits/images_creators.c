/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_renders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:06:09 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/03 13:04:14 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_create_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->textures->floor_texture = mlx_load_png("./assets/floor.png");
	game->textures->coin_texture = mlx_load_png("./assets/snitch.png");
	game->textures->wall_texture = mlx_load_png("./assets/wall.png");
	game->textures->player_texture = mlx_load_png("./assets/harryPotter.png");
	game->textures->animation1_texture = mlx_load_png("./assets/vela1.png");
	game->textures->animation2_texture = mlx_load_png("./assets/vela2.png");
	game->textures->animation3_texture = mlx_load_png("./assets/vela3.png");
	game->textures->enemy_texture = mlx_load_png("./assets/voldemort.png");
	game->textures->exit_texture = mlx_load_png("./assets/door.png");
	game->textures->menu_texture = mlx_load_png("./assets/MenuNormalSize.png");
}

void	ft_create_imgs(t_game *game)
{
	game->images = ft_calloc(1, sizeof(t_images));
	game->images->floor_image = mlx_texture_to_image(game->mlx, game->textures->floor_texture);
	game->images->coin_image = mlx_texture_to_image(game->mlx, game->textures->coin_texture);
	game->images->wall_image = mlx_texture_to_image(game->mlx, game->textures->wall_texture);
	game->images->player_image = mlx_texture_to_image(game->mlx, game->textures->player_texture);
	game->images->enemy_image = mlx_texture_to_image(game->mlx, game->textures->enemy_texture);
	game->images->exit_image = mlx_texture_to_image(game->mlx, game->textures->exit_texture);
	game->images->menu_image = mlx_texture_to_image(game->mlx, game->textures->menu_texture);
	game->images->animation1_image = mlx_texture_to_image(game->mlx, game->textures->animation1_texture);
	game->images->animation2_image = mlx_texture_to_image(game->mlx, game->textures->animation2_texture);
	game->images->animation3_image = mlx_texture_to_image(game->mlx, game->textures->animation3_texture);
	ft_delete_textures(game);
}

void	ft_delete_textures(t_game *game)
{
	mlx_delete_texture(game->textures->floor_texture);
	mlx_delete_texture(game->textures->coin_texture);
	mlx_delete_texture(game->textures->wall_texture);
	mlx_delete_texture(game->textures->player_texture);
	mlx_delete_texture(game->textures->animation1_texture);
	mlx_delete_texture(game->textures->animation2_texture);
	mlx_delete_texture(game->textures->animation3_texture);
	mlx_delete_texture(game->textures->enemy_texture);
	mlx_delete_texture(game->textures->exit_texture);
	mlx_delete_texture(game->textures->menu_texture);
}
