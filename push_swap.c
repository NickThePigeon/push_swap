/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:36:44 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/07 20:45:40 by nicky         ########   odam.nl         */
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
				write(1, "dubbel\n", 7);
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	write(1, "gelukt\n", 7);
	return (0);
}

int	swap(t_stack *stack)
{
	int holder;
	
	if (stack->top > 1)
	{
		holder = stack->num_stack[stack->top];
		stack->num_stack[stack->top] = stack->num_stack[stack->top - 1];
		stack->num_stack[stack->top - 1] = holder;
		return (1);
	}
	return (0);
}

int	swap_a(t_stack *stack_a)
{
	if (swap(stack_a) == 1)
	{
		write(1, "sa\n", 3);
		return (1);
	}
	else
		return (0);
}

int	swap_b(t_stack *stack_b)
{
	if (swap(stack_b) == 1)
	{
		write(1, "sb\n", 3);
		return (1);
	}
	else
		return (0);
}

int	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	int err;

	err = 0;
	err += swap(stack_a);
	err += swap(stack_b);
	if (err == 2)
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}

int	push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->top >= 0)
	{
		stack_to->top++;
		stack_to->num_stack[stack_to->top] = stack_from->num_stack[stack_from->top];
		stack_from->top--;
		return (1);
	}
	return (0);
}

int	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_a, stack_b) == 1)
	{
		write(1, "pa\n", 3);
		return (1);
	}
	else
		return (0);
}

int	push_b(t_stack *stack_b, t_stack *stack_a)
{
	if (push(stack_b, stack_a) == 1)
	{
		write(1, "pb\n", 3);
		return (1);
	}
	else
		return (0);
}

int	r_rotate(t_stack *stack)
{
	int	holder;
	int i;

	i = stack->top;
	if (stack->top > 0)
	{
		holder = stack->num_stack[stack->top];
		while (i > 0)
		{
			stack->num_stack[i] = stack->num_stack[i - 1];
			i--;
		}
		stack->num_stack[0] = holder;
		return (1);
	}
	return (0);
}

int r_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	int err;

	err = 0;
	if (stack_a->top > 0 && stack_b->top > 0)
	{
		err += r_rotate(stack_a);
		err += r_rotate(stack_b);
		if (err == 2)
		{
			write(1, "rrr\n", 4);
			return (1);
		}
	}
	return (0);
}

int	r_rotate_a(t_stack *stack_a)
{
	if (r_rotate(stack_a) == 1)
	{
		write(1, "rra\n", 4);
		return (1);
	}
	else
		return (0);
}

int	r_rotate_b(t_stack *stack_b)
{
	if (r_rotate(stack_b) == 1)
	{
		write(1, "ra\n", 3);
		return (1);
	}
	else
		return (0);
}

int	rotate(t_stack *stack)
{
	int	holder;
	int i;

	i = 1;
	if (stack->top > 0)
	{
		holder = stack->num_stack[0];
		while (i <= stack->top)
		{
			stack->num_stack[i - 1] = stack->num_stack[i];
			i++;
		}
		stack->num_stack[stack->top] = holder;
		return (1);
	}
	return (0);
}

int	rotate_a(t_stack *stack_a)
{
	if (rotate(stack_a) == 1)
	{
		write(1, "ra\n", 3);
		return (1);
	}
	else
		return (0);
}

int	rotate_b(t_stack *stack_b)
{
	if (rotate(stack_b) == 1)
	{
		write(1, "rb\n", 3);
		return (1);
	}
	else
		return (0);
}

int rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	int err;

	err = 0;
	if (stack_a->top > 0 && stack_b->top > 0)
	{
		err += rotate(stack_a);
		err += rotate(stack_b);
		if (err == 2)
		{
			write(1, "rr\n", 3);
			return (1);
		}
	}
	return (0);
}

int	get_arguments(char **args, t_stack *stack)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (args[i])
	{
		stack->top++;
		while (args[i][j])
		{
			if (args[i][0] == '-')
				j++;
			else if (ft_isdigit(args[i][j]))
				j++;
			else
				exit(0);
		}
		j = 0;
		stack->num_stack[stack->top] = ft_atoi(args[i]);
		// if (!stack->num_stack[stack->top])
		// 	exit(0);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack_a)
{
	int i;
	int holder;

	i = 0;
	holder = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->num_stack[i] > holder)
		{
			holder = stack_a->num_stack[i];
			i++;
		}
		else
			return (0);
	}
	return (1);
}

// int	sort(t_stack *stack_a, t_stack *stack_b)
// {	
// 	if (stack_b->top < 2)
// 	{
// 		push(stack_a, stack_b);
// 		push(stack_a, stack_b);
// 	}
// 	while (!is_sorted(stack_a))
// 	{	
// 		if (stack_b->num_stack[stack_b->top])
// 	}
// }

int	sort(t_stack *stack_a, t_stack *stack_b)
{
	
}

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	
	stack_a.top = -1;
	stack_b.top = -1;
	if (argc > 1)
	{
		get_arguments(argv, &stack_a);
		check_doubles(&stack_a);
		for (int i = 0; i <= stack_a.top; i++)
		{
			printf("%d\n", stack_a.num_stack[i]);
		}
		printf("\n");
		// for (int i = 0; i <= stack_b.top; i++)
		// {
		// 	printf("%d\n", stack_b.num_stack[i]);
		// }
	}
	else
		return (-1);
	return (0);
}