/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 18:22:31 by nduijf        #+#    #+#                 */
/*   Updated: 2021/11/01 23:06:55 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_close(error_msg message, int err)
{
	print_error(message);
	err = 0;
	exit(0);
}

void	print_error(error_msg msg)
{
	if (msg == MALLOC_FAILED)
		ft_putendl_fd("ERROR\nMalloc allocation failed", 2);
	if (msg == INTEGER_OVERFLOW)
		ft_putendl_fd("ERROR\nInteger exceeds limits", 2);
}

void	free_stack_array(t_stack *stack_a, t_stack *stack_b, t_stack *copy_a, t_stack *enum_a)
{
	if (stack_a->num_stack)
		free(stack_a->num_stack);
	if (stack_b->num_stack)
		free(stack_b->num_stack);
	if (copy_a->num_stack)
		free(copy_a->num_stack);
	if (enum_a->num_stack)
		free(enum_a->num_stack);
}