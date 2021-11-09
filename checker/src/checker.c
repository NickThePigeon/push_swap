/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 10:15:09 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/05 21:28:53 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 0)
		ft_close(NO_ARGUMENTS, 1);
	stack_a->top = 0;
	stack_b->top = 0;
	stack_a->array = (int *)malloc(sizeof(int) * len);
	if (!stack_a->array)
		ft_close(MALLOC_FAILED, 1);
	stack_b->array = (int *)malloc(sizeof(int) * len);
	if (!stack_b->array)
	{
		free(stack_a->array);
		ft_close(MALLOC_FAILED, 1);
	}
}

void	free_both_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
}

void	check_and_get(t_stack *stack_a, t_stack *stack_b, char **argv, int argc)
{
	if (get_arguments(argv, argc, stack_a) == 0)
	{
		free_both_stacks(stack_a, stack_b);
		ft_close(STACK_ALLOCATION_FAIL, 2);
	}
	if (check_doubles(stack_a) == 0)
	{
		ft_close(DOUBLE_INTEGER, 3);
	}
	if (check_overflow(argv, stack_a) == 0)
	{
		free_both_stacks(stack_a, stack_b);
		ft_close(INTEGER_OVERFLOW, 4);
	}
}	

int	check_operations(t_stack *stack_a, t_stack *stack_b, char *input)
{
	if (!ft_strncmp("sa\n", input, 3))
		swap_a(stack_a);
	else if (!ft_strncmp("sb\n", input, 3))
		swap_b(stack_b);
	else if (!ft_strncmp("ss\n", input, 3))
		swap_ss(stack_a, stack_b);
	else if (!ft_strncmp("pa\n", input, 3))
		push_to_a(stack_a, stack_b);
	else if (!ft_strncmp("pb\n", input, 3))
		push_to_b(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", input, 3))
		rotate_a(stack_a);
	else if (!ft_strncmp("rb\n", input, 3))
		rotate_b(stack_b);
	else if (!ft_strncmp("rr\n", input, 3))
		rotate_rr(stack_a, stack_b);
	else if (!ft_strncmp("rra\n", input, 4))
		r_rotate_a(stack_a);
	else if (!ft_strncmp("rrb\n", input, 4))
		r_rotate_b(stack_b);
	else if (!ft_strncmp("rrr\n", input, 4))
		r_rotate_rr(stack_a, stack_b);
	else
		return (0);
	return (1);
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

void	print_stack(t_stack *stack)
{
	int	i;
	int	size;

	size = stack->top;
	i = 0;
	while (size > 0)
	{
		printf("%d ", stack->array[size - 1]);
		size--;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*line;
	int		error;

	init_stack(&stack_a, &stack_b, (argc - 1));
	check_and_get(&stack_a, &stack_b, argv, argc);
	error = 1;
	while (get_next_line(0, &line) && error > 0)
	{
		error = check_operations(&stack_a, &stack_b, line);
		free(line);
	}
	if (error == 0)
	{
		free_both_stacks(&stack_a, &stack_b);
		ft_close(UNKOWN_EXCUTION_INPUT, 5);
	}
	error = is_sorted(&stack_a, &stack_b);
	free_both_stacks(&stack_a, &stack_b);
	if (error == 0)
		ft_close(KO, 6);
	ft_close(SUCCES, 99);
	return (0);
}
