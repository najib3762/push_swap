/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macpro15 <macpro15@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:31:19 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/05 12:38:03 by macpro15         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	my_tolower(int c)
{
	return (c + 32 * (c >= 'A' && c <= 'Z'));
}

int	ft_putnbr_base(long nbr, int base, unsigned char is_upper)
{
	char	*arr;
	int		printed;

	printed = 0;
	arr = "0123456789ABCDEF";
	if (nbr < 0)
	{
		printed += putcharr('-');
		nbr = -nbr;
	}
	if (nbr >= base)
	{
		printed += ft_putnbr_base(nbr / base, base, is_upper);
		return (printed += ft_putnbr_base(nbr % base, base, is_upper));
	}
	else
	{
		if (is_upper)
			putcharr(arr[nbr]);
		else
			putcharr(my_tolower(arr[nbr]));
		printed++;
	}
	return (printed);
}
