/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:11:37 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/18 21:59:15 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	rarb(t_list *stack_a, t_list *stack_b, int nbr, char s)
{
	int	i;

	i = 0;
	if (s == 'b')
	{
		i = search_target(stack_b, nbr, 'b');
		if (i < search_index(stack_a, nbr))
			i = search_index(stack_a, nbr);
	}
	else if (s == 'a')
	{
		i = search_target(stack_a, nbr, 'a');
		if (i < search_index(stack_b, nbr))
			i = search_index(stack_b, nbr);
	}
	return (i);
}

int	rarrb(t_list *stack_a, t_list *stack_b, int nbr, char s)
{
	int	i;

	i = 0;
	if (s == 'b')
	{
		if (search_target(stack_b, nbr, 'b'))
			i = ft_lstsize(stack_b) - search_target(stack_b, nbr, 'b');
		i += search_index(stack_a, nbr);
	}
	else if (s == 'a')
	{
		if (search_index(stack_b, nbr))
			i = ft_lstsize(stack_b) - search_index(stack_b, nbr);
		i += search_target(stack_a, nbr, 'a');
	}
	return (i);
}

int	rrarb(t_list *stack_a, t_list *stack_b, int nbr, char s)
{
	int	i;

	i = 0;
	if (s == 'b')
	{
		if (search_index(stack_a, nbr))
			i = ft_lstsize(stack_a) - search_index(stack_a, nbr);
		i += search_target(stack_b, nbr, 'b');
	}
	else if (s == 'a')
	{
		if (search_target(stack_a, nbr, 'a'))
			i = ft_lstsize(stack_a) - search_target(stack_a, nbr, 'a');
		i += search_index(stack_b, nbr);
	}
	return (i);
}

int	rrarrb(t_list *stack_a, t_list *stack_b, int nbr, char s)
{
	int	i;

	i = 0;
	if (s == 'b')
	{
		if (search_target(stack_b, nbr, 'b'))
			i = ft_lstsize(stack_b) - search_target(stack_b, nbr, 'b');
		if ((i < (ft_lstsize(stack_a) - search_index(stack_a, nbr)))
			&& search_index(stack_a, nbr))
			i = ft_lstsize(stack_a) - search_index(stack_a, nbr);
	}
	else if (s == 'a')
	{
		if (search_target(stack_a, nbr, 'a'))
			i = ft_lstsize(stack_a) - search_target(stack_a, nbr, 'a');
		if ((i < (ft_lstsize(stack_b) - search_index(stack_b, nbr)))
			&& search_index(stack_b, nbr))
			i = ft_lstsize(stack_b) - search_index(stack_b, nbr);
	}
	return (i);
}
