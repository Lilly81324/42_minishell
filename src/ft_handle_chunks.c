/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:48:42 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/13 18:29:32 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// starts handling all the args in a certain order
// moves from arg[i] to the next pipe argument or end
// sets <ri> (real i) to the value of whatever arg is after the pipe
// or the arg that is null
// arguments are checked for Argument substitution
// then for piping
// then for commands
int	ft_handle_chunks(char *arg[], int *ri, char *envp[])
{
	int	i;
	int	special;

	i = (*ri) - 1;
	while (arg[++i] != NULL)
	{//find variable assignement
		if (1 == 2)
		{//variable assignement found -> start going trough again and replace the variable with its value
			printf("how?\n");
		}
	}
	i = (*ri) - 1;
	while (arg[++i] != NULL)
	{//run commands
		special = ft_check_special(arg[i]);
		if (special == 1)
		{
			printf("Special Command\n");
			return (ft_special_cmd(arg[i]));
		}
		else
		{
			printf("Regular command\n");
			return (ft_regular_cmd(arg[i], envp));
		}
	}
	*ri = i;
	return (-1);
}

	// int	special;
	// while
	// special = ft_check_special(arg[0]);
	// if (special == 1)
	// 	return (ft_special_cmd(arg[0]));
	// else
	// 	return (ft_regular_cmd(arg[0], envp));