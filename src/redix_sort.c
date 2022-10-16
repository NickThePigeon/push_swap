/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:01:54 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/09 12:40:13 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_redix(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	num;
	int	i;
	int	j;

	i = 0;
	size = stack_a->top;
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j < size)
		{
			num = stack_a->num_stack[stack_a->top - 1];
			if (((num >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_to_b(stack_a, stack_b);
			j++;
		}
		while (!is_empty(stack_b))
			push_to_a(stack_a, stack_b);
		i++;
	}
}

t_stack	copy_and_enum(t_stack *stack_a, t_stack *sorted_a, t_all *all)
{
	t_stack	enum_a;
	int		i;
	int		j;

	enum_a.num_stack = (int *)malloc(sizeof(int) * stack_a->top);
	if (!enum_a.num_stack)
		ft_close(MALLOC_FAILED, 7, all);
	enum_a.top = stack_a->top;
	i = 0;
	while (i < stack_a->top)
	{
		j = 0;
		while (j < stack_a->top)
		{
			if (sorted_a->num_stack[i] == stack_a->num_stack[j])
			{
				enum_a.num_stack[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	return (enum_a);
}
