/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 13:56:53 by nicky         #+#    #+#                 */
/*   Updated: 2021/11/03 13:50:42 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

typedef enum
{
	MALLOC_FAILED,
	STACK_ALLOCATION_FAIL,
	INTEGER_OVERFLOW,
	DOUBLE_INTEGER,
	UNKOWN_EXCUTION_INPUT,
	KO,
	SUCCES,
}	error_msg;

#endif