# NAME = fractol
# SRCS = fractol_connection.c \
#        fractol_events.c \
#        fractol_math.c \
#        fractol_render.c \
#        fractol_utils.c \
#        main.c

# OBJS_DIR = objs/
# OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

# BONUS_SRCS = bonus/fractol_connection_bonus.c \
#              bonus/fractol_events_bonus.c \
#              bonus/fractol_math_bonus.c \
#              bonus/fractol_render_bonus.c \
#              bonus/fractol_utils_bonus.c \
#              bonus/main_bonus.c
# BONUS_OBJS = $(addprefix $(OBJS_DIR), $(notdir $(BONUS_SRCS:.c=.o)))

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# LDFLAGS = -lmlx -framework OpenGL -framework AppKit

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
# 	@echo "Compilation done."

# $(OBJS_DIR)%.o: bonus/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJS_DIR)%.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# bonus: $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LDFLAGS) -o $(NAME)_bonus
# 	@echo "Bonus compilation done."

# clean:
# 	@$(RM) $(OBJS) $(BONUS_OBJS)

# fclean: clean
# 	@$(RM) $(NAME) $(NAME)_bonus

# re: fclean all

# .PHONY: all bonus clean fclean re


NAME = fractol
NAME_BONUS = fractol_bonus
SRCS = fractol_connection.c \
       fractol_events.c \
       fractol_math.c \
       fractol_render.c \
       fractol_utils.c \
       main.c

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

BONUS_SRCS = bonus/fractol_connection_bonus.c \
             bonus/fractol_events_bonus.c \
             bonus/fractol_math_bonus.c \
             bonus/fractol_render_bonus.c \
             bonus/fractol_utils_bonus.c \
             bonus/main_bonus.c
BONUS_OBJS = $(addprefix $(OBJS_DIR), $(notdir $(BONUS_SRCS:.c=.o)))

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Compilation done."

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LDFLAGS) -o $(NAME_BONUS)
	@echo "Bonus compilation done."

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME) $(NAME)_bonus

re: fclean all

.PHONY: all bonus clean fclean re
.SECONDARY: $(BONUS_OBJS) $(OBJS)



