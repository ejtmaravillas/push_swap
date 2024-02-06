/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:15:11 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/06 00:15:11 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_op_s(int *stack, char c)
{
	int	a;
	int	b;

	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	a = stack[0];
	b = stack[1];
	stack[0] = b;
	stack[1] = a;
}

void	stack_op_ra_r(t_stack data)
{
	int	index;
	int	temp;
	int	size_stack;

	temp = data.a.stack[0];
	if (!data.b.stack[0])
		return ;
	size_stack = 0;
	while (data.a.stack[size_stack] != 0 && size_stack < data.a.size)
		if (++size_stack == data.a.size)
			break ;
	index = 1;
	while (index < data.a.size)
	{
		data.a.stack[index - 1] = data.a.stack[index];
		index++;
	}
	data.a.stack[size_stack - 1] = temp;
	while (size_stack < data.a.size - 1)
	{
		data.a.stack[size_stack] = 0;
		size_stack++;
	}
	stack_op_rb_r(data);
}

void	stack_op_rb_r(t_stack data)
{
	int	index;
	int	temp;
	int	size_stack;

	temp = data.b.stack[0];
	size_stack = 0;
	while (data.b.stack[size_stack] != 0 && size_stack < data.a.size)
		if (++size_stack == data.a.size)
			break ;
	index = 1;
	while (index < data.a.size)
	{
		data.b.stack[index - 1] = data.b.stack[index];
		index++;
	}
	data.b.stack[size_stack - 1] = temp;
	while (size_stack < data.a.size - 1)
	{
		data.b.stack[size_stack] = 0;
		size_stack++;
	}
}

void	stack_op_ra_rr(t_stack data)
{
	int	index;
	int	temp;
	int	size_stack;

	size_stack = 0;
	while (data.a.stack[size_stack] != 0 && size_stack < data.a.size)
	{
		size_stack++;
		if (size_stack == data.a.size)
			break ;
	}
	temp = data.a.stack[size_stack - 1];
	index = 1;
	while (size_stack > index)
	{
		data.a.stack[size_stack - 1] = data.a.stack[size_stack - 2];
		size_stack--;
	}
	data.a.stack[0] = temp;
	stack_op_rb_rr(data);
}

void	stack_op_rb_rr(t_stack data)
{
	int	index;
	int	temp;
	int	size_stack;

	if (!data.b.stack[0])
		return ;
	size_stack = 0;
	while (data.b.stack[size_stack] != 0 && size_stack < data.a.size)
	{
		size_stack++;
		if (size_stack == data.a.size)
			break ;
	}
	temp = data.b.stack[size_stack - 1];
	index = 1;
	while (size_stack > index)
	{
		data.b.stack[size_stack - 1] = data.b.stack[size_stack - 2];
		size_stack--;
	}
	data.b.stack[0] = temp;
}
