CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -lreadline

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_FILES = \
ft_free_char_arr_arr.c \
ft_get_path.c \
ft_space_bef.c \
ft_get_envp_value.c \
ft_loop.c \
ft_handle_input.c
SRC_MAIN = aa_main.c
OBJ_MAIN = $(SRC_MAIN:%.c=%.o)
OBJ_FILES = $(SRC_FILES:%.c=%.o)

NAME = minishell

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) $(LIBFT_LIB) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) $(OBJ_MAIN) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FILES) $(OBJ_MAIN)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

run:
	valgrind --leak-check=full ./$(NAME)

re: fclean all

PHONY: all clean fclean run re