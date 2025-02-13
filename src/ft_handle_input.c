/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:52:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/13 18:27:28 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// return values: -1 for continue 0-255 for  
// certain return values should stop the programm and return that value
// -1 if continue
// handles a whole input string, breaks it down into chunks
// and then does all chunks in a specific order
int	ft_handle_input(char *inp, char *envp[])
{
	char **argv;
	int	i;
	int status;

	argv = ft_split_quot_inc(inp);
	if (argv == NULL)
		return (1);
	i = -1;
	while (argv[++i] != NULL)
		printf("{%s}\n", argv[i]);
	i = 0;
	status = ft_handle_chunks(argv, &i, envp);
	ft_nullb(argv);
	return (status);
}

// handle: <, >, >>, |, $x, builtins, commands
// a chunk is delimited by ; && || or | 