NAME=push_swap.a
CHECK=checker.a

CFLAGS= -Wall -Werror -Wextra

CC= cc

PUSH_SWAP_SRCS =  push_swap.c push_swap_utils_a.c push_swap_utils_b.c push_swap_init.c push_swap_tab.c push_swap_sort.c\
					push_swap_sort_forward.c push_swap_sort_backward.c push_swap_sort_accessory.c

CHECK_SRCS = checker.c push_swap_utils_a.c push_swap_utils_b.c push_swap_init.c push_swap_tab.c push_swap_sort.c\
					push_swap_sort_forward.c push_swap_sort_backward.c push_swap_sort_accessory.c
# The value of the make variable VPATH specifies a list of directories that make should search.
VPATH = src:check:lib:lib/libft
# LIBFT
LIBFT = ./lib/libft/libft.a
LIBFT_DIR = ./lib/libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)

# # FT_PRINTF
# FT_PRINTF = ./lib/ft_printf/libftprintf.a
# FT_PRINTF_DIR = ./lib/ft_printf
# FT_PRINTF_LIB = $(FT_PRINTF_DIR)/$(FT_PRINTF)

# # FT_PRINTF
# GNL = ./lib/get_next_line/getnextline.a
# GNL_DIR = ./lib/get_next_line
# GNL_LIB = $(GNL_DIR)/$(GNL)

# LIBRARY CALL FOR LIBFT AND FT_PRINTF LIBRARIES AND GNL
LIBR = $(LIBFT_LIB) 
# $(FT_PRINTF_LIB) $(GNL_LIB)

# MAKE LIBFT AND FT_PRINTF AND GNLßßß
# https://www.gnu.org/software/make/manual/make.html#Recursion
MAKE_LIBR = make --no-print-directory -C

PUSH_SWAP_OBJS= $(PUSH_SWAP_SRCS:.c=.o)
CHECK_OBJS= $(CHECK_SRCS:.c=.o)

RM= rm -f

LB= ar rcs

# all:	$(LIBFT_LIB) $(FT_PRINTF_LIB) $(GNL_LIB) $(NAME)
all:	$(LIBFT_LIB) $(NAME)

bonus: $(CHECK)

$(NAME): $(PUSH_SWAP_OBJS)
	@$(LB) $(NAME) $(PUSH_SWAP_OBJS)
	$(CC) $(NAME) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(GNL) -o push_swap

$(CHECK): $(CHECK_OBJS)
	$(CC) $(CFLAGS) $(CHECK_OBJS) $(LIBFT) -o checker

$(LIBFT_LIB):
	$(MAKE_LIBR) $(LIBFT_DIR)

# $(FT_PRINTF_LIB):
# 	$(MAKE_LIBR) $(FT_PRINTF_DIR)

# $(GNL_LIB):
# 	$(MAKE_LIBR) $(GNL_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJS)
	$(RM) $(CHECK_OBJS)

fclean: clean
	$(RM) $(NAME) $(PUSH_SWAP_OBJS)
	$(RM) $(CHECK) $(CHECK_OBJS)
	$(MAKE_LIBR) $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all bonus clean fclean re
