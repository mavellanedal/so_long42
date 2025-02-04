/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:45:18 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/04 09:55:19 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**ft_load_map(char *path)
{
	int		rows;
	int		cols;
	char	**map;

	rows = 0;
	cols = 0;
	map = map_checks(path, &rows, &cols);
	if (!map)
		return (NULL);
	return (map);
}

void	ft_mesure_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->total_coins = cont_coins(game);
	game->map_width = ft_strlen(map[0]) * TILE_SIZE;
	while (map[i])
		i++;
	game->map_height = i * TILE_SIZE;
}

int	ft_init_game(t_game *game)
{
	game->moves = 0;
	game->coins = 0;
	game->enemy_count = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->map_width, game->map_height, \
	"so_long mavellan", true);
	if (!(game->mlx))
		return (0);
	ft_create_textures(game);
	ft_create_imgs(game);
	ft_render_map(game, game->images);
	mlx_key_hook(game->mlx, &handle_player_move, game);
	if (game->enemy_count == 1)
		mlx_loop_hook(game->mlx, &hook_loop, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_free(game->map);
	free(game->textures);
	free(game->images);
	return (1);
}
