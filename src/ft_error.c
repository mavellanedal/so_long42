/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:48:01 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/06 13:40:55 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(int i)
{
	if (i == 1)
		return (ft_printf(ARGV_MISSING));
	else if (i == 2)
		return (ft_printf(INVALID_CHARS));
	else if (i == 3)
		return (ft_printf(NOT_RECTANGUALR));
	else if (i == 4)
		return (ft_printf(NOT_CLOSED));
	else if (i == 5)
		return (ft_printf(FILE_EXTENSION));
	else if (i == 6)
		return (ft_printf(NO_CORRECT_CONTENTS));
	else if (i == 7)
		return (ft_printf(NO_ACCESIBLE));
	else if (i == 8)
		return (ft_printf(FILE_EMPTY));
	else if (i == 9)
		return (ft_printf(STARTING_GAME));
	else if (i == 10)
		return (ft_printf(MAP_ALLOC));
	else if (i == 1)
		return (ft_printf(BUILDING_MAP));
	return (0);
}
