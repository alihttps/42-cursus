SRCS = \
	check_input_utils.c \
	check_input_utils2.c \
	init_stack_a.c \
	is_stack_sorted.c \
	rotate.c \
	stack_utils.c \
	turk_algo.c \
	check_input.c \
	init_stack_b.c \
	main.c \
	ft_split.c \
	ft_join.c \
	push.c \
	reverse_rotate.c \
	stack_utils2.c \
	swap.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = cc

NAME = push_swap

GREEN = \033[32m

RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC)  $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation done.$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
