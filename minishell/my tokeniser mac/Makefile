NAME = minishell

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS = -lreadline
# CFLAGS = -Wall -Wextra -Iinclude -g # <---------------------------------------

# Directories
SRC_DIR = src
INCLUDE_DIR = include

# various directories
SRC_TOKENISER_DIR =	$(SRC_DIR)/tokeniser
#SRC_EXPANDER_DIR =	$(SRC_DIR)/expander

# Source files for tokeniser
SRC_TOKENISER =	$(SRC_TOKENISER_DIR)/get_tokens.c \
				$(SRC_TOKENISER_DIR)/libft_utils.c \
				$(SRC_TOKENISER_DIR)/linked_list_utils.c \
				$(SRC_TOKENISER_DIR)/token_type.c \
				$(SRC_TOKENISER_DIR)/tokenizer_utils.c \
				$(SRC_TOKENISER_DIR)/tokenizer.c \

#SRC_EXPANDER = $(SRC_EXPANDER_DIR)/expander.c

# Source files
SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/debug.c \
		$(SRC_TOKENISER)
#		$(SRC_EXPANDER)

# Header files
HDRS = $(INCLUDE_DIR)/minishell.h

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Rules to build the executables
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Object files depend on their respective source files
$(OBJS): %.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all bonus clean fclean re
