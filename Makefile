NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = 	handle_input.c simplify_data.c push_swap.c \
			rev_rotate_list.c rotate_list.c swap_nodes.c push_nodes.c \
			k_sort.c

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
