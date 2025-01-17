/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:16:26 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/17 10:39:14 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	start_game(char **map, int rows, int cols)
{
	mlx_t	*mlx;

	mlx = mlx_init(cols * TILE_SIZE, rows *TILE_SIZE, "so_long", true);
	if (!mlx)
		return(ft_error(12));
	if (render_walls(mlx, map, rows, cols) != 1)
		return(0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (1);
}

int	main(int ac, char **av)
{
	char	**map;
	int		rows;

	if (ac != 2)
		return (ft_error(1));
	rows = 0;
	map = read_map(av[1], &rows);
	if (map == NULL)
		return (ft_error(3));
	if (map_checks(map, rows, av[1]) != 0)
	{
		free_map(map);
		return (0);
	}
	if (start_game(map, rows, ft_strlen(map[0])) != 1)
	{
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}
