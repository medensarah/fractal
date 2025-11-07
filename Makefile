GREEN = \033[0;38;2;142;194;121;49m
LIGHTGREEN = \033[0;38;2;142;255;105;49m
YELLOW = \033[0;93m
LIGHTYELLOW = \033[1;33m
PINK = \033[0;38;2;255;206;248;49m
PURPLE = \033[0;38;2;194;170;242;49m
NONE = \033[0m

CC = cc
CFLAGS = -Wall -Wextra

NAME = fractol
OBJDIR = obj
MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

SRCS = src/main.c \
		src/init.c \
		src/maths.c \
		src/graphics.c \
		src/parsing.c \
		src/hook.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo "$(PINK)Build complete (./$(NAME))$(NONE)"

# crée tous les dossiers nécessaires (ex : obj/src/)
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling $<$(NONE)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)Cleaned objects$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(LIGHTYELLOW)Cleaned all$(NONE)"

re: fclean all
	@echo "$(PURPLE)Rebuild complete$(NONE)"

.PHONY: all clean fclean re
