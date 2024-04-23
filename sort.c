/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:31:50 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/22 11:59:37 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

// rarb, rarrb, rrarb, rrarrb
int	count_a_to_b(t_list *stack_a, t_list *stack_b)
{
	int		i;
	t_list	*tmp;
	int		best;

	tmp = stack_a;
	best = INT_MAX;
	while (tmp)
	{
		i = rrarrb(stack_a, stack_b, tmp->content, 'b');
		if (i > rarb(stack_a, stack_b, tmp->content, 'b'))
			i = rarb(stack_a, stack_b, tmp->content, 'b');
		if (i > rarrb(stack_a, stack_b, tmp->content, 'b'))
			i = rarrb(stack_a, stack_b, tmp->content, 'b');
		if (i > rrarb(stack_a, stack_b, tmp->content, 'b'))
			i = rrarb(stack_a, stack_b, tmp->content, 'b');
		if (i < best)
			best = i;
		tmp = tmp->next;
	}
	return (best);
}

int	count_b_to_a(t_list *stack_a, t_list *stack_b)
{
	int		i;
	t_list	*tmp;
	int		best;

	tmp = stack_b;
	best = INT_MAX;
	while (tmp)
	{
		i = rrarrb(stack_a, stack_b, tmp->content, 'a');
		if (i > rarb(stack_a, stack_b, tmp->content, 'a'))
			i = rarb(stack_a, stack_b, tmp->content, 'a');
		if (i > rarrb(stack_a, stack_b, tmp->content, 'a'))
			i = rarrb(stack_a, stack_b, tmp->content, 'a');
		if (i > rrarb(stack_a, stack_b, tmp->content, 'a'))
			i = rrarb(stack_a, stack_b, tmp->content, 'a');
		if (i < best)
			best = i;
		tmp = tmp->next;
	}
	return (best);
}

void	sort_a_to_b_50(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (ft_lstsize(*stack_a) > 50)
	{
		tmp = *stack_a;
		i = count_a_to_b(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == rarb(*stack_a, *stack_b, tmp->content, 'b'))
				i = apply_rarb(stack_a, stack_b, tmp->content, 'b');
			else if (i == rrarrb(*stack_a, *stack_b, tmp->content, 'b'))
				i = apply_rrarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == rarrb(*stack_a, *stack_b, tmp->content, 'b'))
				i = apply_rarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == rrarb(*stack_a, *stack_b, tmp->content, 'b'))
				i = apply_rrarb(stack_a, stack_b, tmp->content, 'b');
			else
				tmp = tmp->next;
		}
	}
}

void	sort_a_to_b(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (ft_lstsize(*stack_a) > 3)
	{
		tmp = *stack_a;
		i = count_a_to_b(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == rarb(*stack_a, *stack_b, tmp->content, 'b'))
				i = apply_rarb(stack_a, stack_b, tmp->content, 'b');
			else if (i == rrarrb(*stack_a, *stack_b, tmp->content, 'b'))
				i = apply_rrarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == rarrb(*stack_a, *stack_b, tmp->content, 'b'))
				i = apply_rarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == rrarb(*stack_a, *stack_b, tmp->content, 'b'))
				i = apply_rrarb(stack_a, stack_b, tmp->content, 'b');
			else
				tmp = tmp->next;
		}
	}
}

void	sort_b_to_a(t_list **stack_a, t_list **stack_b, int i)
{
	int		size;
	t_list	*tmp;
	int		nbr;

	size = ft_lstsize(*stack_a);
	while (*stack_b)
	{
		tmp = *stack_b;
		i = search_target(*stack_a, tmp->content, 'a');
		nbr = get_target(*stack_a, i);
		if (i > (size / 2))
		{
			while ((*stack_a)->content != nbr)
				rev_rotate_a(stack_a);
			push_a(stack_a, stack_b);
		}
		else
		{
			while ((*stack_a)->content != nbr)
				rotate_a(stack_a);
			push_a(stack_a, stack_b);
		}
		size++;
	}
}
