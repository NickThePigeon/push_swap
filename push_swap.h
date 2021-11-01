/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:37:00 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/01 19:18:04 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include "error.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef	struct	s_stack
{
	int	*num_stack;
	int top;
}	t_stack;

int	swap_a(t_stack *stack_a);
int	swap_b(t_stack *stack_b);
int	swap_ss(t_stack *stack_a, t_stack *stack_b);
int	swap(t_stack *stack);

int	push_to_a(t_stack *stack_a, t_stack *stack_b);
int	push_to_b(t_stack *stack_a, t_stack *stack_b);
int	push(t_stack *stack_from, t_stack *stack_to);

int	rotate_a(t_stack *stack_a);
int	rotate_b(t_stack *stack_b);
int rotate_rr(t_stack *stack_a, t_stack *stack_b);
int	rotate(t_stack *stack);

int	r_rotate_a(t_stack *stack_a);
int	r_rotate_b(t_stack *stack_b);
int r_rotate_rr(t_stack *stack_a, t_stack *stack_b);
int	r_rotate(t_stack *stack);

int	check_doubles(t_stack *stack);
int	get_arguments(char **args, int argc, t_stack *stack);
int	is_empty(t_stack *stack);
int	is_sorted(t_stack *stack);
void	print_stack(t_stack *stack);
void	init(int argc, char **argv);
t_stack		copy_and_enum(t_stack *stack_a, t_stack *sorted_a);

void	bubble_sort(int *arr, int n);
void	swap_point(int *xp, int *yp);
void	sort(t_stack *stack_a, t_stack *stack_b);
int		get_place_most_significant_set_bit(int x);

#endif