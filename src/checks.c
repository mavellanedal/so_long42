/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:47:44 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/09 17:58:49 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file_extension(char *file_name)
{
	if (!ft_strnstr(file_name + (ft_strlen(file_name) - 4), ".ber", 4))
		ft_error(2);
	return (0);
}
