/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:39:45 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/18 21:58:40 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	apply_rarb(t_list **stack_a, t_list **stack_b, int nbr, char s)
{
	if (s == 'b')
	{
		while ((*stack_a)->content != nbr && search_target(*stack_b, nbr,
				'b') > 0)
			rotate_rr(stack_a, stack_b);
		while ((*stack_a)->content != nbr)
			rotate_a(stack_a);
		while (search_target(*stack_b, nbr, 'b') > 0)
			rotate_b(stack_b);
		push_b(stack_a, stack_b);
	}
	else if (s == 'a')
	{
		while ((*stack_b)->content != nbr && search_target(*stack_a, nbr,
				'a') > 0)
			rotate_rr(stack_a, stack_b);
		while (((*stack_b)->content != nbr))
			rotate_b(stack_b);
		while (search_target(*stack_a, nbr, 'a') > 0)
			rotate_a(stack_a);
		push_a(stack_a, stack_b);
	}
	return (-1);
}

int	apply_rarrb(t_list **stack_a, t_list **stack_b, int nbr, char s)
{
	if (s == 'b')
	{
		while ((*stack_a)->content != nbr)
			rotate_a(stack_a);
		while (search_target(*stack_b, nbr, 'b') > 0)
			rev_rotate_b(stack_b);
		push_b(stack_a, stack_b);
	}
	else if (s == 'a')
	{
		while ((*stack_b)->content != nbr)
			rev_rotate_b(stack_b);
		while (search_target(*stack_a, nbr, 'a') > 0)
			rotate_a(stack_a);
		push_a(stack_a, stack_b);
	}
	return (-1);
}

int	apply_rrarb(t_list **stack_a, t_list **stack_b, int nbr, char s)
{
	if (s == 'b')
	{
		while ((*stack_a)->content != nbr)
			rev_rotate_a(stack_a);
		while (search_target(*stack_b, nbr, 'b') > 0)
			rotate_b(stack_b);
		push_b(stack_a, stack_b);
	}
	else if (s == 'a')
	{
		while ((*stack_b)->content != nbr)
			rotate_b(stack_b);
		while (search_target(*stack_a, nbr, 'a') > 0)
			rev_rotate_a(stack_a);
		push_a(stack_a, stack_b);
	}
	return (-1);
}

int	apply_rrarrb(t_list **stack_a, t_list **stack_b, int nbr, char s)
{
	if (s == 'b')
	{
		while ((*stack_a)->content != nbr && search_target(*stack_b, nbr,
				'b') > 0)
			rev_rotate_rrr(stack_a, stack_b);
		while ((*stack_a)->content != nbr)
			rev_rotate_a(stack_a);
		while (search_target(*stack_b, nbr, 'b') > 0)
			rev_rotate_b(stack_b);
		push_b(stack_a, stack_b);
	}
	else if (s == 'a')
	{
		while ((*stack_b)->content != nbr && search_target(*stack_b, nbr,
				'a') > 0)
			rev_rotate_rrr(stack_a, stack_b);
		while ((*stack_b)->content != nbr)
			rev_rotate_b(stack_b);
		while (search_target(*stack_a, nbr, 'a') > 0)
			rev_rotate_a(stack_a);
		push_a(stack_a, stack_b);
	}
	return (-1);
}
