CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main.c validation/validation.c validation/helpers_validation.c sorting/sort_funcs.c \
sorting/sort_funcs_1.c sorting/sort_funcs_2.c sorting/algorithms_call.c
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I$(LIBFT_PATH)

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