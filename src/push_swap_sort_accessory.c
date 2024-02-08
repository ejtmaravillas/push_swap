/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_accessory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:01:02 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/06 00:01:02 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	stack_n_loc_b(int *stack_src, int *stack_dest, int size)
// {
// 	int	loc;
// 	int	index;
// 	int	len;
// 	int	temp;

// 	len = stack_get_len(stack_src, size);
// 	index = 0;
// 	while (index < len)
// 	{
// 		temp = stack_dest[0] - stack_src[index];
// 		if (temp == 2)
// 			loc = index;
// 		index++;
// 	}
// 	return (loc);
// }

int	stack_get_max(int *stack, int size)
{
	int	index;
	int	max;

	index = 0;
	max = 0;
	while (stack[index] > 0 && index < size)
	{
		if (stack[index] > max)
			max = stack[index];
		if (index == size - 1)
			break ;
		index++;
	}
	return (max);
}

int	stack_get_min(int *stack, int min, int size)
{
	int	index;

	index = 0;
	while (stack[index] > 0 && index < size)
	{
		if (stack[index] < min)
			min = stack[index];
		if (index == size - 1)
			break ;
		index++;
	}
	return (min);
}

// bool	stack_check_rev(t_stack data, int mid)
// {
// 	int	len;

// 	len = stack_get_len(data.a.stack, data.a.size);
// 	if (data.a.stack[len - 1] > mid && data.a.stack[len - 1] <= data.a.last)
// 	{
// 		stack_op_rr(data.a.stack, data.a.size, 'a');
// 		stack_op_push(data.a.stack, data.b.stack, data.a.size, 'b');
// 	}
// 	else if (data.a.stack[len - 1] <= mid
// 		&& data.a.stack[len - 1] >= data.a.first)
// 	{
// 		stack_op_
// 		stack_op_push(data.a.stack, data.b.stack, data.a.size, 'b');
// 		if ((!(data.a.stack[len - 1] <= mid
// 					&& data.a.stack[len - 1] >= data.a.first))
// 			&& !((data.a.stack[len - 1] > mid && data.a.stack[len - 1]
// 					<= data.a.last)))
// 		{
// 			stack_op_ra_r(data);
// 			ft_printf("rr\n");
// 		}
// 		else if (stack_get_len(data.b.stack, data.a.size) > 1)
// 			stack_op_r(data.b.stack, data.a.size, 'b');
// 	}
// 	else
// 	{
// 		stack_op_r(data.a.stack, data.a.size, 'a');
// 		return (false);
// 	}
// 	return (true);
// }

// void	stack_move_compare(t_stack data, int loca, int locb)
// {
// 	int	total_a;
// 	int	total_b;
// 	int	vala;
// 	int	valb;

// 	total_a = (loca * 2) + locb;
// 	total_b = (locb * 2) + loca;
// 	vala = data.b.stack[loca];
// 	valb = data.b.stack[locb];
// 	if (total_a < total_b)
// 	{
// 		stack_get_operate(data, loca, vala);
// 		stack_get_operate(data, locb, valb);
// 	}
// 	else if (total_b < total_a)
// 	{
// 		stack_get_operate(data, locb, valb);
// 		stack_get_operate(data, loca, vala);
// 	}
// }

// void	stack_get_operate(t_stack data, int loc, int val)
// {
// 	int	lenb;

// 	lenb = stack_get_len(data.b.stack, data.a.size);
// 	if (loc <= (lenb / 2))
// 		while (data.b.stack[0] != val)
// 			stack_op_r(data.b.stack, data.a.size, 'b');
// 	else if (loc > (lenb / 2))
// 		while (data.b.stack[0] != val)
// 			stack_op_rr(data.b.stack, data.a.size, 'b');
// 	if (data.a.stack[0] < data.b.stack[0])
// 	{
// 		stack_op_r(data.a.stack, data.a.size, 'a');
// 		stack_op_push(data.b.stack, data.a.stack, data.a.size, 'a');
// 		stack_op_rr(data.a.stack, data.a.size, 'a');
// 	}
// 	else
// 		stack_op_push(data.b.stack, data.a.stack, data.a.size, 'a');
// }
