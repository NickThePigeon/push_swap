/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 14:36:44 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/04 12:29:56 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		initialize(argc, argv);
	}
	else
	{
		ft_putendl_fd("ERROR", 2);
	}
	return (0);
}
