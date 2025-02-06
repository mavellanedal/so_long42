/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:10:23 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/06 13:36:27 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_row_wall(char *row, int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (row[i++] != '1')
			return (1);
	return (0);
}

int	ft_check_if_close(char **map, int rows, int cols)
{
	int	i;
	int	row_len;

	if (rows < 1 || cols < 1 || map[0] == NULL)
		return (1);
	if (ft_check_row_wall(map[0], cols) || \
	ft_check_row_wall(map[rows - 1], cols))
		return (1);
	i = 0;
	while (i < rows)
	{
		row_len = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][row_len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	is_rectangular(char **map, int rows)
{
	int	row_l;
	int	row_c;
	int	i;

	if (rows == 0 || map[0] == NULL)
		return (1);
	row_l = ft_strlen(map[0]);
	row_c = 0;
	i = 0;
	while (map[i])
	{
		row_c = ft_strlen(map[i]);
		if (row_c != row_l)
			return (1);
		i++;
	}
	return (0);
}

int	ft_empty_checker(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i] == NULL || map[i][0] == '\0' || map[i][0] == '\n' \
		|| map[i][0] == '\r')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checker(char **map, int rows, int cols)
{
	int	checker;

	checker = ft_empty_checker(map, rows);
	if (checker)
		return (ft_error(8));
	checker += is_rectangular(map, rows);
	if (checker)
		return (ft_error(3));
	checker += ft_check_if_close(map, rows, cols);
	if (checker)
		return (ft_error(4));
	checker += ft_check_chars(map);
	if (checker)
		return (ft_error(6));
	checker += ft_check_entities(map);
	if (checker)
		return (ft_error(2));
	checker += ft_check_path(map, rows, cols);
	if (checker)
		return (ft_error(7));
	return (checker);
}
