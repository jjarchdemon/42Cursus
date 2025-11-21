# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 16:17:23 by jambatt           #+#    #+#              #
#    Updated: 2024/12/04 16:17:32 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC  = ft_printf.c pick_formatter.c support_functions.c 
OBJ  = $(SRC:.c=.o) 

#default rule
all: $(NAME)

#rule to create static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

#rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean commands
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
