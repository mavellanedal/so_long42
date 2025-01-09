/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:28:51 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/11 12:02:54 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	char	digit;

	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}
