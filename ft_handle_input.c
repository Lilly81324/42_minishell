/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/11 18:36:33 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_input(char *inp, char *envp[])
{
	char *path;

	path = ft_get_path(envp, inp);
	if (path == NULL)
	{
		printf(INVALID_COMMAND);
		return (1);
	}
	else
		printf("Command found: %s\n", path);
	free(path);
	path = NULL;
	return (0);
}
