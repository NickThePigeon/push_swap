/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:03:48 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/04 17:07:01 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b, int len, t_all *all)
{
	stack_a->top = 0;
	stack_b->top = 0;
	stack_a->num_stack = (int *)malloc((len) * sizeof(int));
	if (!stack_a->num_stack)
		ft_close(MALLOC_FAILED, 3, all);
	stack_b->num_stack = (int *)malloc((len) * sizeof(int));
	if (!stack_b->num_stack)
	{
		free(stack_a->num_stack);
		ft_close(MALLOC_FAILED, 3, all);
	}
}

void	init_and_sort_copy_stack(t_stack *copy_a, t_stack *stack_a, t_all *all)
{
	copy_a->num_stack = ft_intndup(stack_a->num_stack, stack_a->top);
	if (!copy_a->num_stack)
		ft_close(MALLOC_FAILED, 6, all);
	copy_a->top = stack_a->top;
	bubble_sort(copy_a->num_stack, stack_a->top);
}

void	pre_sort(t_all *all)
{
	if (all->enum_a.top == 3)
		sort_three(&all->enum_a);
	else if (all->enum_a.top == 5)
		sort_five(&all->enum_a, &all->stack_b);
	else
		sort_redix(&all->enum_a, &all->stack_b);
}

void	initialize(int argc, char **argv)
{
	t_all	all;

	init_stacks(&all.stack_a, &all.stack_b, (argc - 1), &all);
	if (get_arguments(argv, argc, &all.stack_a) == 0)
		ft_close(STACK_ALLOCATION_FAIL, 3, &all);
	if (check_overflow(argv, &all.stack_a) == 0)
		ft_close(INTEGER_OVERFLOW, 4, &all);
	if (check_doubles(&all.stack_a) == 0)
		ft_close(DOUBLE_INTEGER, 5, &all);
	init_and_sort_copy_stack(&all.copy_a, &all.stack_a, &all);
	all.enum_a = copy_and_enum(&all.stack_a, &all.copy_a, &all);
	if (is_sorted(&all.enum_a))
		ft_close(SUCCES, 99, &all);
	pre_sort(&all);
	ft_close(SUCCES, 99, &all);
}
