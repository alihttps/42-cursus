SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putadd.c ft_putunsigned.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re