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
	if (!temp)
		return ;
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
	if (!stack[0])
		return ;
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

void	stack_op_s(int *stack, char c)
{
	int	a;
	int	b;

	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
	if (!stack[0])
		return ;
	a = stack[0];
	b = stack[1];
	stack[0] = b;
	stack[1] = a;
}

void	stack_op_ss(t_stack data, char c)
{
	if (!data.a.stack[0] || !data.b.stack[0])
		return ;
	if (c == 'a' || c == 'b')
	{
		stack_op_s(data.a.stack, 'a');
		stack_op_s(data.b.stack, 'b');
	}
	else
	{
		stack_op_s(data.a.stack, c);
		stack_op_s(data.b.stack, c);
	}
}

void	free_error_arg(t_stack *data, char **argv, int *stack_num)
{
	t_stackinfo	*stk;

	stk = &data->a;
	if (stk->d <= 2)
		free_stack_raw(argv);
	free(stack_num);
	error(data);
}
