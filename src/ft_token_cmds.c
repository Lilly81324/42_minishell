/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:26:44 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:02:20 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_token_cmds(char *arg[], int i, char *envp[])
{
	int	status;

	while (arg[i] != NULL && arg[i][0] != '|' && arg[i][0] != ';')
	{
		if (ft_is_delimiter(arg[i]) == 1)
			i += 2;
		else
		{
			if (ft_check_special(arg[i]) == 1)
				status = ft_special_cmd(arg, &i);
			else
				status = ft_regular_cmd(arg, &i, envp);
			if (status != -1)
				return (status);
		}
	}
	return (-1);
}
