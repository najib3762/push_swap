/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:23:55 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/17 20:32:42 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

void	push_two(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp;

	if (*stack_2)
	{
		temp = *stack_2;
		(*stack_2) = (*stack_2)->next;
		temp->next = (*stack_1);
		(*stack_1) = temp;
	}
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push_two(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push_two(stack_b, stack_a);
	ft_printf("pb\n");
}
