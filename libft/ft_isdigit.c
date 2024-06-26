/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:51:26 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/18 21:59:40 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char *c)
{
	int	i;
	int	j;

	i = 0;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i] == '0' && c[i] >= '0' && c[i] <= '9')
		i++;
	j = 0;
	while (c[i] && c[i] >= '0' && c[i] <= '9')
	{
		j++;
		i++;
	}
	if (c[i] == '\0' && j <= 10)
		return (1);
	return (0);
}
