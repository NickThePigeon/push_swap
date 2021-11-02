/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   r_rotate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 13:41:02 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/02 23:15:23 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	r_rotate_a(t_stack *stack_a)
{
	if (r_rotate(stack_a) == 1)
		return (1);
	else
		return (0);
}

int	r_rotate_b(t_stack *stack_b)
{
	if (r_rotate(stack_b) == 1)
		return (1);
	else
		return (0);
}

int	r_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	err;

	err = 0;
	if (stack_a->top > 1 && stack_b->top > 1)
	{
		err += r_rotate(stack_a);
		err += r_rotate(stack_b);
		if (err == 2)
			return (1);
	}
	return (0);
}

int	r_rotate(t_stack *stack)
{
	int	holder;
	int	i;

	if (stack->top > 1)
	{
		i = 0;
		holder = stack->array[0];
		while (i < stack->top - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->top - 1] = holder;
		return (1);
	}
	return (0);
}