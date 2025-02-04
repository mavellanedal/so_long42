/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:13:52 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/31 17:43:26 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_point	*ft_create_point(int rows, int cols)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (point)
	{
		point->max_rows = rows;
		point->max_cols = cols;
		point->check = 0;
	}
	return (point);
}

int	ft_cleanup(t_point *char_pos, char **flood_map, int ret)
{
	free(char_pos);
	if (flood_map)
		ft_free(flood_map);
	return (ret);
}

int	ft_ent_count(char **map)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

int	ft_valid_chars(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

int	ft_check_entities(char **map)
{
	int	i;
	int	j;

	if (map == NULL)
		return (1);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_valid_chars(map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
