/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 13:56:53 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/05 14:09:34 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

typedef enum
{
	NO_ARGUMENTS,
	MALLOC_FAILED,
	STACK_ALLOCATION_FAIL,
	INTEGER_OVERFLOW,
	DOUBLE_INTEGER,
	UNKOWN_EXCUTION_INPUT,
	KO,
	SUCCES,
}	error_msg;

#endif