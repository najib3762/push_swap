/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:24:04 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/19 23:00:17 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

void	rotate_ab(t_list **stack)
{
	t_list	*temp;
	t_list	*curr;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	*stack = curr;
	(*stack)->next = temp;
	(*stack) = (*stack)->next->next;
	temp->next = NULL;
}

void	rotate_a(t_list **stack_a)
{
	rotate_ab(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	rotate_ab(stack_b);
	ft_printf("rb\n");
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_ab(stack_b);
	rotate_ab(stack_a);
	ft_printf("rr\n");
}
