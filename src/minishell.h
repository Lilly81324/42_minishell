/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/18 16:02:41 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "../libft/libft.h"

// Error messages
# define INVALID_COMMAND "lilshell: Not a valid command\n"
# define FORK_ERROR "lilshell: Error creating fork\n"

// Used in ft_tokenization to know what to skip over
# define SPACES " \n\t\v\f\r"
# define SPECIALS "><;|"

// Used for showing the prompt before readline like this:
// <PROMPT><PWD><POST_PROMPT>
// example:
// PROMPT="lilshell:"	POST_PROMPT=">"
// lilshell:/home/sikunne>
# define PROMPT "lilshell>"
# define POST_PROMPT "> "

// Utility-------------------------------------------------
char	*ft_get_path(char *cmd);
char	*ft_space_bef(char *str);
void	ft_null(void *ptr);
void	ft_nullb(char **ptr);
void	ft_nullc(char **ptr);
void	ft_skip_spaces(int *i, char *str);
int		ft_c_in_s(char *big, char little);
int		ft_cooler_open(char *filename);
int		ft_is_delimiter(char *str);
// Redirection
int		ft_stdout_to_outfile(char *filename);
int		ft_stdout_to_pipe(void);
int		ft_stdin_to_infile(char *filename);
int		ft_stdin_to_pipe(int r_end);
void	ft_dup_std(int *std);
void	ft_reset_std(int *std);
// Debugging
void	ft_print_tokens(char **tokens);

// Programm------------------------------------------------
int		ft_loop(char *envp[]);
// Input getting
char	*ft_make_prompt(void);
int		ft_handle_input(char *inp, char *envp[]);
// Tokenize input
int		ft_token_count(char *s);
void	ft_token_extractor(char *s, char **result);
char	**ft_tokenization(char *s);
// Executing the input
int		ft_handle_chunks(char *arg[], int *ri, char *envp[]);
// Redirecting
int		ft_token_redirect(char *arg[], int i);
int		ft_redirection(char **argv, int pos);
// Commands
int		ft_token_cmds(char *arg[], int i, char *envp[]);
// Builtin command
int		ft_check_special(char *inp);
int		ft_special_cmd(char **tokens, int *pos, char *envp[]);
int		ft_builtin_env(int *pos, char *envp[]);
// Basic command or rest
int		ft_regular_cmd(char **arg, int *pos);
char	**ft_prepare_argv(char **arg, int *pos);
// End of executing input
void	ft_token_skip_chunk(char *arg[], int *i);


// Builtins such as cd, unset or export run in parent process
// otherwise every other command runs as child

// Every chunk like redirection has different amount of blocks it needs,
// The current position needst to be increased accordingly

// I used continue instead of return, are we allowed to use that?

#endif