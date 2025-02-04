/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:15:26 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/31 17:43:49 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**ft_copy_map(char **map, int rows)
{
	int		i;
	char	**copy_map;

	copy_map = malloc(sizeof(char *) * (rows + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy_map[i] = ft_strdup(map[i]);
		if (!copy_map[i])
		{
			while (--i >= 0)
				free(copy_map[i]);
			free(copy_map);
			return (NULL);
		}
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	ft_locate_p(char **map, t_point *char_pos)
{
	int	i;
	int	j;

	if (!map || !char_pos)
		return ;
	char_pos->row = -1;
	char_pos->col = -1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				char_pos->row = i;
				char_pos->col = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_is_target(char c)
{
	if (c == 'C' || c == 'E')
		return (1);
	return (0);
}

void	ft_flood_fill(char **flood_m, t_point *char_pos, int row, int col)
{
	if (row < 0 || col < 0 || row >= char_pos->max_rows
		|| col >= char_pos->max_cols)
		return ;
	if (ft_is_target(flood_m[row][col]))
		char_pos->check += 1;
	if (flood_m[row][col] == 'F' || flood_m[row][col] == '1')
		return ;
	flood_m[row][col] = 'F';
	ft_flood_fill(flood_m, char_pos, row + 1, col);
	ft_flood_fill(flood_m, char_pos, row - 1, col);
	ft_flood_fill(flood_m, char_pos, row, col + 1);
	ft_flood_fill(flood_m, char_pos, row, col - 1);
}

int	ft_check_path(char **map, int rows, int cols)
{
	t_point	*char_pos;
	int		total;
	char	**flood_map;

	char_pos = ft_create_point(rows, cols);
	if (!char_pos)
		return (1);
	ft_locate_p(map, char_pos);
	if (char_pos->row == -1 || char_pos->col == -1)
		return (ft_cleanup(char_pos, NULL, 1));
	flood_map = ft_copy_map(map, rows);
	total = ft_ent_count(map);
	ft_flood_fill(flood_map, char_pos, char_pos->row, char_pos->col);
	if (char_pos->check == total)
		return (ft_cleanup(char_pos, flood_map, 0));
	return (ft_cleanup(char_pos, flood_map, 1));
}
