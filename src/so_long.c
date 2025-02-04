/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:16:26 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/03 13:05:59 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error(1));
	game.map = ft_load_map(av[1]);
	if (!game.map)
		return (1);
	ft_mesure_map(&game, game.map);
	if (ft_init_game(&game) == 0)
		return(ft_printf("ERROR\nAl inicar el juego.\n"));
	return (0);
}
