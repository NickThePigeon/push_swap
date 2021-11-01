/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:36:44 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/01 18:08:33 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int i;
	int size;

	size = stack->top - 1;
	i = 0;
	while (size > 0)
	{
		if (stack->num_stack[size] == i)
		{
			size--;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	is_empty(t_stack *stack)
{	
	if (stack->top == 0)
		return (1);
	return (0);
}

void	print_stack(t_stack *stack)
{
	int i;
	int size;
	
	size = stack->top;
	i = 0;
	while (size > 0)
	{
		printf("%d ", stack->num_stack[size - 1]);
		size--;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		init(argc, argv);
	}
	else
		return (-1);
	return (0);
}
