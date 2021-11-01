/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:05:10 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/02 00:34:31 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_stack *stack_a)
{
	if (rotate(stack_a) == 1)
	{
		write(1, "ra\n", 3);
		return (1);
	}
	else
		return (0);
}

int	rotate_b(t_stack *stack_b)
{
	if (rotate(stack_b) == 1)
	{
		write(1, "rb\n", 3);
		return (1);
	}
	else
		return (0);
}

int	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	err;

	err = 0;
	if (stack_a->top > 1 && stack_b->top > 1)
	{
		err += rotate(stack_a);
		err += rotate(stack_b);
		if (err == 2)
		{
			write(1, "rr\n", 3);
			return (1);
		}
	}
	return (0);
}

int	rotate(t_stack *stack)
{
	int	holder;
	int	i;

	if (stack->top > 1)
	{
		i = stack->top - 1;
		holder = stack->num_stack[stack->top - 1];
		while (i > 0)
		{
			stack->num_stack[i] = stack->num_stack[i - 1];
			i--;
		}
		stack->num_stack[0] = holder;
		return (1);
	}
	return (0);
}
