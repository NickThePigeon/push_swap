/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 13:57:54 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/05 21:30:58 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_close(t_error_msg message, int err)
{
	err = 0;
	print_error(message);
	exit(0);
}

void	print_error(t_error_msg message)
{
	if (message == NO_ARGUMENTS)
		ft_putendl_fd("ERROR\nNo arguments given", 2);
	if (message == MALLOC_FAILED)
		ft_putendl_fd("ERROR\nMalloc allocation failed", 2);
	if (message == INTEGER_OVERFLOW)
		ft_putendl_fd("ERROR\nInteger exceeds limits", 2);
	if (message == STACK_ALLOCATION_FAIL)
		ft_putendl_fd("ERROR\nArguments can only be integers", 2);
	if (message == DOUBLE_INTEGER)
		ft_putendl_fd("ERROR\nDouble integer in stack", 2);
	if (message == UNKOWN_EXCUTION_INPUT)
		ft_putendl_fd("ERROR\nUnknown execution input", 2);
	if (message == KO)
		ft_putendl_fd("KO", 1);
	if (message == SUCCES)
		ft_putendl_fd("OK", 1);
}
