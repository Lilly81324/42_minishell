/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:46:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:35:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Central loop called when input is given
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
		if (status >= 1000)
			return (status);
	}
	return (0);
}

// CTRL+C -> new line
// CTRL+D -> exit