/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:00:16 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/06 00:00:16 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_init(t_stack *data, int argc, char **argv)
{
	stack_init(data, &data->a, argc);
	stack_init(data, &data->b, argc);
	data->stacklist = NULL;
	stack_fill(data, &data->a, argc, argv);
}

void	stack_init(t_stack *data, t_stackinfo *stk, int size)
{
	stk->stack = malloc(sizeof(int) * size);
	if (!stk->stack)
		error(data);
	stk->first = 0;
	stk->last = 0;
	stk->mid = 0;
	stk->size = size;
	ft_memset(stk->stack, 0, sizeof(int) * size);
}

int	count_elements(char **s)
{
	int	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

void	error(t_stack *data)
{
	free_stack(data);
	ft_putendl_fd("Error", 2);
	exit (EXIT_FAILURE);
}

void	free_stack(t_stack *data)
{
	if (data->a.stack)
		free(data->a.stack);
	if (data->b.stack)
		free(data->b.stack);
}
