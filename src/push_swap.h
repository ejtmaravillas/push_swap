/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:31:01 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/31 13:31:01 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define DIVISION 5

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"

// stack_info --> necessary info for stack a and stack b
// stack --> int pointer for the stack values
// size --> number of elements for stack a and b
// first --> first value of stack
// last --> last value of stack
typedef struct stack_info
{
	int	*stack;
	int	size;
	int	first;
	int	last;
	int	mid;
	int	d;
	int	div;
}	t_stackinfo;

typedef struct stack_push_swap
{
	t_stackinfo	a;
	t_stackinfo	b;
}	t_stack;

int		count_elements(char **s);
void	data_init(t_stack *data, int argc, char **argv, int d);
void	stack_init(t_stack *data, t_stackinfo *stk, int size, int d);
void	error(t_stack *data);
void	free_error_arg(t_stack *data, char **argv, int *stack_num);
void	free_stack(t_stack *data);
void	free_stack_raw(char **stack_raw);
void	stack_fill(t_stack *data, t_stackinfo *stk, int size, char **argv);
bool	check_arg(char *arg);
void	check_duplicate(t_stack *data, int *stack_num, int size, char **argv);
void	stack_tabulate(int *stack_num, int *stack, int size);
bool	check_if_sorted(t_stack data, int size);
void	stack_op_s(int *stack, char c);
void	stack_op_ss(t_stack data, char c);
void	stack_op_r(int *stack, int size, char c);
void	stack_op_rr(int *stack, int size, char c);
void	stack_op_push(int *stack_src, int *stack_dest, int size, char c);
bool	stack_is_empty(int *stack);
void	stack_sort_forward(t_stack data);
void	stack_sort_gtmid(t_stack data, int size, int mid);
void	stack_sort_lsmid(t_stack data, int size, int mid);
void	stack_sort_backward(t_stack data);
void	stack_print(t_stack data);
void	sort_stack_three_a(t_stack data, int stack[3], int size);
void	sort_stack_three(t_stack data);
void	stack_sort(t_stack data, int size);
int		stack_n_loc_a(int *stack_src, int *stack_dest, int size);
int		stack_n_loc_b(int *stack_src, int *stack_dest, int size);
bool	check_np1(t_stack data);
bool	check_nm1(t_stack data);
bool	check_oneloc(t_stack data, int size);
int		get_abs(int num1, int num2);
void	stack_sort_rem(t_stack data);
int		stack_get_min(int *stack, int min, int size);
int		stack_get_max(int *stack, int size);
int		stack_get_len(int *stack, int size);
void	stack_move_compare(t_stack data, int loca, int locb);
bool	stack_check(t_stack data, int mid);
void	stack_op_ra_r(t_stack data);
void	stack_op_rb_r(t_stack data);
void	stack_get_operate(t_stack data, int loc, int val);
void	stack_sort_lt5(t_stack data);
void	stack_sort_gt5(t_stack data);
int		stack_get_div(int size);
void	stack_op_ra_rr(t_stack data);
void	stack_op_rb_rr(t_stack data);

#endif