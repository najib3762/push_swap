/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:23:45 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/19 20:39:37 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

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
	ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	swap_two(stack_b);
	ft_printf("sb\n");
}

void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	swap_two(stack_a);
	swap_two(stack_b);
	ft_printf("ss\n");
}
