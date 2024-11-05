CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = double_list/clear_double_list.c double_list/double_list.c sorting/algo_helpers.c \
sorting/chunk_sort.c sorting/pre_sort.c sorting/sort_funcs_1.c sorting/sort_funcs_2.c \
sorting/sort_funcs.c validation/validation.c errors_funcs.c main.c
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I./$(LIBFT_PATH)

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
	
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re