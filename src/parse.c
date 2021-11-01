/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:03:48 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/01 19:26:42 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_stack *stack)
{
	int holder;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < stack->top)
	{
		holder = stack->num_stack[i];
		while (j < stack->top)
		{
			if (holder == stack->num_stack[j] && j != i)
			{
				exit(0);/* proper exit here! */
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	get_arguments(char **args,	int argc, t_stack *stack)
{
	int len;
	int j;

	len = argc - 1;
	j = 0;
	while (len > 0)
	{
		while (args[len][j])
		{
			if (args[len][0] == '-')
				j++;
			else if (ft_isdigit(args[len][j]))
				j++;
			else
				exit(0);/* proper exit here */
		}
		j = 0;
		stack->num_stack[stack->top] = ft_atoi(args[len]);
		stack->top++;
		len--;
	}
	return (0);
}

int	check_overflow(char **argv, t_stack *stack)
{
	char *ret_itoa;
	int len;
	int i;
	
	len = stack->top - 1;
	i = 1;
	while (argv[i])
	{
		ret_itoa = ft_itoa(stack->num_stack[len]);
		if (ft_strncmp(argv[i], ret_itoa, ft_strlen(argv[i])))
		{
			printf("Overflow!");
			/* proper exit here! */
			exit(0);
		}
		if (ret_itoa)
			free(ret_itoa);
		i++;
		len--;
	}
	return (1);
}

void	init_and_sort_copy_stack(t_stack *copy_a, t_stack *stack_a)
{
	copy_a->num_stack = ft_intndup(stack_a->num_stack, stack_a->top);
	copy_a->top = stack_a->top;
	bubble_sort(copy_a->num_stack, stack_a->top);	
}

void	init(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	t_stack copy_a;
	t_stack enum_a;
	
	stack_a.top = 0;
	stack_b.top = 0;
	stack_a.num_stack = (int *)malloc((argc - 1) * sizeof(int)); 
	stack_b.num_stack = (int *)malloc((argc - 1) * sizeof(int));
	
	get_arguments(argv, argc, &stack_a);
	check_overflow(argv, &stack_a);
	check_doubles(&stack_a);
	init_and_sort_copy_stack(&copy_a, &stack_a);

	enum_a = copy_and_enum(&stack_a, &copy_a);

	sort(&enum_a, &stack_b);
	// print_stack(&enum_a);
	free(copy_a.num_stack);
	free(stack_a.num_stack);
	free(stack_b.num_stack);
	free(enum_a.num_stack);
	system("leaks push_swap");
}