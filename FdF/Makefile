
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
NAME    = fdf

# Source files
SRCS    = src/main.c  \
			src/parsing.c \
			utils/utils_init.c \
			utils/utils_deinit.c \
			utils/utils_close.c \
			utils/utils_mlx.c \
			debug/debug.c \
			include/get_next_line/get_next_line.c \
			include/get_next_line/get_next_line_utils.c
OBJS    = $(SRCS:.c=.o)

# --- ft_printf ---
PRINTF_DIR  = include/ft_printf
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC  = -I$(PRINTF_DIR)

# Libft
LIBFT_DIR	= include/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_INC	= -I$(LIBFT_DIR)

# Get Next Line
GNL_INC = -Iinclude/get_next_line

# Detect platform
UNAME_S	:= $(shell uname -s)

# MiniLibX settings based on platform
ifeq ($(UNAME_S),Linux)
	MLX_DIR = include/minilibx-linux
	MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else ifeq ($(UNAME_S),Darwin)
	MLX_DIR = include/minilibx-mac
	MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

MLX_INC = -I$(MLX_DIR)

all: $(MLX_DIR)/libmlx.a $(PRINTF_LIB) $(LIBFT) $(NAME)

# Build libft
$(LIBFT):
	@echo "Building Libft library..."
	@$(MAKE) -s -C $(LIBFT_DIR) 

# Build ft_printf
$(PRINTF_LIB):
	@echo "Building ft_printf..."
	@$(MAKE) -C $(PRINTF_DIR)

# Compile final executable
$(NAME): $(OBJS) $(PRINTF_LIB) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF_LIB) $(MLX_LIB) -o $(NAME)

# Compile .c files into .o
%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) $(MLX_INC) $(PRINTF_INC) $(GNL_INC) -c $< -o $@

# Build MiniLibX if not present
$(MLX_DIR)/libmlx.a:
	@echo "Building MiniLibX library..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1 || echo "MiniLibX build failed!"

# Clean object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean >/dev/null 2>&1 || true
	@$(MAKE) -C $(MLX_DIR) clean >/dev/null 2>&1 || true
	@$(MAKE) -C $(PRINTF_DIR) clean >/dev/null 2>&1 || true
	@echo "Clean: objects and libraries cleaned"

# Clean everything including executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory >/dev/null 2>&1 || true
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory >/dev/null 2>&1 || true
	@echo "Clean: everything cleaned"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
