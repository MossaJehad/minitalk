CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_PATH = build/
LIBFT_PATH = libft

CFLAGS += -I$(LIBFT_PATH)

LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

NAME_SERVER = server
NAME_CLIENT = client

SRC_S = server.c serverclean.c
SRC_C = client.c

OBJ_S = $(addprefix $(OBJ_PATH), $(SRC_S:.c=.o))
OBJ_C = $(addprefix $(OBJ_PATH), $(SRC_C:.c=.o))

HEADERS = minitalk.h $(LIBFT_PATH)/libft.h

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_S) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_S) $(LIBFT_FLAGS)

$(NAME_CLIENT): $(OBJ_C) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBFT_FLAGS)

$(OBJ_PATH)%.o: %.c $(HEADERS) | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re