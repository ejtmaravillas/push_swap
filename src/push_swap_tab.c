#include "push_swap.h"

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

void	free_stack_raw(char **stack_raw)
{
	int count;

	count = 0;
	while (stack_raw[count] != NULL)
	{
		free(stack_raw[count]);
		count++;
	}
}


int	get_abs(int num1, int num2)
{
	int diff;

	diff = num1 - num2;
	if (diff < 0)
		diff *= -1;
	return (diff);
}