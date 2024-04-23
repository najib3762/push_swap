/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:22:56 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/20 13:53:36 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	is_sorted(t_list **stack_a)
{
	t_list	*slow;
	t_list	*fast;

	slow = *stack_a;
	fast = slow->next;
	while (fast != NULL)
	{
		if (slow->content > fast->content)
			return (0);
		slow = slow->next;
		fast = fast->next;
	}
	return (1);
}

void	free_stack(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
}

void	ft_check_double(t_list **stack_a)
{
	t_list	*curr;
	t_list	*next;

	curr = *stack_a;
	while (curr != NULL)
	{
		next = curr->next;
		while (next != NULL)
		{
			if (curr->content == next->content)
			{
				free_stack(*stack_a);
				print_error("Error\n");
			}
			next = next->next;
		}
		curr = curr->next;
	}
}
