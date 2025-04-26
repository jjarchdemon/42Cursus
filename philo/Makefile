CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

#sources from object files
SRCS =	blend_color.c //TODO 
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d) #dependencies

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32mPhilosophers compiled successfully!\033[0m"

#Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32mObject files created!\033[0m"

#Generate dependencies
%.d: %.c
	@$(CC) $(CFLAGS) -MM $< -MF $@
	@echo "\033[0;32mDependencies created!\033[0m"

# Include dependencies
-include $(DEPS)

# Clean object files
clean:
	@rm -f $(OBJS) $(DEPS)
	@$(MAKE) clean -s -C $(LIBFT)
	@echo "\033[0;33mObject files & dependencies removed!\033[0m"

fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT)
	@rm -f $(NAME)
	@echo "\033[0;33mCompletely cleaned!\033[0m"

re: fclean all
	@echo "\033[0;33mCleaned & Compiled again!\033[0m"