/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/14 17:31:38 by sikunne          ###   ########.fr       */
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

# define INVALID_COMMAND "LILSHELL: Not a valid command\n"
# define FORK_ERROR "LILSHELL: Error creating fork\n"

// Used in ft_split_quot_int to know what to skip over
# define SPACES " \n\t\v\f\r"
# define SPECIALS "><;|"

char	*ft_get_path(char **envp, char *cmd);
char	*ft_space_bef(char *str);
char	*ft_get_envp_value(char *envp[], const char *find);
int		ft_loop(char *envp[]);
int		ft_handle_input(char *inp, char *envp[]);
void	ft_null(void *ptr);
void	ft_nullb(char **ptr);
void	ft_nullc(char **ptr);
char	**ft_prepare_argv(char **arg, int *pos);
int		ft_regular_cmd(char **arg, int *pos, char *envp[]);
int		ft_special_cmd(char *inp);
int		ft_check_special(char *inp);
void	ft_skip_spaces(int *i, char *str);
int		ft_c_in_s(char *big, char little);
int		ft_handle_chunks(char *arg[], int *ri, char *envp[]);
int		ft_is_delimiter(char *str);
int		ft_token_count(char *s);
void	ft_token_extractor(char *s, char **result);
char	**ft_tokenization(char *s);

// Variables in double quotes have to be interpreted,
// Things in single quotes are ALWAYS taken literally
// Dont need to add \ handling

// Right now the first pair of quotes is taken away 
// and the rest is given to execve

// Builtins such as cd, unset or export run in parent process
// otherwise every other command runs as child

// Every chunk like redirection has different amount of blocks it needs,
// The current position needst to be increased accordingly

#endif