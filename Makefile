# Compiler and Flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3

# Project name
NAME    = fractal

# Folders
SRC_DIR = src
OBJ_DIR = obj
MLX     = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# Source and Object Files
SRC_FILES = main.c \
			init.c

SRC      = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS     = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Default target
all: $(NAME)

# Final link step
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo "✅ Build complete: $(NAME)"

# Rule to compile .c to .o into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< -> $@"

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Cleaned object files."

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "🧼 Full clean (including executable)."

# Recompile
re: fclean all

.PHONY: all clean fclean re
