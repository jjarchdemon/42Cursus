# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 16:17:23 by jambatt           #+#    #+#              #
#    Updated: 2025/11/22 12:16:02 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
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
