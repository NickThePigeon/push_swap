/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 18:39:33 by nduijf        #+#    #+#                 */
/*   Updated: 2021/11/05 21:37:20 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error_msg
{
	DEBUG = 1,
	MALLOC_FAILED,
	STACK_ALLOCATION_FAIL,
	INTEGER_OVERFLOW,
	DOUBLE_INTEGER,
	SUCCES,
}	t_error_msg;

#endif