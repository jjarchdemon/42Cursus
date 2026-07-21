# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jambatt <jambatt@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/21 15:16:10 by jambatt           #+#    #+#              #
#    Updated: 2026/07/21 15:28:59 by jambatt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = megaphone
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

all: $(NAME)
	@echo "compiled successfully"

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "compiled"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "making object files"

clean:
	@$(RM) $(OBJS)
	@echo "removed .o files"

fclean: clean
	@$(RM) $(NAME)
	@echo "removed everything"

re: fclean all
	@echo "recompiled successfully"
