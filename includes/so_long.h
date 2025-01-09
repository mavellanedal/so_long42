/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:55:16 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/09 18:01:08 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>

//Error message
# define PARAMETERS_ERROR "ERROR\nYou must pass as parameter only the map"
# define FILE_EXTENSION_ERROR "ERROR\nYou must pass as parameter a .ber file"

int	ft_error(int nbr_error);
int	check_file_extension(char *file_name);

#endif