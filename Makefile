CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c validation.c
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I.$(LIBFT_PATH)

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re