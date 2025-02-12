/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:59:40 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 16:17:13 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_prepare_cmd(char *path, char *inp, char *envp[])
{
	pid_t	pid;
	char	**argv;

	argv = ft_prepare_argv(inp);
	pid = fork();
	if (pid < 0)
	{
		perror("Error creating fork\n");
		return (-1);
	}
	if (pid == 0)
		execve(path, argv, envp);
	ft_nullb(argv);
	waitpid(pid, NULL, 0);
	return (0);
}
