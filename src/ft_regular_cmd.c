/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regular_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:39 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/14 17:12:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Takes string for command with arguments and execves it
// ex: "echo -n lel" as input string
int	ft_regular_cmd(char **arg, int *pos, char *envp[])
{
	char	*path;
	pid_t	pid;
	char	**argv;
	int		len;

	path = ft_get_path(envp, arg[*pos]);
	if (path == NULL)
	{
		printf(INVALID_COMMAND);
		return (1);
	}
	else
		printf("Command found: %s\n", path);
	argv = ft_prepare_argv(arg, pos);
	pid = fork();
	if (pid < 0)
	{
		printf(FORK_ERROR);
		return (1);
	}
	if (pid == 0)
		execve(path, argv, envp);
	waitpid(pid, NULL, 0);
	ft_nullc(argv);
	ft_null(path);
	len = 0;
	while (ft_is_delimiter(arg[len + (*pos)]) == 0)
		len++;
	printf("Ended command [%s], jumping to %s\n", arg[*pos], arg[(*pos) + len]);
	(*pos) += len;
	return (-1);
}
