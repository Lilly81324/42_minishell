/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:27 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/18 17:26:11 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// continously runs through the <token[*pos]> until it reached the end
// ..
// if input has whitespaces -> error, doesnt exist

// wrongfully doesnt split "../miini"
int	ft_builtin_cd(char **tokens, int *pos, char *envp[])
{
	char	*cwd;
	char	**instru;

	(*pos)++;
	if (ft_is_delimiter(tokens[*pos]) == 1)
		return (-1);
	cwd = getcwd(NULL , 0);
	instru = ft_split_quot_ex(tokens[*pos], '/');
	ft_print_tokens(instru);
	ft_nullb(instru);
	ft_null(cwd);
	if (envp == NULL)
		printf("error");
	(*pos)++;
	return (-1);
}
