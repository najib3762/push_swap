/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:35:28 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/17 20:34:08 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*serc;
	char	*dest;
	size_t	i;

	if (!dst && !src)
		return (dst);
	dest = (char *)dst;
	serc = (char *)src;
	i = 0;
	if (dst > src)
		while (len-- > 0)
			dest[len] = serc[len];
	else
	{
		while (i < len)
		{
			dest[i] = serc[i];
			i++;
		}
	}
	return (dst);
}
/*int main ()
{
	char src[]="world world";
	printf("%s",ft_memmove(src+2,src,3));
	return (0);
}*/
