/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:14:23 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/06 00:14:23 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_op_r(int *stack, int size, char c)
{
	int	index;
	int	temp;
	int	size_stack;

	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
	temp = stack[0];
	size_stack = 0;
	while (stack[size_stack] != 0 && size_stack < size)
		if (++size_stack == size)
			break ;
	index = 1;
	while (index < size)
	{
		stack[index - 1] = stack[index];
		index++;
	}
	stack[size_stack - 1] = temp;
	while (size_stack < size - 1)
	{
		stack[size_stack] = 0;
		size_stack++;
	}
}

void	stack_op_rr(int *stack, int size, char c)
{
	int	index;
	int	temp;
	int	size_stack;

	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
	size_stack = 0;
	while (stack[size_stack] != 0 && size_stack < size)
	{
		size_stack++;
		if (size_stack == size)
			break ;
	}
	temp = stack[size_stack - 1];
	index = 1;
	while (size_stack > index)
	{
		stack[size_stack - 1] = stack[size_stack - 2];
		size_stack--;
	}
	stack[0] = temp;
}

void	stack_op_push(int *stack_src, int *stack_dest, int size, char c)
{
	int	temp;
	int	index;
	int	len;

	len = size;
	temp = stack_src[0];
	stack_src[0] = 0;
	size++;
	while (--size > 1)
	{
		stack_dest[size - 1] = stack_dest[size - 2];
	}
	stack_dest[0] = temp;
	index = 1;
	while (index < len)
	{
		stack_src[index - 1] = stack_src[index];
		index++;
	}
	stack_src[len - 1] = 0;
	if (c == 'a' || c == 'b')
		ft_printf("p%c\n", c);
}
