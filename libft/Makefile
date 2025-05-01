SRC = ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_memcpy ft_memmove ft_memset ft_strlcat ft_strlcpy ft_strlen ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_itoa ft_strmapi ft_striteri ft_split

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

