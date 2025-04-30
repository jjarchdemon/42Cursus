CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

#sources from object files
SRCS =	debug.c \
		error_handling.c \
		init.c \
		main.c \
		monitor.c \
		more_utils.c \
		parse_input.c \
		routine.c \
		threads.c \
		utils.c
OBJS = $(SRCS:.c=.o)
###############################################################
DEPS = $(SRCS:.c=.d) #dependencies
###############################################################

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32mphilo compiled successfully!\033[0m"

#Compile object files
%.o: %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@
#	@echo "\033[0;32mObject files created!\033[0m"

###############################################################
#Generate dependencies
%.d: %.c
	@$(CC) $(CFLAGS) -MM $< -MF $@
#	@echo "\033[0;32mDependencies created!\033[0m"

# Include dependencies
-include $(DEPS)
###############################################################

# Clean object files
clean:
	@rm -f $(OBJS) $(DEPS)
	@echo "\033[0;33mObject files & dependencies removed!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;33mCompletely cleaned!\033[0m"

re: fclean all
	@echo "\033[0;33mCleaned & Compiled again!\033[0m"