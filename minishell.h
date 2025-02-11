/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:42:19 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/11 18:36:24 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "./libft/libft.h"

# define INVALID_COMMAND "Not a valid input\n"

// for setup of commands
char	*ft_get_path(char **envp, char *cmd);
void	ft_free_char_arr_arr(char **target);
char	*ft_space_bef(char *str);
char 	*ft_get_envp_value(char *envp[], const char *find);
int		ft_loop(int argc, char *argv[], char *envp[]);
char	*ft_check_cmd(char **envp, char *cmd);
int		ft_handle_input(char *inp, char *envp[]);

#endif