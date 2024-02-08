/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:17:38 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/06 00:17:38 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char	**stack_raw;
	t_stack	data_check;
	int		size;

	size = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		stack_raw = ft_split(argv[1], ' ');
		size = count_elements(stack_raw);
		if (size == 1)
			return (free_stack_raw(stack_raw), 1);
		data_init(&data_check, size, stack_raw, argc);
	}
	else
	{
		stack_raw = ++argv;
		size = count_elements(argv);
		data_init(&data_check, size, stack_raw, argc);
	}
	check_gnl(data_check, stack_raw);
	return (0);
}

void	check_gnl(t_stack data_check, char **stack_raw)
{
	char	*commands;

	commands = malloc(1 * sizeof(char));
	if (data_check.a.d <= 2)
		free_stack_raw(stack_raw);
	if (check_if_sorted(data_check, data_check.a.size))
	{
		free_stack(&data_check);
		free(commands);
		return ;
	}
	while (commands != NULL)
	{
		free(commands);
		commands = get_next_line(STDIN_FILENO);
		if (!commands)
			break ;
		if (!(stack_command(data_check, commands)))
		{
			free_null(commands);
			error(&data_check);
		}
	}
	print_out(data_check);
	free_stack(&data_check);
}

int	stack_command(t_stack data, char *command)
{
	if (!(ft_strncmp(command, "sa\n", 3)))
		stack_op_s(data.a.stack, 'd');
	else if (!(ft_strncmp(command, "sb\n", 3)))
		stack_op_s(data.b.stack, 'd');
	else if (!(ft_strncmp(command, "ra\n", 3)))
		stack_op_r(data.a.stack, data.a.size, 'd');
	else if (!(ft_strncmp(command, "rb\n", 3)))
		stack_op_r(data.b.stack, data.a.size, 'd');
	else if (!(ft_strncmp(command, "rra\n", 4)))
		stack_op_rr(data.a.stack, data.a.size, 'd');
	else if (!(ft_strncmp(command, "rrb\n", 4)))
		stack_op_rr(data.b.stack, data.a.size, 'd');
	else if (!(ft_strncmp(command, "pa\n", 3)))
		stack_op_push(data.b.stack, data.a.stack, data.a.size, 'd');
	else if (!(ft_strncmp(command, "pb\n", 3)))
		stack_op_push(data.a.stack, data.b.stack, data.a.size, 'd');
	else if (!(ft_strncmp(command, "rr\n", 3)))
		stack_op_ra_r(data);
	else if (!(ft_strncmp(command, "rrr\n", 4)))
		stack_op_ra_rr(data);
	else
		return (0);
	return (1);
}

void	print_out(t_stack data)
{
	if (check_if_sorted(data, data.a.size))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
