/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:09:32 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 16:59:24 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		total_len;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(total_len + 1);
	i = 0;
	j = 0;
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

/*#include <stdio.h>
int	main(void)
{
	printf("La cadena resultado es: %s", ft_strjoin("tripouille", "42"));
}*/
