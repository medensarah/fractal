GREEN = \033[0;38;2;142;194;121;49m
LIGHTGREEN = \033[0;38;2;142;255;105;49m
YELLOW = \033[0;93m
LIGHTYELLOW = \033[1;33m
PINK = \033[0;38;2;255;206;248;49m
PURPLE = \033[0;38;2;194;170;242;49m
NONE = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = fractol
OBJDIR = obj
MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/printf.a

SRCS = main.c init.c
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

all: $(PRINTF) $(NAME)

$(PRINTF):
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR)
	@echo "$(LIGHTGREEN)Library printf ready$(NONE)"

$(NAME): $(OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(MLX) -o $(NAME)
	@echo "$(PINK)Build complete (./$(NAME))$(NONE)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling $<$(NONE)"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR) clean
	@echo "$(YELLOW)Cleaned objects$(NONE)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR) fclean
	@echo "$(LIGHTYELLOW)Cleaned all$(NONE)"

re: fclean all
	@echo "$(PURPLE)Rebuild complete$(NONE)"

.PHONY: all clean fclean re

# # Compiler and Flags
# CC      = cc
# CFLAGS  = -Wall -Wextra -Werror -g3

# # Project name
# NAME    = fractol

# # Folders
# SRC_DIR = src
# OBJ_DIR = obj
# MLX     = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# # Source and Object Files
# SRC_FILES = main.c \
# 			init.c

# SRC      = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
# OBJS     = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# # Default target
# all: $(NAME)

# # Final link step
# $(NAME): $(OBJS)
# 	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
# 	@echo "✅ Build complete: $(NAME)"

# # Rule to compile .c to .o into obj/
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@echo "Compiled $< -> $@"

# # Clean object files
# clean:
# 	@rm -rf $(OBJ_DIR)
# 	@echo "🧹 Cleaned object files."

# # Clean everything
# fclean: clean
# 	@rm -f $(NAME)
# 	@echo "🧼 Full clean (including executable)."

# # Recompile
# re: fclean all

# .PHONY: all clean fclean re
