/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:12:43 by mavellan          #+#    #+#             */
/*   Updated: 2025/02/03 12:50:52 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_c_checker(char **map, int *c)
{
	int	i;
	int	j;

	if (map == NULL || c == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				*c += 1;
			j++;
		}
		i++;
	}
}

void	ft_e_checker(char **map, int *e)
{
	int	i;
	int	j;

	if (map == NULL || e == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				*e += 1;
			j++;
		}
		i++;
	}
}

void	ft_p_checker(char **map, int *p)
{
	int	i;
	int	j;

	if (map == NULL || p == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				*p += 1;
			j++;
		}
		i++;
	}
}

int	ft_check_chars(char **map)
{
	int	p;
	int	e;
	int	c;

	if (map == NULL)
		return (1);
	p = 0;
	e = 0;
	c = 0;
	ft_p_checker(map, &p);
	ft_e_checker(map, &e);
	ft_c_checker(map, &c);
	if (p == 1 && e == 1 && c >= 1)
		return (0);
	return (1);
}
