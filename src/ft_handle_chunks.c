/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:48:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/14 17:18:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// called on each token to run it
// return values:
// -1 for continue doing the line
// 0-255 for stop the current the line
// 1000-1255 for stop whole programm
int	ft_handle_chunks(char *arg[], int *i, char *envp[])
{
	int	special;

	special = ft_check_special(arg[*i]);
	if (special == 1)
	{
		printf("Special Command\n");
		(*i)++;
		// Not working with pos properly right now
		return (ft_special_cmd(arg[(*i) -1]));
	}
	else
	{
		printf("Regular command\n");
		return (ft_regular_cmd(arg, i, envp));
	}
	return (-1);
}

	// int	special;
	// while
	// special = ft_check_special(arg[0]);
	// if (special == 1)
	// 	return (ft_special_cmd(arg[0]));
	// else
	// 	return (ft_regular_cmd(arg[0], envp));