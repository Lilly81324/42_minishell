/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:46:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/11 18:31:43 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern void rl_cleanup_after_signal(void);

int	ft_loop(int argc, char *argv[], char *envp[])
{
	char	*input;
	int		status;
	
	if (argc == 2 && argv == NULL)
		return (1);
	while (1)
	{
		input = readline("> ");
		if (input == NULL)
		{
			return (0);
		}
		status = ft_handle_input(input, envp);
		free(input);
		input = NULL;
		if (status != 0)
		{
			return (status);
		}
	}
	return (0);
}
