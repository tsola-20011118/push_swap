CFLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = push_swap

# OBJS = push_swap.o push_swap_tool.o algorithm.o algorithm_rotate.o algorithm_tool.o lst_operation.o \
# 		process.o
OBJS = push_swap.o push_swap_tool.o algorithm.o algorithm_rotate.o algorithm_tool.o lst_operation.o \
		process.o printf.o printf_libft.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o push_swap

clean:
	-$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re