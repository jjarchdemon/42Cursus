
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = fdf

# Source files
SRCS    = main.c 
OBJS    = $(SRCS:.c=.o)

# Libft
#LIBFT_DIR	= include/libft
#LIBFT		= $(LIBFT_DIR)/libft.a
#LIBFT_INC	= -I$(LIBFT_DIR)

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

all: $(MLX_DIR)/libmlx.a $(NAME)

# Build libft
#$(LIBFT):
#	@echo "Building Libft library..."
#	@$(MAKE) -s -C $(LIBFT_DIR) --no-print-directory >/dev/null 2>&1 || echo "Libft build failed!"

# Compile final executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_LIB) -o $(NAME)

# Compile .c files into .o
%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

# Build MiniLibX if not present
$(MLX_DIR)/libmlx.a:
	@echo "Building MiniLibX library..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1 || echo "MiniLibX build failed!"

# Clean object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

# Clean everything including executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

