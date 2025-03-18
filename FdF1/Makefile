# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 10:35:43 by jambatt           #+#    #+#              #
#    Updated: 2025/03/18 10:48:25 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -I $(INCLUDE) -I$(INCLUDE)/minilibx-linux

SRC_DIR = src
INCLUDE = include

LIBFT = $(INCLUDE)/my_libft
MLX = $(INCLUDE)/minilibx-linux

LIBFT_A = $(LIBFT)/libft.a
MLX_A = $(MLX)/libmlx.a

#how to get gnl and printf srcs separately

NAME = fdf

LINUX_FLAGS = -L/usr/lib -lGL -lGLU -lX11 -lXext

#sources from object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) $(LINUX_FLAGS) -lm \
		-o $(NAME)

#compile libft
$(LIBFT_A):
	$(MAKE) -s -C $(LIBFT)

$(MLX_A):
	$(MAKE) -s -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) clean -s -C $(LIBFT)

fclean: clean
	$(MAKE) fclean -s -C $(LIBFT)
	$(MAKE) clean -s -C $(MLX)
	@rm -f $(NAME)

re: fclean all
