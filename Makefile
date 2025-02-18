CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -lreadline

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC_FILES = $(addprefix $(SRC_DIR), \
	ft_get_path.c \
	ft_space_bef.c \
	ft_loop.c \
	ft_handle_input.c \
	ft_null.c \
	ft_nullb.c \
	ft_nullc.c \
	ft_prepare_argv.c \
	ft_special_cmd.c \
	ft_regular_cmd.c \
	ft_check_special.c \
	ft_skip_spaces.c \
	ft_c_in_s.c \
	ft_handle_chunks.c \
	ft_is_delimiter.c \
	ft_token_count.c \
	ft_token_extractor.c \
	ft_tokenization.c \
	ft_redirection.c \
	ft_stdout_to_outfile.c \
	ft_cooler_open.c \
	ft_token_redirect.c \
	ft_token_cmds.c \
	ft_token_skip_chunk.c \
	ft_print_tokens.c \
	ft_dup_std.c \
	ft_reset_std.c \
	ft_stdin_to_infile.c \
	ft_stdout_to_pipe.c \
	ft_stdin_to_pipe.c \
	ft_builtin_env.c \
	ft_make_prompt.c \
)
SRC_MAIN = $(SRC_DIR)aa_main.c
OBJ_MAIN = $(OBJ_DIR)aa_main.o
OBJ_FILES = $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_FILES:%.c=%.o))

NAME = minishell

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) $(LIBFT_LIB) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) $(OBJ_MAIN) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

# Make directory for objects
$(OBJ_DIR):
	mkdir obj

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FILES) $(OBJ_MAIN)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

show:
	echo $(SRC_FILES)
	echo $(OBJ_FILES)

run:
	valgrind --leak-check=full ./$(NAME)

re: fclean all

PHONY: all clean fclean run re