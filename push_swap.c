/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:36:44 by nicky         #+#    #+#                 */
/*   Updated: 2021/08/11 12:44:34 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_close(int err)
{
	exit(0);
}

static int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	else
		return (0);
}

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	min;
	int	answer;

	min = 1;
	answer = 0;
	while (ft_isspace(str[0]))
		str++;
	if (str[0] == 45)
		min = min * -1;
	if ((str[0] == 45) || (str[0] == 43))
		str++;
	while (ft_isdigit(str[0]))
	{
		answer = answer * 10 + str[0] - '0';
		str++;
	}
	return (answer * min);
}

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

int	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	int err;

	err = 0;
	err += swap(stack_a);
	err += swap(stack_b);
	if (err == 2)
		return (1);
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

int	rotate(t_stack *stack)
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

int rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	int err;

	err = 0;
	if (stack_a->top > 0 && stack_b->top > 0)
	{
		err += rotate(stack_a);
		err += rotate(stack_b);
		if (err == 2)
			return (1);
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
				ft_close(0);
		}
		j = 0;
		stack->num_stack[stack->top] = ft_atoi(args[i]);
		if (!stack->num_stack[stack->top])
			exit(0);
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
	while (i < stack_a->top)
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

int	sort(t_stack *stack_a, t_stack *stack_b)
{	
	if (stack_b->top < 2)
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
	while (!is_sorted(stack_a))
	{	
		if (stack_b->num_stack[stack_b->top])
	}
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
		sort(&stack_a, &stack_b);
		for (int i = 0; i <= stack_a.top; i++)
		{
			printf("%d\n", stack_a.num_stack[i]);
		}
		printf("\n");
		for (int i = 0; i <= stack_b.top; i++)
		{
			printf("%d\n", stack_b.num_stack[i]);
		}
	}
	else
		return (-1);
	return (0);
}