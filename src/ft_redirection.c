/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:52:10 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:04:24 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// handles redirections and increases the position accordingly
int	ft_redirection(char **argv, int pos, char *envp[])
{
	if (argv[pos][0] == '>' && argv[pos][1] == '\0')
		ft_stdout_to_outfile(argv[pos + 1], envp);
	else if (argv[pos][0] == '<' && argv[pos][1] == '\0')
		ft_stdin_to_infile(argv[pos + 1]);
	return (-1);
}
