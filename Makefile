NAME=push_swap.a

CFLAGS= -Wall -Werror -Wextra

CC= cc

PUSH_SWAP_SRCS =  push_swap.c
# The value of the make variable VPATH specifies a list of directories that make should search.
VPATH = src:lib:lib/libft:lib/ft_printf
# LIBFT 
LIBFT = ./lib/libft/libft.a
LIBFT_DIR = ./lib/libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)

# FT_PRINTF
FT_PRINTF = ./lib/ft_printf/libftprintf.a
FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/$(FT_PRINTF)

# LIBRARY CALL FOR LIBFT AND FT_PRINTF LIBRARIES
LIBR = $(LIBFT_LIB) $(FT_PRINTF_LIB)

# MAKE LIBFT AND FT_PRINTF
# https://www.gnu.org/software/make/manual/make.html#Recursion
MAKE_LIBR = make --no-print-directory -C

PUSH_SWAP_OBJS= $(PUSH_SWAP_SRCS:.c=.o)

RM= rm -f

LB= ar rcs

all:	$(LIBFT_LIB) $(FT_PRINTF_LIB) $(NAME)

$(NAME): $(PUSH_SWAP_OBJS)
	@$(LB) $(NAME) $(PUSH_SWAP_OBJS)
	$(CC) $(NAME) $(LIBFT) $(FT_PRINTF)

$(LIBFT_LIB):
	$(MAKE_LIBR) $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	$(MAKE_LIBR) $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(PUSH_SWAP_OBJS)
	$(MAKE_LIBR) $(LIBFT_DIR) fclean
	$(MAKE_LIBR) $(FT_PRINTF_DIR) fclean

re:	fclean all

.PHONY: all bonus clean fclean re
