/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:28:25 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/31 13:30:28 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**stack_raw;
	t_stack	data;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putendl_fd("Error", 2), 1);
	if (argc == 2)
	{
		stack_raw = ft_split(argv[1], ' ');
		data_init(&data, count_elements(stack_raw), stack_raw);
	}
	else if (argc > 2 && argv++)
		data_init(&data, count_elements(argv), argv);
	return (0);
}

void	data_init(t_stack *data, int argc, char **argv)
{
	stack_init(data, &data->a, argc);
	stack_init(data, &data->b, argc);
	data->stacklist = NULL;
	stack_fill(data, &data->a, argc, argv);
}

void	stack_fill(t_stack *data, t_stackinfo *stk, int size, char **argv)
{
	int	*stack_num;
	int	count;

	stack_num = malloc(sizeof(int) * size);
	count = 0;
	if (!stack_num)
		error(data);
	while (argv[count])
	{
		if (!check_arg(argv[count]))
			error(data);
		stack_num[count] = ft_atoi(argv[count]);
		count++;
	}
	check_duplicate(data, stack_num, size);
	stack_tabulate(stack_num, stk->stack, size);
	while (size--)
		ft_printf("stack_num[%d]: %d || stack_order[%d]: %d\n", size, stack_num[size], size, stk->stack[size]);
	free(stack_num);
}

void	stack_tabulate(int *stack_num, int *stack, int size)
{
	int	n;
	int	m;
	int	order;

	n = 0;
	while (n < size)
	{
		m = 0;
		order = 1;
		while (m < size)
			if (stack_num[n] > stack_num[m++])
				order++;
		stack[n++] = order;
	}
}

void	check_duplicate(t_stack *data, int *stack_num, int size)
{
	int	n;
	int	m;

	n = 0;
	while (n < size)
	{
		m = n + 1;
		while (m < size)
		{
			if (stack_num[n] == stack_num[m])
			{
				free(stack_num);
				error(data);
			}
			m++;
		}
		n++;
	}
}

bool	check_arg(char *arg)
{
	long long	num;
	int			sign;

	sign = 1;
	num = 0;
	if (!*arg)
		return (false);
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
		if (!*arg)
			return (false);
	}
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		num = (num * 10) + (*arg - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
			return (false);
		arg++;
	}
	return (true);
}

void	stack_init(t_stack *data, t_stackinfo *stk, int size)
{
	stk->stack = malloc(sizeof(int) * size);
	if (!stk->stack)
		error(data);
	stk->first = 0;
	stk->last = 0;
	stk->size = size;
	ft_memset(stk->stack, 0, sizeof(int) * size);
}

int	count_elements(char **s)
{
	int	count;

	count = 0;
	while (*s++)
		count++;
	ft_printf("count: %d\n", count);
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
	// if (data->stacklist)
	//     ft_lstclear(&data->stacklist, NULL);
}
