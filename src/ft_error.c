/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:48:01 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 16:58:52 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(int i)
{
	if (i == 0)
		return (ft_printf(ARGV_MISSING));
	else if (i == 2)
		return (ft_printf(MLX_INIT));
	else if (i == 3)
		return (ft_printf(READING_MAP));
	else if (i == 4)
		return (ft_printf(INVALID_CHARS));
	else if (i == 5)
		return (ft_printf(NOT_RECTANGUALR));
	else if (i == 6)
		return (ft_printf(NOT_CLOSED));
	else if (i == 7)
		return (ft_printf(FILE_EXTENSION));
	else if (i == 8)
		return (ft_printf(NOT_EXIT));
	else if (i == 9)
		return (ft_printf(NOT_COLECTIONABLES));
	else if (i == 10)
		return (ft_printf(NOT_POSITION));
	else if (i == 11)
		return (ft_printf(NO_ACCESIBLE));
	else if (i == 12)
		return (ft_printf(INIT_MLX));
	return (0);
}

int	ft_error2(int i)
{
	if (i == 13)
		return (ft_printf(WALL_TEXTURE_LOAD));
	else if (i == 14)
		return (ft_printf(CREATE_WALL_IMG));
	else if (i == 15)
		return (ft_printf(DRAW_WALL));
	else if (i == 16)
		return (ft_printf(FLOOR_TEXTURE_LOAD));
	else if (i == 17)
		return (ft_printf(CREATE_FLOOR_IMG));
	else if (i == 18)
		return (ft_printf(DRAW_FLOOR));
	else if (i == 19)
		return (ft_printf(COIN_TEXTURE_LOAD));
	else if (i == 20)
		return (ft_printf(CREATE_COIN_IMG));
	else if (i == 21)
		return (ft_printf(DRAW_COIN));
	else if (i == 22)
		return (ft_printf(PLAYER_TEXTURE_LOAD));
	else if (i == 23)
		return (ft_printf(CREATE_PLAYER_IMG));
	else if (i == 24)
		return (ft_printf(DRAW_PLAYER));
	return (0);
}

int	ft_error3(int i)
{
	if (i == 25)
		return (ft_printf(EXIT_TEXTURE_LOAD));
	else if (i == 26)
		return (ft_printf(CREATE_EXIT_IMG));
	else if (i == 27)
		return (ft_printf(DRAW_EXIT));
	else if (i == 28)
		return (ft_printf(MENU_TEXTURE_LOAD));
	else if (i == 29)
		return (ft_printf(CREATE_MENU_IMG));
	else if (i == 30)
		return (ft_printf(DRAW_MENU));
	else if (i == 31)
		return (ft_printf(ENEMY_TEXTURE_LOAD));
	else if (i == 32)
		return (ft_printf(CREATE_ENEMY_IMG));
	else if (i == 33)
		return (ft_printf(DRAW_ENEMY));
	else if (i == 34)
		return (ft_printf(FILE_EMPTY));
	return (0);
}

int	check_error(char asset, int i)
{
	if (asset == 'w')
	{
		if (i == 1)
			return (ft_error2(13));
		else if (i == 2)
			return (ft_error2(14));
	}
	else if (asset == 'f')
	{
		if (i == 1)
			return (ft_error2(16));
		else if (i == 2)
			return (ft_error2(17));
	}
	else if (asset == 'm')
	{
		if (i == 1)
			return (ft_error2(29));
		else if (i == 2)
			return (ft_error2(30));
	}
	return (0);
}

int	check_error2(char asset, int i)
{
	if (asset == 'c')
	{
		if (i == 1)
			return (ft_error2(19));
		else if (i == 2)
			return (ft_error2(20));
	}
	else if (asset == 'p')
	{
		if (i == 1)
			return (ft_error2(22));
		else if (i == 2)
			return (ft_error2(23));
	}
	else if (asset == 'v')
	{
		if (i == 1)
			return (ft_error3(31));
		else if (i == 2)
			return (ft_error3(32));
	}
	return (0);
}
