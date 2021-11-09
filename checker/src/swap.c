/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 13:43:48 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/05 21:28:39 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap_a(t_stack *stack_a)
{
	if (swap(stack_a) == 1)
		return (1);
	else
		return (0);
}

int	swap_b(t_stack *stack_b)
{
	if (swap(stack_b) == 1)
		return (1);
	else
		return (0);
}

int	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	int	err;

	err = 0;
	err += swap(stack_a);
	err += swap(stack_b);
	if (err == 2)
		return (1);
	else
		return (0);
}

int	swap(t_stack *stack)
{
	int	holder;

	if (stack->top > 0)
	{
		holder = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = stack->array[stack->top - 2];
		stack->array[stack->top - 2] = holder;
		return (1);
	}
	return (0);
}
