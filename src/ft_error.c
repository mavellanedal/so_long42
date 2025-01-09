/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:22:31 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/09 18:00:31 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(int nbr_error)
{
	if (nbr_error == 1)
		return (ft_printf(PARAMETERS_ERROR));
	else if (nbr_error == 2)
		return (ft_printf(FILE_EXTENSION_ERROR));
	return (0);
}
