# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 10:35:43 by jambatt           #+#    #+#              #
#    Updated: 2025/04/23 11:31:05 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE = include

LIBFT = $(INCLUDE)/my_libft
LIBFT_A = $(LIBFT)/libft.a

NAME = fdf

#sources from object files
SRCS =	$(SRC_DIR)/blend_color.c \
	$(SRC_DIR)/create_data_struct.c \
	$(SRC_DIR)/draw_line.c \
	$(SRC_DIR)/draw_line_update.c \
	$(SRC_DIR)/draw_map.c \
	$(SRC_DIR)/handle_esc_key.c \
	$(SRC_DIR)/load_map_data.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/process_line.c \
	$(SRC_DIR)/process_word.c \
	$(SRC_DIR)/setup_graphics.c \
	$(SRC_DIR)/transform_map.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/utils_close.c \
	$(SRC_DIR)/utils_error.c \
	$(SRC_DIR)/utils_mem.c
OBJS = $(SRCS:.c=.o)

LINUX_FLAGS = -L/usr/lib -lGL -lGLU -lX11 -lXext
MLX = include/minilibx-linux
MLX_A = include/minilibx-linux/libmlx.a
INC_FLAGS = -I $(INCLUDE) -I$(INCLUDE)/minilibx-linux

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) $(LINUX_FLAGS) -lm \
		-o $(NAME)
	@echo "\033[0;32mFdF compiled successfully!\033[0m"

#compile libft
$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "\033[0;32mmy_libft library built successfully!\033[0m"

$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	@echo "\033[0;32mmlx library built successfully!\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -s -C $(LIBFT)
	@echo "\033[0;33mAll object files removed!\033[0m"

fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT)
	@$(MAKE) clean -s -C $(MLX)
	@rm -f $(NAME)
	@echo "\033[0;33mCompletely cleaned!\033[0m"

re: fclean all
	@echo "\033[0;33mCleaned & Compiled again!\033[0m"
