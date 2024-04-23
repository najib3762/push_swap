/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:30:14 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/20 18:37:20 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	search_index(t_list *stack, int number)
{
	t_list	*curr;
	int		i;

	curr = stack;
	i = 0;
	while (curr->content != number)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

int	search_target2(t_list *stack, int nbr, char s, int i)
{
	t_list	*tmp;

	if (s == 'b')
	{
		tmp = stack->next;
		while (stack->content < nbr || tmp->content > nbr)
		{
			stack = stack->next;
			tmp = tmp->next;
			i++;
		}
	}
	else if (s == 'a')
	{
		tmp = stack->next;
		while (stack->content > nbr || tmp->content < nbr)
		{
			stack = stack->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

int	search_target(t_list *stack, int nbr, char s)
{
	int	i;

	i = 1;
	if ((s == 'b' && nbr > stack->content && nbr < ft_lstlast(stack)->content)
		|| (s == 'a' && nbr < stack->content
			&& nbr > ft_lstlast(stack)->content))
		i = 0;
	else if (s == 'b' && (nbr > get_max(stack) || nbr < get_min(stack)))
		i = search_index(stack, get_max(stack));
	else if (s == 'a' && (nbr > get_max(stack) || nbr < get_min(stack)))
		i = search_index(stack, get_min(stack));
	else
		i = search_target2(stack, nbr, s, i);
	return (i);
}
