
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = fdf

# Source files
SRCS    = main.c 
OBJS    = $(SRCS:.c=.o)

# MiniLibX
MLX_DIR = include/minilibx-mac
MLX_INC = -I$(MLX_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

#------------------------------------------

all: $(MLX_DIR)/libmlx.a $(NAME)

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

