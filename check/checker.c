#include "checker.h"

int	main(int argc, char **argv)
{
	char	**stack_raw;
	t_stack	data_check;
	int		size;
    char    *commands = malloc(1 * sizeof(char));

	size = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
    {
		stack_raw = ft_split(argv[1], ' ');
        size = count_elements(stack_raw);
        data_init(&data_check, size, stack_raw);
    }
	else if (argc > 2 && argv++)
    {
		stack_raw = argv;
        size = count_elements(argv);
        data_init(&data_check, size, stack_raw);
    }
    while (commands != NULL)
    {
        free(commands);
        commands = get_next_line(STDIN_FILENO);
        if (!commands)
            break ;
        if(!(stack_command(data_check, commands)))
        {
            ft_printf("Error\n");
            exit(-1);
        }
    }
    size = 0;
    print_out(data_check);
    free_stack(&data_check);
	return (0);
}

int    stack_command(t_stack data, char *command)
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
    {
        // free(command);
        return (0);
    }
    return (1);
}

void    print_out(t_stack data)
{
    if (check_if_sorted(data.a.stack, data.a.size))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}