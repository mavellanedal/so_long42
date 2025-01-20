/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:21:32 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/20 16:31:27 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_key(mlx_key_data_t keydata, void *param, t_game *game)
{
	ft_printf("In of handle_key");
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
			game->player_y -= 10;
		else if (keydata.key == MLX_KEY_S)
			game->player_y += 10;
		else if (keydata.key == MLX_KEY_A)
			game->player_x -= 10;
		else if (keydata.key == MLX_KEY_D)
			game->player_x += 10;
	}
	mlx_image_to_window(game->mlx, game->player_image, \
	game->player_x, game->player_y);
}
