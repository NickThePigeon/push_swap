/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:36:44 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/01 09:07:29 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	int i;

	i = 0;
	while (i < stack_a->top)
	{
		if (stack_a->num_stack[i] == i)
			i++;
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
	i = 0;
	while (i < stack->top)
	{
		printf("%d ", stack->num_stack[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	t_stack copy_a;
	t_stack enum_a;
	
	stack_a.top = 0;
	stack_b.top = 0;
	
	stack_a.num_stack = (int *)malloc((argc) * sizeof(int)); 
	stack_b.num_stack = (int *)malloc((argc) * sizeof(int));

	if (argc > 1)
	{
		get_arguments(argv, &stack_a);
		check_doubles(&stack_a);
		copy_a.num_stack = ft_intndup(stack_a.num_stack, stack_a.top);
		copy_a.top = stack_a.top;
		// print_stack(&copy_a);
		bubble_sort(copy_a.num_stack, stack_a.top);
		enum_a = copy_and_enum(&stack_a, &copy_a);
		// printf("\n");
		sort(&enum_a, &stack_b);
		// r_rotate_a(&copy_a);
		// print_stack(&enum_a);
		free(stack_a.num_stack);
		free(stack_b.num_stack);
		free(copy_a.num_stack);
		free(enum_a.num_stack);
	}
	else
		return (-1);
	return (0);
}
