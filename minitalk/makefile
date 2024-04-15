NAME = client server
NAME_BONUS  = client_bonus server_bonus

UTILS_M = minitalk_helpers.c
UTILS_B = minitalk_helpers_bonus.c
CLIENT_M = client.c
SERVER_M = server.c
CLIENT_B = client_bonus.c
SERVER_B = server_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ./ft_printf/libftprintf.a 

all : $(NAME)

$(NAME): $(UTILS_M) $(CLIENT_M) $(SERVER_M)
	$(CC) $(CFLAGS) $(CLIENT_M) $(UTILS_M) $(LIB) -o client
	$(CC) $(CFLAGS) $(SERVER_M) $(UTILS_M) $(LIB) -o server
	
bonus:$(NAME_BONUS)
	
$(NAME_BONUS): $(UTILS_B) $(CLIENT_B) $(SERVER_B)
	$(CC) $(CFLAGS) $(CLIENT_B) $(UTILS_B) $(LIB) -o client_bonus
	$(CC) $(CFLAGS) $(SERVER_B) $(UTILS_B) $(LIB) -o server_bonus

clean :	
	@$(RM) client server client_bonus server_bonus
fclean : clean
	
re : fclean all

.PHONY : all, clean, fclean, re, bonus
