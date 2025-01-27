/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:37:31 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/27 18:08:55 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_menu(t_game *game)
{
	game->menu_image = create_image(game, 'm');
	if (!game->menu_image)
		return (0);
	if (mlx_image_to_window(game->mlx, game->menu_image, 0, 0) < 0)
		return (ft_error2(28));
	return (1);
}

void	update_game_info(t_game *game)
{
	char	*move_text;
	char	*coin_text;

	move_text = NULL;
	coin_text = NULL;
	move_text = ft_strjoin("Movements: ", ft_itoa(game->moves));
	if (!move_text)
		return ;
	mlx_image_to_window(game->mlx, game->menu_image, 0, 0);
	mlx_put_string(game->mlx, move_text, 20, 0);
	free(move_text);
}
