/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:28:25 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/01 21:51:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**stack_raw;
	t_stack	data;
	int		size;

	size = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		stack_raw = ft_split(argv[1], ' ');
		size = count_elements(stack_raw);
		data_init(&data, size, stack_raw);
		free_stack_raw(stack_raw);
		stack_sort(data, size);
		free_stack(&data);
	}
	else
	{
		stack_raw = ++argv;
		size = count_elements(argv);
		data_init(&data, size, stack_raw);
		stack_sort(data, size);
		free_stack(&data);
	}
	return (0);
}
