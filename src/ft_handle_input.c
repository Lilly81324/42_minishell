/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 15:00:17 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_input(char *inp, char *envp[])
{
	char	*path;
	int		exit_status;

	path = ft_get_path(envp, inp);
	if (path == NULL)
	{
		printf(INVALID_COMMAND);
		return (1);
	}
	else
		printf("Command found: %s\n", path);
	exit_status = ft_prepare_cmd(path, inp, envp);
	ft_null(path);
	return (0);
}
