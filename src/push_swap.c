/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:28:25 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/31 18:57:23 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**stack_raw;
	t_stack	data;
	int		size;
	int		count;
	int		len;

	count = -1;
	size = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putendl_fd("Error", 2), 1);
	if (argc == 2)
	{
		stack_raw = ft_split(argv[1], ' ');
		size = count_elements(stack_raw);
		data_init(&data, size, stack_raw);
	}
	else if (argc > 2 && argv++)
	{
		stack_raw = argv;
		size = count_elements(argv);
		data_init(&data, size, stack_raw);
	}
	if (check_if_sorted(data.a.stack, size))
		exit(EXIT_SUCCESS);
	ft_printf("## A PRINT STACK A ##\n");
	while (data.a.stack[++count])
		ft_printf("stack_a[%d]: %d || stack_b[%d]: %d\n", count, data.a.stack[count], count, data.b.stack[count]);
	stack_op_s(data.a.stack);
	count = -1;
	ft_printf("## B SA OPERATION ##\n");
	while (data.a.stack[++count])
		ft_printf("stack_a[%d]: %d || stack_b[%d]: %d\n", count, data.a.stack[count], count, data.b.stack[count]);
	stack_op_r(data.a.stack, size);
	ft_printf("## C RA OPERATION ##\n");
	count = -1;
	while (data.a.stack[++count])
		ft_printf("stack_a[%d]: %d || stack_b[%d]: %d\n", count, data.a.stack[count], count, data.b.stack[count]);
	stack_op_rr(data.a.stack, size);
	ft_printf("## D REVERSE RA OPERATION ##\n");
	count = -1;
	while (data.a.stack[++count])
		ft_printf("stack_a[%d]: %d || stack_b[%d]: %d\n", count, data.a.stack[count], count, data.b.stack[count]);
	stack_op_push(data.a.stack, data.b.stack, size);
	ft_printf("## E PUSH A OPERATION ##\n");
	count = -1;
	len = size;
	while (len--)
	{
		count++;
		ft_printf("stack_a[%d]: %d || stack_b[%d]: %d\n", count, data.a.stack[count], count, data.b.stack[count]);
	}
	stack_op_push(data.b.stack, data.a.stack, size);
	ft_printf("## F PUSH B OPERATION ##\n");
	count = -1;
	len = size;
	while (len--)
	{
		count++;
		ft_printf("stack_a[%d]: %d || stack_b[%d]: %d\n", count, data.a.stack[count], count, data.b.stack[count]);
	}
	return (0);
}

void	stack_op_s(int *stack)
{
	int	a;
	int	b;

	a = stack[0];
	b = stack[1];
	stack[0] = b;
	stack[1] = a;
}

void	stack_op_r(int *stack, int size)
{
	int	index;
	int	temp;

	index = 1;
	temp = stack[0];
	while (index < size)
	{
		stack[index - 1] = stack[index];
		index++;
	}
	stack[size - 1] = temp;
}

void	stack_op_rr(int *stack, int size)
{
	int	index;
	int	temp;

	index = 0;
	temp = stack[size - 1];
	while (size > index)
	{
		// ft_printf("index: %d ## stack[index + 1]: %d || stack[index]: %d\n", size, stack[size - 1], stack[size - 2]);
		stack[size - 1] = stack[size - 2];
		// ft_printf("index: %d ## stack[index + 1]: %d || stack[index]: %d\n", size, stack[size - 1], stack[size - 2]);
		size--;
	}
	stack[0] = temp;
}

void	stack_op_push(int *stack_src, int *stack_dest, int size)
{
	int		temp;
	int		index;
	int		len;

	len = size;
	if (stack_is_empty(stack_src))
		return ;
	temp = stack_src[0];
	index = 0;
	while (len > index)
	{
		stack_dest[len - 1] = stack_dest[len - 2];
		len--;
	}
	stack_dest[0] = temp;
	index = 1;
	len = size;
	while (index < len)
	{
		stack_src[index - 1] = stack_src[index];
		index++;
	}
	stack_src[len - 1] = 0;
}

bool	stack_is_empty(int *stack)
{
	int sum;
	int index;

	sum = 0;
	index = 0;
	while (sum == 0)
		sum += stack[index++];
	if (sum)
		return (false);
	else
		return (true);
}

// int	stack_size(int *stack)
// {
// 	int	count;

// 	count = 0;
// 	while (stack[count])
// 		count++;
// 	return (count);
// }

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

bool	check_if_sorted(int *stack, int size)
{
	int	index;

	index = 0;
	while (index < size - 1)
	{
		if (stack[index] > stack[index + 1])
			return (false);
		index++;
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
	if (count == 1)
		exit(EXIT_SUCCESS);
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
