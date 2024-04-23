/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macpro15 <macpro15@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:55:49 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/05 12:38:03 by macpro15         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	check_format(char format, va_list args)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(args, int), 10, 0));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), 10, 0));
	else if (format == 'x')
		return (ft_putnbr_base((long)va_arg(args, unsigned int), 16, 0));
	else if (format == 'X')
		return (ft_putnbr_base((long)va_arg(args, unsigned int), 16, 1));
	else if (format == 's')
		return (putstrr(va_arg(args, char *)));
	else if (format == 'c')
		return (putcharr(va_arg(args, int)));
	else if (format == '%')
		return (putcharr('%'));
	else if (format == 'p')
	{
		putstrr("0x");
		return (ft_addresss((unsigned long)va_arg(args, void *)) + 2);
	}
	else
		return (putcharr(format));
}

int	ft_printf(const char *s, ...)
{
	int		printed;
	va_list	ap;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start(ap, s);
	printed = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*++s)
				printed += check_format(*s, ap);
			else
				break ;
		}
		else
			printed += write(1, s, 1);
		s++;
	}
	va_end(ap);
	return (printed);
}
