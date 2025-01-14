/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:22:31 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/14 15:44:37 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(int nbr_error)
{
	if (nbr_error == 1)
		return (ft_printf(PARAMETERS_ERROR));
	else if (nbr_error == 2)
		return (ft_printf(FILE_EXTENSION_ERROR));
	else if (nbr_error == 3)
		return (ft_printf(FILE_MAP));
	else if (nbr_error == 4)
		return (ft_printf(INCONSISTENT_MAP_WIDTH));
	else if (nbr_error == 5)
		return (ft_printf(MLX_INIT));
	else if (nbr_error == 5)
		return (ft_printf(LOAD_TEXTURES));
	return (0);
}
