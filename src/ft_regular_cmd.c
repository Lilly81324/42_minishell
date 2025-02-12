/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regular_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 18:19:28 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Takes string for command with arguments and execves it
// ex: "echo -n lel" as input string
int	ft_regular_cmd(char *inp, char *envp[])
{
	char	*path;
	pid_t	pid;
	char	**argv;

	path = ft_get_path(envp, inp);
	if (path == NULL)
	{
		printf(INVALID_COMMAND);
		return (-1);
	}
	else
		printf("Command found: %s\n", path);
	argv = ft_prepare_argv(inp);
	pid = fork();
	if (pid < 0)
	{
		printf(FORK_ERROR);
		return (1);
	}
	if (pid == 0)
		execve(path, argv, envp);
	waitpid(pid, NULL, 0);
	ft_nullb(argv);
	ft_null(path);
	return (-1);
}
