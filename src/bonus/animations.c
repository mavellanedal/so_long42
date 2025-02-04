/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:33:27 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/04 08:54:09 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	animation(t_game *game)
{
	static double	last_time = 0;
	static int		status = 0;
	double			current_time;
	current_time = mlx_get_time();
	if (current_time - last_time > 0.1)
	{

		game->images->animation1_image->instances->enabled = false;
		game->images->animation2_image->instances->enabled = false;
		game->images->animation3_image->instances->enabled = false;
		if (status == 0)
			game->images->animation1_image->instances->enabled = true;
		else if (status == 1)
			game->images->animation2_image->instances->enabled = true;
		else if (status == 2)
			game->images->animation3_image->instances->enabled = true;
		status = (status + 1) % 3;
		last_time = current_time;
	}
}

void	hook_loop(void *param)
{
	t_game	*game;

	game = param;
	animation(game);
}
