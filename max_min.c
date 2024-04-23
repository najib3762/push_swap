/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:22:38 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/22 10:14:22 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	get_max(t_list *stack)
{
	t_list	*curr;
	int		max;

	curr = stack;
	max = curr->content;
	while (curr)
	{
		if (curr->content > max)
			max = curr->content;
		curr = curr->next;
	}
	return (max);
}

int	get_min(t_list *stack)
{
	t_list	*curr;
	int		min;

	curr = stack;
	min = curr->content;
	while (curr)
	{
		if (curr->content < min)
			min = curr->content;
		curr = curr->next;
	}
	return (min);
}

int	get_target(t_list *stack, int index)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = stack;
	while (curr)
	{
		if (i == index)
			return (curr->content);
		i++;
		curr = curr->next;
	}
	return (0);
}
