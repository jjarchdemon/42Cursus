NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. 

SRCS =		libft/ft_atoi.c \
                libft/ft_bzero.c \
                libft/ft_calloc.c \
                libft/ft_isalnum.c \
                libft/ft_isalpha.c \
                libft/ft_isascii.c \
                libft/ft_isdigit.c \
                libft/ft_isprint.c \
                libft/ft_itoa.c \
                libft/ft_memchr.c \
                libft/ft_memcmp.c \
                libft/ft_memcpy.c \
                libft/ft_memmove.c \
                libft/ft_memset.c \
                libft/ft_putchar_fd.c \
                libft/ft_putendl_fd.c \
                libft/ft_putnbr_fd.c \
                libft/ft_putstr_fd.c \
                libft/ft_split.c \
                libft/ft_strchr.c \
                libft/ft_strdup.c \
                libft/ft_striteri.c \
                libft/ft_strjoin.c \
                libft/ft_strlcat.c \
                libft/ft_strlcpy.c \
             	libft/ft_strlen.c \
                libft/ft_strmapi.c \
                libft/ft_strncmp.c \
                libft/ft_strnstr.c \
                libft/ft_strrchr.c \
                libft/ft_strtrim.c \
                libft/ft_substr.c \
                libft/ft_tolower.c \
                libft/ft_toupper.c

OBJS = $(SRCS:.c=.o)

# Path to the ft_printf library
PRINTF_SRCS = 	ft_printf/support_functions.c \
		ft_printf/pick_formatter.c \
		ft_printf/ft_printf.c

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
#get next line srcs
GNL_SRCS = 	get_next_line/get_next_line.c

GNL_OBJS = $(GNL_SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@ar -rcs $(NAME) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
