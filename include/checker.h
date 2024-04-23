/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:07:04 by namoussa          #+#    #+#             */
/*   Updated: 2024/04/19 23:33:39 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "header.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

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

int		ac_nontwo(t_list **stack_a, char **av);
void	print_error(char *str);
int		ac_nontwo(t_list **stack_a, char **av);
void	ft_check_double(t_list **stack_a);
int		is_sorted(t_list **stack_a);
void	free_stack(t_list *stack_a);
void	apply_moves(t_list **stack_a, t_list **stack_b, char *line);
int		check_line(char *str);
void	ft_moves(t_list **stack_a, t_list **stack_b);
void	ft_check_double(t_list **stack_a);

/****************get_next_line************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_strdup_my(char *str, int len);
char	*ft_strjoin_my(char *s1, char *s2);
int		check_line(char *temp);
char	*print_line(char **temp);
char	*get_next_line(int fd);
size_t	ft_strlen_my(char *s);
#endif
