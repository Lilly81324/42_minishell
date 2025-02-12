/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envp_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:05:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 16:26:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns part of envp variable starting with <find>
// returns NULL if not found
char	*ft_get_envp_value(char *envp[], const char *find)
{
	size_t	len;
	int		i;

	len = ft_strlen(find);
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], find, len) != 0)
			return (envp[i] + len);
		i++;
	}
	return (envp[i]);
}
