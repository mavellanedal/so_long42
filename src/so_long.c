/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:07:41 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/14 18:16:41 by mavellan         ###   ########.fr       */
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
	if (check_file_extension(av[1]) < 0)
		return (ft_error(2));
	if (initialize_game(&game, av[1]) < 0)
		return (ft_error(5));
	if (load_textures(&game, &wall_texture, &floor_texture) < 0)
	{
		cleanup(&game, wall_texture, floor_texture);
		return (ft_error(6));
	}
	render_map(&game);
	mlx_loop(game.mlx);
	cleanup(&game, wall_texture, floor_texture);
	return (0);
}
