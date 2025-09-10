NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = 	src/handle_input.c src/simplify_data.c src/push_swap.c \
			src/rev_rotate_list.c src/rotate_list.c src/swap_nodes.c src/push_nodes.c \
			src/k_sort.c src/helper.c

OBJECTS =	$(SOURCES:.c=.o)

all: $(NAME) $(LIBFT)
$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean: 
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re
