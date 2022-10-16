/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 12:38:39 by nduijf        #+#    #+#                 */
/*   Updated: 2021/11/09 12:39:26 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	if (small_sorted(stack_a))
		return ;
	if (stack_a->num_stack[stack_a->top - 2]
		< stack_a->num_stack[stack_a->top - 3]
		&& stack_a->num_stack[stack_a->top - 3]
		> stack_a->num_stack[stack_a->top - 1])
		swap_a(stack_a);
	else if (stack_a->num_stack[stack_a->top - 2]
		< stack_a->num_stack[stack_a->top - 1]
		&& stack_a->num_stack[stack_a->top - 2]
		> stack_a->num_stack[stack_a->top - 3])
	{
		swap_a(stack_a);
		r_rotate_a(stack_a);
	}
	else if (stack_a->num_stack[stack_a->top - 2]
		< stack_a->num_stack[stack_a->top - 1]
		&& stack_a->num_stack[stack_a->top - 3]
		< stack_a->num_stack[stack_a->top - 1])
		rotate_a(stack_a);
	else
		sort_three_point_two(stack_a);
}

void	sort_three_point_two(t_stack *stack_a)
{
	if (stack_a->num_stack[stack_a->top - 2]
		> stack_a->num_stack[stack_a->top - 3]
		&& stack_a->num_stack[stack_a->top - 3]
		> stack_a->num_stack[stack_a->top - 1])
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (stack_a->num_stack[stack_a->top - 2]
		> stack_a->num_stack[stack_a->top - 3]
		&& stack_a->num_stack[stack_a->top - 1]
		> stack_a->num_stack[stack_a->top - 3])
		r_rotate_a(stack_a);
}

void	sort_last_two(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (stack_b->num_stack[stack_b->top - 1] > stack_a->num_stack[0])
		{
			push_to_a(stack_a, stack_b);
			rotate_a(stack_a);
		}
		else if (stack_b->num_stack[stack_b->top - 1]
			> stack_a->num_stack[stack_a->top - 1]
			&& stack_b->num_stack[stack_b->top - 1]
			< stack_a->num_stack[stack_a->top - 2])
		{
			push_to_a(stack_a, stack_b);
			swap_a(stack_a);
		}
		else
			sort_last_two_point_two(stack_a, stack_b);
		i++;
	}
}

void	sort_last_two_point_two(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->num_stack[stack_b->top - 1]
		< stack_a->num_stack[stack_a->top - 1])
		push_to_a(stack_a, stack_b);
	else if (stack_b->num_stack[stack_b->top - 1] < stack_a->num_stack[0]
		&& stack_b->num_stack[stack_b->top - 1] > stack_a->num_stack[1])
	{
		r_rotate_a(stack_a);
		push_to_a(stack_a, stack_b);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (stack_b->num_stack[stack_b->top - 1]
		> stack_a->num_stack[stack_a->top - 2]
		&& stack_b->num_stack[stack_b->top - 1]
		< stack_a->num_stack[stack_a->top - 3])
	{
		rotate_a(stack_a);
		push_to_a(stack_a, stack_b);
		swap_a(stack_a);
		r_rotate_a(stack_a);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_to_b(stack_a, stack_b);
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	sort_last_two(stack_a, stack_b);
}
