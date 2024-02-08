/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_forward.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:07:46 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/06 00:07:46 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort_forward(t_stack data)
{
	int	mid;
	int	size;

	if (check_if_sorted(data, data.a.size))
		return ;
	size = data.a.size;
	mid = size / data.a.div;
	data.a.first = 0;
	data.a.last = mid * 2;
	while (data.a.first != data.a.last && data.a.first < data.a.last)
	{
		stack_sort_gtmid(data, data.a.size, mid);
		size = size - ((size * 2) / data.a.div);
		mid = data.a.last + (size / data.a.div);
		data.a.first = data.a.last;
		data.a.last = mid + (size / data.a.div);
	}
	stack_sort_rem(data);
	sort_stack_three(data);
}

void	stack_sort_gtmid(t_stack data, int size, int mid)
{
	int	count;

	count = data.a.first;
	while (size-- && count < data.a.last)
	{
		if (stack_check(data, mid))
			count++;
	}
}

void	sort_stack_three(t_stack data)
{
	int	n;
	int	m;
	int	order;
	int	stack[3];
	int	size;

	n = 0;
	size = 0;
	while (data.a.stack[n] > 0 && n < data.a.size)
	{
		stack[size++] = 0;
		if (++n == data.a.size)
			break ;
	}
	n = 0;
	while (n < size)
	{
		m = 0;
		order = 1;
		while (m < size)
			if (data.a.stack[n] > data.a.stack[m++])
				order++;
		stack[n++] = order;
	}
	sort_stack_three_a(data, stack, size);
}

void	sort_stack_three_a(t_stack data, int stack[3], int size)
{
	if ((stack[0] - stack[1]) == -2 && stack[0] == 1)
	{
		stack_op_rr(data.a.stack, size, 'a');
		stack_op_s(data.a.stack, 'a');
	}
	else if ((stack[0] - stack[1]) == 1 && stack[0] == 2)
		stack_op_s(data.a.stack, 'a');
	else if ((stack[0] - stack[1]) == 1 && stack[0] == 3)
	{
		stack_op_s(data.a.stack, 'a');
		stack_op_rr(data.a.stack, size, 'a');
	}
	else if ((stack[0] - stack[1]) == 2 && stack[0] == 3)
		stack_op_r(data.a.stack, size, 'a');
	else if ((stack[0] - stack[1]) == -1 && stack[0] == 2)
		stack_op_rr(data.a.stack, size, 'a');
}

void	stack_sort_rem(t_stack data)
{
	int	mid;
	int	size;
	int	index;
	int	len;

	index = 0;
	while (data.a.stack[index] > 0 && index < data.a.size)
	{
		index++;
		if (index == data.a.size)
			break ;
	}
	len = index - 2;
	data.a.first = stack_get_min(data.a.stack, data.a.size, data.a.size) - 1;
	data.a.last = stack_get_max(data.a.stack, data.a.size) - 3;
	size = len;
	mid = data.a.first + size / 2;
	while (data.a.first != data.a.last && data.a.first < data.a.last)
	{
		stack_sort_gtmid(data, data.a.size, mid);
		size = size - ((size * 2) / 2);
		mid = data.a.last + (size / 2);
		data.a.first = data.a.last;
		data.a.last = mid + (size / 2);
	}
}
