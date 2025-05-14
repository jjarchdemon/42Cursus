NAME = minishell

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS = -lreadline -lncurses
# CFLAGS = -Wall -Wextra -Iinclude -g # <---------------------------------------

# Directories
SRC_DIR = src
INCLUDE_DIR = include

# Source files
SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/debug.c \
		$(SRC_DIR)/get_tokens.c \
		$(SRC_DIR)/libft_utils.c \
		$(SRC_DIR)/linked_list_utils.c \
		$(SRC_DIR)/tokenizer.c \
		$(SRC_DIR)/tokenizer_utils.c \
		$(SRC_DIR)/astree.c \
		$(SRC_DIR)/signals.c

# Header files
HDRS = $(INCLUDE_DIR)/minishell.h

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Rules to build the executables
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

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
