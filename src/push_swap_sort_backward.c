#include "push_swap.h"

void	stack_sort_backward(t_stack data)
{
	int loca;
    int len;
	int val;

	// ft_printf("##### BACKWARD #####\n");
	while (data.b.stack[0] > 0)
	{
		len = stack_get_len(data.b.stack, data.a.size);
		loca = stack_n_loc_a(data.b.stack, data.a.stack, data.a.size);
		val = data.b.stack[loca];
		// ft_printf("len: %d || loca: %d || val: %d\n", len, loca, val);
		// stack_print(data);
		if (loca <= (len/2))
			while (data.b.stack[0] != val)
				stack_op_r(data.b.stack, data.a.size, 'b');
		else if (loca > (len/2))
			while (data.b.stack[0] != val)
				stack_op_rr(data.b.stack, data.a.size, 'b');
		stack_op_push(data.b.stack, data.a.stack, data.a.size, 'a');
	}
}

int    stack_n_loc_a(int *stack_src, int *stack_dest, int size)
{
    int loc;
    int index;
    int len;
	int temp;

	len = stack_get_len(stack_src, size);
    index = 0;
    while (index < len)
    {
		temp = stack_dest[0] - stack_src[index];
        if (temp == 1)
			loc = index;
		index++;
    }
	return (loc);
}
int		stack_get_len(int *stack, int size)
{
	int index;

	index = 0;
    while (stack[index] > 0 && index < size)
	{
        index++;
	}
	return (index);
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
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (sign * num) < INT_MIN))
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