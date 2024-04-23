/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:51:21 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/21 21:58:44 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstfirst(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (lst);
}

void	sort_50(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	min_a;
	int	size;

	i = 0;
	min_a = 0;
	size = ft_lstsize(*stack_a);
	while (size > 3 && !is_sorted(stack_a))
	{
		min_a = get_min(*stack_a);
		i = search_index(*stack_a, get_min(*stack_a));
		if (i > (size / 2))
		{
			while ((*stack_a)->content != min_a)
				rev_rotate_a(stack_a);
			push_b(stack_a, stack_b);
		}
		else
		{
			while ((*stack_a)->content != min_a)
				rotate_a(stack_a);
			push_b(stack_a, stack_b);
		}
		size--;
	}
}
