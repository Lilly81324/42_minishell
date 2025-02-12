/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 16:27:55 by sikunne          ###   ########.fr       */
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

# define INVALID_COMMAND "Not a valid input\n"

// for setup of commands
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
char	**ft_split_quot_ex(char const *s, char c);
char	**ft_prepare_argv(char *inp);

#endif