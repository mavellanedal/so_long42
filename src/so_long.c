/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:07:41 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/10 18:33:43 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game			game;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;

	wall_texture = NULL;
	floor_texture = NULL;

	if (ac != 2)
		return (ft_error(1));

	if (load_and_validate_map(av[1], &game.map, &game.width, &game.height) < 0)
		return (ft_error(3));
	game.mlx = mlx_init(game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long", false);
	if (!game.mlx)
		return (ft_error(5));
	return (0);
}

