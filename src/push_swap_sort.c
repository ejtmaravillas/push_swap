/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:11:23 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/06 00:11:23 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_stack data, int size)
{
	if (size == 3)
	{
		if (!check_if_sorted(data, size))
			sort_stack_three(data);
		free_stack(&data);
		exit(EXIT_SUCCESS);
	}
	else
	{
		data.a.size = size;
		data.b.size = size;
		stack_sort_forward(data);
		stack_sort_backward(data);
		if (!check_if_sorted(data, size))
		{
			if (check_oneloc(data, size))
				while (data.a.stack[0] != 1)
					stack_op_rr(data.a.stack, size, 'a');
			else
				while (data.a.stack[0] != 1)
					stack_op_r(data.a.stack, size, 'a');
		}
	}
}

bool	check_oneloc(t_stack data, int size)
{
	int	index;

	index = 0;
	while (index < size - 1)
	{
		if (data.a.stack[index] == 1 && index > size / 2)
			return (true);
		else if (data.a.stack[index] == 1 && index < size / 2)
			return (false);
		index++;
	}
	return (false);
}

bool	stack_check(t_stack data, int mid)
{
	if (data.a.stack[0] > mid && data.a.stack[0] <= data.a.last)
		stack_op_push(data.a.stack, data.b.stack, data.a.size, 'b');
	else if (data.a.stack[0] <= mid && data.a.stack[0] >= data.a.first)
	{
		stack_op_push(data.a.stack, data.b.stack, data.a.size, 'b');
		if ((!(data.a.stack[0] <= mid && data.a.stack[0] >= data.a.first))
			&& !((data.a.stack[0] > mid && data.a.stack[0] <= data.a.last)))
		{
			stack_op_ra_r(data);
			ft_printf("rr\n");
		}
		else if (stack_get_len(data.b.stack, data.a.size) > 1)
			stack_op_r(data.b.stack, data.a.size, 'b');
	}
	else
	{
		stack_op_r(data.a.stack, data.a.size, 'a');
		return (false);
	}
	return (true);
}

void	stack_print(t_stack data)
{
	int	count;
	int	len;

	count = -1;
	len = data.a.size;
	while (len--)
	{
		count++;
		ft_printf("stack_a[%d]: %d\n", count, data.a.stack[count]);
	}
}

bool	stack_is_empty(int *stack)
{
	int	sum;
	int	index;

	sum = 0;
	index = 0;
	while (sum == 0)
		sum += stack[index++];
	if (sum)
		return (false);
	else
		return (true);
}
