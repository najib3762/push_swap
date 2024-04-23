/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:24:13 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/19 22:02:22 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	rev_rotate_ab(t_list **stack)
{
	t_list	*curr;
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	curr = *stack;
	while (curr->next->next != NULL)
		curr = curr->next;
	temp = curr->next;
	temp->next = *stack;
	*stack = temp;
	curr->next = NULL;
}

void	rev_rotate_a(t_list **stack_a)
{
	rev_rotate_ab(stack_a);
}

void	rev_rotate_b(t_list **stack_b)
{
	rev_rotate_ab(stack_b);
}

void	rev_rotate_rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_ab(stack_b);
	rev_rotate_ab(stack_a);
}
