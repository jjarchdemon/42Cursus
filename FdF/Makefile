# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 10:35:43 by jambatt           #+#    #+#              #
#    Updated: 2025/04/09 14:33:47 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OS = $(shell uname)

SRC_DIR = src
INCLUDE = include

LIBFT = $(INCLUDE)/my_libft

LIBFT_A = $(LIBFT)/libft.a

NAME = fdf


#sources from object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS := $(filter-out  $(SRC_DIR)/alt/%, $(SRCS))  # Exclude the folder
OBJS = $(SRCS:.c=.o)

###################################################################
# Platform-dependent compilation
ifeq ($(OS), Linux)
        LINUX_FLAGS = -L/usr/lib -lGL -lGLU -lX11 -lXext
        MLX = include/minilibx-linux
        MLX_A = include/minilibx-linux/libmlx.a
        INC_FLAGS = -I $(INCLUDE) -I$(INCLUDE)/minilibx-linux
else
        LINUX_FLAGS =  -L/usr/X11/lib -lXext -lX11 \
		       -framework OpenGl -framework Appkit
        MLX = include/mlx_macos
        MLX_A = include/mlx_macos/libmlx.a	
        INC_FLAGS = -I $(INCLUDE) -I$(INCLUDE)/mlx_macos
endif
#####################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) $(LINUX_FLAGS) -lm \
		-o $(NAME)

#compile libft
$(LIBFT_A):
	$(MAKE) -s -C $(LIBFT)

$(MLX_A):
	$(MAKE) -s -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) clean -s -C $(LIBFT)

fclean: clean
	$(MAKE) fclean -s -C $(LIBFT)
	$(MAKE) clean -s -C $(MLX)
	@rm -f $(NAME)

re: fclean all
