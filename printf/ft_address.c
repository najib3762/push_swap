/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macpro15 <macpro15@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:16:17 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/05 12:38:03 by macpro15         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_addresss(unsigned long nbr)
{
	char	*arr;
	int		printed;

	printed = 0;
	arr = "0123456789abcdef";
	if (nbr >= 16)
	{
		printed += ft_addresss(nbr / 16);
		return (printed += ft_addresss(nbr % 16));
	}
	else
	{
		putcharr(arr[nbr]);
		printed++;
	}
	return (printed);
}
