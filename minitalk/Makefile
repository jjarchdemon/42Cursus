# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 10:22:10 by jambatt           #+#    #+#              #
#    Updated: 2025/02/24 11:05:33 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

#default rule/goal
all: server client

#link the object files to create executables
server: server.o
	$(CC) $(CFLAGS) $^ -o $@

client: client.o
	$(CC) $(CFLAGS) $^ -o $@

#compile the .o files
server.o : server.c
	$(CC) $(CFLAGS) -c $< -o $@

client.o : client.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f server client

re: fclean all


.PHONY: clean fclean re
