/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 18:03:48 by nicky         #+#    #+#                 */
/*   Updated: 2021/10/31 20:46:24 by nicky         ########   odam.nl         */
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

int	get_arguments(char **args, t_stack *stack)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (args[i])
	{
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
		stack->top++;
		i++;
	}
	return (0);
}
