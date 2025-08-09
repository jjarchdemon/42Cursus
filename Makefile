# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseph <joseph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 11:10:57 by jambatt           #+#    #+#              #
#    Updated: 2025/08/09 02:18:28 by joseph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

#sources from object files
SRCS =	debug.c \
		init.c \
		main.c \
		monitor.c \
		parse_input.c \
		routine.c \
		threads.c \
		utils_basic.c \
		utils.c
OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32mphilo compiled successfully!\033[0m"

#Compile object files
%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@
#	@echo "\033[0;32mObject files created!\033[0m"

# Clean object files
clean:
	@rm -f $(OBJS)
	@echo "\033[0;33mObject files removed!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;33mCompletely cleaned!\033[0m"

re: fclean all
	@echo "\033[0;33mCleaned & Compiled again!\033[0m"
