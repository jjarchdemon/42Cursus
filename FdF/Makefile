# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 10:35:43 by jambatt           #+#    #+#              #
#    Updated: 2025/04/09 16:50:54 by jambatt          ###   ########.fr        #
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
SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS := $(filter-out  $(SRC_DIR)/alt/%, $(SRCS))  # Exclude the folder
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
