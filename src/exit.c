/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 18:22:31 by nduijf        #+#    #+#                 */
/*   Updated: 2021/11/02 00:34:50 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"

void	ft_close(error_msg message, int err, t_all *all)
{
	print_error(message);
	free_stack_array(all, err);
	exit(0);
}

void	print_error(error_msg msg)
{
	if (msg == MALLOC_FAILED)
		ft_putendl_fd("ERROR\nMalloc allocation failed", 2);
	if (msg == INTEGER_OVERFLOW)
		ft_putendl_fd("ERROR\nInteger exceeds limits", 2);
	if (msg == STACK_ALLOCATION_FAIL)
		ft_putendl_fd("ERROR\nStack allocation failed", 2);
	if (msg == DOUBLE_INTEGER)
		ft_putendl_fd("ERROR\nDouble integer in stack", 2);
}

void	free_stack_array(t_all *all, int err)
{
	if (err > 2)
	{
		free(all->stack_a.num_stack);
		free(all->stack_b.num_stack);
	}
	if (err > 6)
		free(all->copy_a.num_stack);
	if (err > 7)
		free(all->enum_a.num_stack);
}
