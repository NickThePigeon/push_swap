/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:03:48 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/01 23:25:09 by nicky         ########   odam.nl         */
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
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
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
				return (0);
		}
		j = 0;
		stack->num_stack[stack->top] = ft_atoi(args[len]);
		stack->top++;
		len--;
	}
	return (0);
}

void	init_stacks(t_stack *stack_a, t_stack *stack_b, int len)
{
	stack_a->top = 0;
	stack_b->top = 0;
	stack_a->num_stack = (int *)malloc((len) * sizeof(int));
	if (!stack_a->num_stack)
		ft_close(MALLOC_FAILED, 3);
	stack_b->num_stack = (int *)malloc((len) * sizeof(int));
	if (!stack_b->num_stack)
	{
		free(stack_a->num_stack);
		ft_close(MALLOC_FAILED, 3);
	}
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
			return (0);
		if (ret_itoa)
			free(ret_itoa);
		i++;
		len--;
	}
	return (1);
}

int	init_and_sort_copy_stack(t_stack *copy_a, t_stack *stack_a)
{
	copy_a->num_stack = ft_intndup(stack_a->num_stack, stack_a->top);
	if (!copy_a->num_stack)
		return (0);
	copy_a->top = stack_a->top;
	bubble_sort(copy_a->num_stack, stack_a->top);
	return (1);
}

void	initialize_two(t_stack *stack_a, t_stack *stack_b, t_stack *copy_a, t_stack *enum_a)
{
	if (init_and_sort_copy_stack(copy_a, stack_a) == 0)
	{
		free_stack_array(stack_a, stack_b, copy_a, enum_a);
		ft_close(MALLOC_FAILED, 6);
	}
	enum_a = copy_and_enum(stack_a, copy_a);
	if (!enum_a)
	{
		free_stack_array(stack_a, stack_b, copy_a, enum_a);
		ft_close(MALLOC_FAILED, 7);
	}
}

void	initialize(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	t_stack copy_a;
	t_stack enum_a;

	init_stacks(&stack_a, &stack_b, (argc - 1));
	if (get_arguments(argv, argc, &stack_a) == 0)
	{
		free_stack_array(&stack_a, &stack_b, &copy_a, &enum_a);
		ft_close(STACK_ALLOCATION_FAIL, 3);
	}
	if (check_overflow(argv, &stack_a) == 0)
	{
		free_stack_array(&stack_a, &stack_b, &copy_a, &enum_a);
		ft_close(INTEGER_OVERFLOW, 4);
	}
	if (check_doubles(&stack_a) == 0)
	{
		free_stack_array(&stack_a, &stack_b, &copy_a, &enum_a);
		ft_close(DOUBLE_INTEGER, 5);
	}
	initialize_two(&stack_a, &stack_b, &copy_a, &enum_a);

	sort(&enum_a, &stack_b);
	// print_stack(&enum_a);
	free_stack_array(&stack_a, &stack_b, &copy_a, &enum_a);
}
