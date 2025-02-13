/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/13 18:08:24 by sikunne          ###   ########.fr       */
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

char	*ft_get_path(char **envp, char *cmd);
void	ft_free_char_arr_arr(char **target);
char	*ft_space_bef(char *str);
char	*ft_get_envp_value(char *envp[], const char *find);
int		ft_loop(char *envp[]);
char	*ft_check_cmd(char **envp, char *cmd);
int		ft_handle_input(char *inp, char *envp[]);
int		ft_prepare_cmd(char *path, char *inp, char *envp[]);
void	ft_null(void *ptr);
void	ft_nullb(char **ptr);
char	**ft_split_quot_inc(char *s);
char	**ft_prepare_argv(char *inp);
int		ft_regular_cmd(char *inp, char *envp[]);
int		ft_special_cmd(char *inp);
int		ft_check_special(char *inp);
void	ft_skip_spaces(int *i, char *str);
void	ft_skip_not_spaces(int *i, char *str);
int		ft_c_in_s(char *big, char little);
int		ft_handle_chunks(char *arg[], int *ri, char *envp[]);

// Variables in double quotes have to be interpreted,
// Things in single quotes are ALWAYS taken literally
// Dont need to add \ handling

// Right now the first pair of quotes is taken away 
// and the rest is given to execve

// Builtins such as cd, unset or export run in parent process
// otherwise every other command runs as child

#endif