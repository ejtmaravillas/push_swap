#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

// stack_list --> inside the stack --> linked list for each element
// stack_list *next --> for the next element;
// stack_list *prev --> for the previous element;
typedef struct stack_list
{
	void *value;
	struct stack_list *next;
	struct stack_list *prev;
}	t_stacklist;

// stack_info --> necessary info for stack a and stack b
// stack --> int pointer for the stack values
// size --> number of elements for stack a and b
// first --> first value of stack
// last --> last value of stack
typedef struct stack_info
{
	int *stack;
	int size;
	int first;
	int last;
}	t_stackinfo;

typedef struct stack_push_swap
{
	t_stackinfo a;
	t_stackinfo b;
	t_list *stacklist;
}	t_stack;


char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *arg);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *dst, int c, size_t length);
int		count_elements(char **s);
void 	data_init(t_stack *data, int argc, char **argv);
void 	stack_init(t_stack *data, t_stackinfo *stk, int size);
void 	error(t_stack *data);
void 	free_stack(t_stack *data);
void 	stack_fill(t_stack *data, t_stackinfo *stk, int size, char **argv);
bool 	check_arg(char *arg);
void 	check_duplicate(t_stack *data, int *stack_num, int size);
void 	stack_tabulate(int *stack_num, int *stack, int size);

#endif