/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 13:42:40 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/05 21:28:14 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate_a(t_stack *stack_a)
{
	if (rotate(stack_a) == 1)
		return (1);
	else
		return (0);
}

int	rotate_b(t_stack *stack_b)
{
	if (rotate(stack_b) == 1)
		return (1);
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
			return (1);
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
		holder = stack->array[stack->top - 1];
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = holder;
		return (1);
	}
	return (0);
}
