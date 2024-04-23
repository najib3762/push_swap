/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:23:45 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/19 20:40:38 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	swap_two(t_list **stack)
{
	t_list	*temp;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
	}
}

void	swap_a(t_list **stack_a)
{
	swap_two(stack_a);
}

void	swap_b(t_list **stack_b)
{
	swap_two(stack_b);
}

void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	swap_two(stack_a);
	swap_two(stack_b);
}
