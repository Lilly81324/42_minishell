/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:56:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/24 15:45:36 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char **new_env;

	if (argc == 2)
		printf("%s", argv[1]);
	new_env = ft_copy_env(envp);	
	return (ft_loop(&new_env));
}

// TODO:
// Signaling
// Exit Codes
// Argument substitution
// Argument declaration?
// >> and <<
// piping
// Ctrl+C makes newline
// builtins:
// echo with -n flag
// cd
// export
// unset