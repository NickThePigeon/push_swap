/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:36:44 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/22 12:44:04 by nduijf        ########   odam.nl         */
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
				// write(1, "dubbel\n", 7);
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
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

int	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_b, stack_a) == 1)
	{
		write(1, "pa\n", 3);
		return (1);
	}
	else
		return (0);
}

int	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_a, stack_b) == 1)
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
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack_a)
{
	int i;
	int holder;

	holder = -1;
	i = 0;
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
	printf("sorted\n");
	return (1);
}

int	is_empty(t_stack *stack)
{	
	if (stack->top == -1)
		return (1);
	return (0);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int size;
	int num;
	int i;
	int j;
	
	i = 0;
	size = stack_a->top;
	while (i <= size)
	{
		j = 0;
    	while(j <= size)
    	{
        	num = stack_a->num_stack[stack_a->top];
        	if (((num >> i)&1) == 0)
				r_rotate_a(stack_a);
        	else
				push_to_b(stack_a, stack_b);
			j++;
    	}
    	while (!is_empty(stack_b))
			push_to_a(stack_a, stack_b);
		i++;
	}
}

t_stack		copy_stack(t_stack *stack_a)
{
	
}

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	t_stack copy_a;
	
	stack_a.top = -1;
	stack_b.top = -1;
	copy_a.top = -1;
	
	stack_a.num_stack = (int *)malloc((argc - 1) * sizeof(int)); 
	stack_b.num_stack = (int *)malloc((argc - 1) * sizeof(int));
	copy_a.num_stack = (int *)malloc((argc - 1) * sizeof(int));

	if (argc > 1)
	{
		get_arguments(argv, &stack_a);
		check_doubles(&stack_a);
		sort(&stack_a, &stack_b);
		
		// printf("\n");
		int i;
		i = 0;
		while (i <= stack_a.top)
		{
			printf("%d\n", stack_a.num_stack[i]);
			i++;
		}
	}
	else
		return (-1);
	return (0);
}