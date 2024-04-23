/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 09:22:18 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/21 12:45:08 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	size = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(1);
	if (ac >= 2)
		size = ac_nontwo(&stack_a, av);
	ft_check_double(&stack_a);
	if (!is_sorted(&stack_a))
	{
		ft_algo(&stack_a, &stack_b, size);
		free_stack(stack_a);
	}
	else if (is_sorted(&stack_a))
		free_stack(stack_a);
	return (0);
}
