/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:09:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 17:45:21 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_prepare_argv(char *inp)
{
	int		i;
	char	**ret;

	i = -1;
	ret = ft_split_quot_ex(inp, ' ');
	while (ret[++i] != NULL)
		printf("ARG: %s\n", ret[i]);
	return (ret);
}
