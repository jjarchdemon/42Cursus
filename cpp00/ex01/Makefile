# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/21 15:13:16 by jambatt           #+#    #+#              #
#    Updated: 2026/07/21 15:13:28 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp \
	Contact.cpp \
	Phonebook.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = phonebook
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
