/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ender.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:57:05 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/03 11:23:08 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_clean_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->images->floor_image);
	mlx_delete_image(game->mlx, game->images->animation1_image);
	mlx_delete_image(game->mlx, game->images->animation2_image);
	mlx_delete_image(game->mlx, game->images->animation3_image);
	mlx_delete_image(game->mlx, game->images->coin_image);
	mlx_delete_image(game->mlx, game->images->enemy_image);
	mlx_delete_image(game->mlx, game->images->exit_image);
	mlx_delete_image(game->mlx, game->images->menu_image);
	mlx_delete_image(game->mlx, game->images->player_image);
	mlx_delete_image(game->mlx, game->images->wall_image);
}

void	ft_cleanup_game(t_game *game)
{
	if (game->map)
	{
		ft_free(game->map);
		game->map = NULL;
	}
	if (game->textures)
	{
		free(game->textures);
		game->textures = NULL;
	}
	if (game->images)
	{
		ft_clean_images(game);
		free(game->images);
		game->images = NULL;
	}
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	exit (0);
}

void	ft_game_over(t_game *game)
{
	ft_printf("Game Over!\n");
	ft_cleanup_game(game);
	exit(1);
}
