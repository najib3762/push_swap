/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:57:45 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/19 23:41:17 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	apply_moves(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!strncmp(line, "ss\n", 3))
		swap_ab(stack_a, stack_b);
	else if (!strncmp(line, "sa\n", 3))
		swap_a(stack_a);
	else if (!strncmp(line, "sb\n", 3))
		swap_b(stack_b);
	else if (!strncmp(line, "pa\n", 3))
		push_a(stack_a, stack_b);
	else if (!strncmp(line, "pb\n", 3))
		push_b(stack_a, stack_b);
	else if (!strncmp(line, "rb\n", 3))
		rotate_b(stack_b);
	else if (!strncmp(line, "ra\n", 3))
		rotate_a(stack_a);
	else if (!strncmp(line, "rr\n", 3))
		rotate_rr(stack_a, stack_b);
	else if (!strncmp(line, "rra\n", 4))
		rev_rotate_a(stack_a);
	else if (!strncmp(line, "rrb\n", 4))
		rev_rotate_b(stack_b);
	else if (!strncmp(line, "rrr\n", 4))
		rev_rotate_rrr(stack_a, stack_b);
}

int	check_line_my(char *str)
{
	if (!strncmp(str, "ss\n", 3) || !strncmp(str, "sa\n", 3) || !strncmp(str,
			"sb\n", 3) || !strncmp(str, "rr\n", 3) || !strncmp(str, "ra\n", 3)
		|| !strncmp(str, "rb\n", 3) || !strncmp(str, "rrr\n", 4)
		|| !strncmp(str, "rra\n", 4) || !strncmp(str, "rrb\n", 4)
		|| !strncmp(str, "pa\n", 3) || !strncmp(str, "pb\n", 3))
		return (1);
	return (0);
}

void	ft_moves(t_list **stack_a, t_list **stack_b)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!check_line_my(line))
		{
			free(line);
			free_stack(*stack_a);
			free_stack(*stack_b);
			print_error("Error\n");
		}
		apply_moves(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(1);
	if (ac >= 2)
		ac_nontwo(&stack_a, av);
	ft_check_double(&stack_a);
	ft_moves(&stack_a, &stack_b);
	if (is_sorted(&stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack_a);
	return (0);
}
