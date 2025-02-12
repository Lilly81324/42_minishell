/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:46:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 16:27:05 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_loop(char *envp[])
{
	char	*input;
	int		status;

	while (1)
	{
		input = readline("> ");
		if (input == NULL) //Ctrl+D -> should exit
			return (0);
		status = ft_handle_input(input, envp);
		ft_null(input);
		if (status != 0)
			return (status);
	}
	return (0);
}

// CTRL+C -> new line
// CTRL+D -> exit