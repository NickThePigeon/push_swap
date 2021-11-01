/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   r_rotate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:05:01 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/01 09:02:01 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_rotate_a(t_stack *stack_a)
{
	if (r_rotate(stack_a) == 1)
	{
		write(1, "rra\n", 4);
		return (1);
	}
	else
		return (0);
}

int	r_rotate_b(t_stack *stack_b)
{
	if (r_rotate(stack_b) == 1)
	{
		write(1, "rrb\n", 4);
		return (1);
	}
	else
		return (0);
}

int r_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	int err;

	err = 0;
	if (stack_a->top > 1 && stack_b->top > 1)
	{
		err += r_rotate(stack_a);
		err += r_rotate(stack_b);
		if (err == 2)
		{
			write(1, "rrr\n", 4);
			return (1);
		}
	}
	return (0);
}

int	r_rotate(t_stack *stack)
{
	int	holder;
	int i;

	i = 0;
	if (stack->top > 1)
	{
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
