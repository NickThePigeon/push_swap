/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 10:15:28 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/02 22:52:06 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include "../libft/libft.h"
#include <stdio.h>
#include "error.h"

typedef struct	s_stack
{
	int *array;
	int top;
}	t_stack;

/* Operations */
int	push_to_a(t_stack *stack_a, t_stack *stack_b);
int	push_to_b(t_stack *stack_a, t_stack *stack_b);
int	push(t_stack *stack_from, t_stack *stack_to);

int	swap_a(t_stack *stack_a);
int	swap_b(t_stack *stack_b);
int	swap_ss(t_stack *stack_a, t_stack *stack_b);
int	swap(t_stack *stack);

int	rotate_a(t_stack *stack_a);
int	rotate_b(t_stack *stack_b);
int	rotate_rr(t_stack *stack_a, t_stack *stack_b);
int	rotate(t_stack *stack);

int	r_rotate_a(t_stack *stack_a);
int	r_rotate_b(t_stack *stack_b);
int	r_rotate_rr(t_stack *stack_a, t_stack *stack_b);
int	r_rotate(t_stack *stack);

/* getting and checking functions */
void	check_and_get(t_stack *stack_a, t_stack *stack_b, char **argv, int argc);
int	check_doubles(t_stack *stack);
int	get_arguments(char **args,	int argc, t_stack *stack);
int	check_overflow(char **argv, t_stack *stack);
int	check_operations(t_stack *stack_a, t_stack *stack_b, char *input);

/* exit functions */
void	ft_close(error_msg message, int err);
void	print_error(error_msg message);
int		get_next_line(int fd, char **line);

#endif