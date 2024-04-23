/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:22:47 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/22 11:59:27 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

void	sort_two(t_list **stack_a)
{
	int	a;
	int	b;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	if (a > b)
		swap_a(stack_a);
}

// 2 1 3 * 3 2 1 * 3 1 2 * 1 3 2 * 2 3 1
void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a > b && b > c && a > c)
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c && a > c)
		rev_rotate_a(stack_a);
}

void	turk_algo(t_list **stack_a, t_list **stack_b)
{
	int	i;

	push_b(stack_a, stack_b);
	if (ft_lstsize(*stack_a) > 3)
		push_b(stack_a, stack_b);
	if (ft_lstsize(*stack_a) > 300)
	{
		if (ft_lstsize(*stack_a) > 50)
			sort_a_to_b_50(stack_a, stack_b);
		sort_50(stack_a, stack_b);
	}
	if (ft_lstsize(*stack_a) > 3)
		sort_a_to_b(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	sort_b_to_a(stack_a, stack_b, 0);
	i = search_index(*stack_a, get_min(*stack_a));
	if (i < ft_lstsize(*stack_a) / 2)
		while (ft_lstlast(*stack_a)->content < ft_lstfirst(*stack_a)->content)
			rotate_a(stack_a);
	else
		while (ft_lstlast(*stack_a)->content < ft_lstfirst(*stack_a)->content)
			rev_rotate_a(stack_a);
}

void	ft_algo(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		turk_algo(stack_a, stack_b);
}
