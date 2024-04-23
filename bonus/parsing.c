/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:04:11 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/21 12:46:02 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ac_nontwo(t_list **stack_a, char **av)
{
	int		j;
	char	**tab;
	int		res;

	j = 1;
	res = 0;
	while (av[j])
	{
		tab = ft_split(av[j], ' ');
		if (tab == NULL || tab[0] == NULL)
		{
			free_tab(tab);
			print_error("Error\n");
		}
		process_tab(stack_a, tab, &res);
		free_tab(tab);
		j++;
	}
	return (res);
}

void	process_tab(t_list **stack_a, char **tab, int *res)
{
	long	nbr;
	int		i;

	i = 0;
	while (tab[i])
	{
		if ((tab[i][0] == '-' || tab[i][0] == '+') && (tab[i][1] == '\0'))
		{
			free_tab(tab);
			print_error("Error\n");
		}
		if (ft_isdigit(tab[i]) != 0)
		{
			nbr = ft_atoi(tab[i]);
			if (nbr > 2147483647 || nbr < -2147483648)
				print_error("Error\n");
			ft_lstadd_back(stack_a, ft_lstnew(nbr));
		}
		else
			print_error("Error\n");
		(*res)++;
		i++;
	}
}
