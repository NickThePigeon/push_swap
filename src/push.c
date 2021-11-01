/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:09:51 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/01 15:54:23 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_b, stack_a) == 1)
	{
		write(1, "pa\n", 3);
		return (1);
	}
	else
		return (0);
}

int	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_a, stack_b) == 1)
	{
		write(1, "pb\n", 3);
		return (1);
	}
	else
		return (0);
}

int	push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->top > 0)
	{
		stack_to->top++;
		stack_to->num_stack[stack_to->top - 1] = stack_from->num_stack[stack_from->top - 1];
		stack_from->top--;
		return (1);
	}
	return (0);
}
