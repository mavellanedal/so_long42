/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:16:26 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/16 16:35:38 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	mlx_t	*mlx;
	char	**map;
	int		rows;

	if (ac != 2)
		return (ft_error(1));
	rows = 0;
	map = read_map(av[1], &rows);
	if (map == NULL)
		return (ft_error(3));
	if (map_checks(map, rows, av[1]) != 0)
		return (1);
	ft_printf("El mapa es correcto.\n");
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		return (ft_error(2));
	mlx_loop(mlx);
	free_map(map);
	mlx_terminate(mlx);
	return (0);
}
