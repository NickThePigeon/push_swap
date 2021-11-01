/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:09:39 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/31 18:10:52 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack *stack_a)
{
	if (swap(stack_a) == 1)
	{
		write(1, "sa\n", 3);
		return (1);
	}
	else
		return (0);
}

int	swap_b(t_stack *stack_b)
{
	if (swap(stack_b) == 1)
	{
		write(1, "sb\n", 3);
		return (1);
	}
	else
		return (0);
}

int	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	int err;

	err = 0;
	err += swap(stack_a);
	err += swap(stack_b);
	if (err == 2)
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}

int	swap(t_stack *stack)
{
	int holder;
	
	if (stack->top > 0)
	{
		holder = stack->num_stack[stack->top - 1];
		stack->num_stack[stack->top - 1] = stack->num_stack[stack->top - 2];
		stack->num_stack[stack->top - 2] = holder;
		return (1);
	}
	return (0);
}
