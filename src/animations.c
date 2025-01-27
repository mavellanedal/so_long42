/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:33:27 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/27 17:42:43 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animation(t_game *game)
{
	static double	last_time = 0;
	static int		status = 0;
	double			current_time;

	current_time = mlx_get_time();
	if (current_time - last_time > 0.1)
	{
		game->animation_image1->instances->enabled = false;
		game->animation_image2->instances->enabled = false;
		game->animation_image3->instances->enabled = false;
		if (status == 0)
			game->animation_image1->instances->enabled = true;
		else if (status == 1)
			game->animation_image2->instances->enabled = true;
		else if (status == 2)
			game->animation_image3->instances->enabled = true;
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
