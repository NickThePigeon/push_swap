/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 13:13:01 by nduijf        #+#    #+#                 */
/*   Updated: 2022/10/16 17:11:51 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack *stack)
{
	int	size;

	size = stack->top;
	while (size > 0)
	{
		printf("%d ", stack->array[size - 1]);
		size--;
	}
	printf("\n");
}

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	holder;
	int	len;

	if (stack_b->top != 0)
		return (0);
	len = stack_a->top - 1;
	holder = stack_a->array[len];
	len--;
	while (len >= 0)
	{
		if (stack_a->array[len] > holder)
		{
			holder = stack_a->array[len];
			len--;
		}
		else
			return (0);
	}
	return (1);
}
