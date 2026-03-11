# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 16:26:36 by jambatt           #+#    #+#              #
#    Updated: 2026/01/26 12:58:53 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = Zombie
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all