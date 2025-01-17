/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:48:01 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/17 10:40:02 by mavellan         ###   ########.fr       */
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
	return (0);
}
