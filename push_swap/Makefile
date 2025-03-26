# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 17:14:29 by jambatt           #+#    #+#              #
#    Updated: 2025/03/25 17:14:40 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE = include

LIBFT = $(INCLUDE)/my_libft
LIBFT_A = $(LIBFT)/libft.a

NAME = push_swap

#sources from object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "\033[0;32mpush_swap compiled successfully!\033[0m"

#compile libft
$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "\033[0;32mmy_libft library built successfully!\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -s -C $(LIBFT)
	@echo "\033[0;33mAll object files removed!\033[0m"

fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT)
	@rm -f $(NAME)
	@echo "\033[0;33mAll exe and object files removed!\033[0m"

# Rebuild everything
re: fclean all

# PHONY targets
.PHONY: all clean fclean re
