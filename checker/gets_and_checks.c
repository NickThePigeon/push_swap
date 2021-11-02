/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gets_and_checks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 16:44:07 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/02 16:44:54 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_doubles(t_stack *stack)
{
	int	holder;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->top)
	{
		holder = stack->array[i];
		while (j < stack->top)
		{
			if (holder == stack->array[j] && j != i)
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
	int	len;
	int	j;

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
		stack->array[stack->top] = ft_atoi(args[len]);
		stack->top++;
		len--;
	}
	return (1);
}

int	check_overflow(char **argv, t_stack *stack)
{
	char	*ret_itoa;
	int		len;
	int		i;

	len = stack->top - 1;
	i = 1;
	while (argv[i])
	{
		ret_itoa = ft_itoa(stack->array[len]);
		if (ft_strncmp(argv[i], ret_itoa, ft_strlen(argv[i])))
			return (0);
		if (ret_itoa)
			free(ret_itoa);
		i++;
		len--;
	}
	return (1);
}
