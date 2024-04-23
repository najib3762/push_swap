/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:36:48 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/22 11:59:54 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	print_error(char *str);
int		get_target(t_list *stack, int index);
// int		ac_two(t_list **stack_a, char **av);
// void	sort_2(t_list **stack_a, t_list **stack_b);
void	sort_a_to_b_50(t_list **stack_a, t_list **stack_b);
void	turk_algo(t_list **stack_a, t_list **stack_b);
int		count_a_to_b(t_list *stack_a, t_list *stack_b);
void	process_tab(t_list **stack_a, char **tab, int *res);
void	sort_50(t_list **stack_a, t_list **stack_b);
int		ac_nontwo(t_list **stack_a, char **av);
void	ft_check_double(t_list **stack_a);
int		is_sorted(t_list **stack_a);
void	free_stack(t_list *stack_a);
void	ft_algo(t_list **stack_a, t_list **stack_b, int size);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ab(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_b(t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_rr(t_list **stack_a, t_list **stack_b);
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rev_rotate_rrr(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstlast(t_list *lst);
int		rarb(t_list *stack_a, t_list *stack_b, int nbr, char s);
int		rarrb(t_list *stack_a, t_list *stack_b, int nbr, char s);
int		rrarrb(t_list *stack_a, t_list *stack_b, int nbr, char s);
int		rrarb(t_list *stack_a, t_list *stack_b, int nbr, char s);
void	ft_algo(t_list **stack_a, t_list **stack_b, int size);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
int		get_max(t_list *stack);
int		get_min(t_list *stack);
t_list	*ft_lstlast(t_list *lst);
void	print_error(char *str);
void	sort_a_to_b(t_list **stack_a, t_list **stack_b);
void	sort_b_to_a(t_list **stack_a, t_list **stack_b, int i);
t_list	*ft_lstfirst(t_list *lst);
int		search_target(t_list *stack, int nbr, char s);
int		search_index(t_list *stack, int number);
int		apply_rarb(t_list **stack_a, t_list **stack_b, int nbr, char s);
int		apply_rarrb(t_list **stack_a, t_list **stack_b, int nbr, char s);
int		apply_rrarb(t_list **stack_a, t_list **stack_b, int nbr, char s);
int		apply_rrarrb(t_list **stack_a, t_list **stack_b, int nbr, char s);

//**********ft_printf*********************//
int		putcharr(int c);
int		putstrr(char *str);
int		ft_addresss(unsigned long n);
int		ft_printf(const char *str, ...);
int		ft_putnbr_base(long nbr, int base, unsigned char is_upper);
#endif
