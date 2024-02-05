#include "../src/push_swap.h"
#include "../lib/get_next_line/get_next_line.h"

void    stack_command_s(t_stack, char *command)
{
    if (ft_strncmp(command, "sa", 2))
        stack_op_s(data.a.stack, 'a');
    if (ft_strncmp(command, "sb", 2))
        stack_op_s(data.b.stack, 'b');
    if (ft_strncmp(command, "ra", 2))
        stack_op_r(data.a.stack, data.a.size, 'a');
    if (ft_strncmp(command, "rb", 2))
        stack_op_r(data.b.stack, data.a.size, 'b');
    if (ft_strncmp(command, "rra", 3))
        stack_op_rr(data.a.stack, data.a.size, 'a');
    if (ft_strncmp(command, "rrb", 3))
        stack_op_rr(data.a.stack, data.a.size, 'b');
    if (ft_strncmp(command, "pa", 2))
        stack_op_push(data.b.stack, data.a.stack, 'a');
    if (ft_strncmp(command, "pb", 2))
        stack_op_push(data.a.stack, data.b.stack, 'b');
    if (ft_strncmp(command, 'rr', 2))
        stack_op_ra_r(data);
}
