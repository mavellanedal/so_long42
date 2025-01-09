/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:02:56 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/11 16:53:08 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr(int num, int *len)
{
	char	str;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len = 11;
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		*len += 1;
	}
	if (num >= 10)
		ft_putnbr (num / 10, len);
	str = num % 10 + '0';
	write(1, &str, 1);
	*len += 1;
}

int	ft_print_int(va_list args)
{
	int		len;
	int		num;

	len = 0;
	num = va_arg(args, int);
	ft_putnbr(num, &len);
	return (len);
}
