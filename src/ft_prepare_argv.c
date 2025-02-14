/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:09:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/14 16:58:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_copy_argv(char **o_argv, int start, int len)
{
	char	**n_argv;
	int		i;

	printf("Making new argv from %s to %s\n", o_argv[start], o_argv[start + len]);
	n_argv = (char **)malloc((len + 1) * sizeof (char *));
	i = -1;
	while(++i < len)
	{
		printf("Copying %s from %i to %i\n", o_argv[i + start], i + start, i);
		n_argv[i] = o_argv[i + start];
	}
	printf("Setting %i to NULL\n", i);
	n_argv[i] = NULL;
	return (n_argv);
}

// creates a heap copy of the given string of arguments
// starting at arg[*pos] and going until an argument is < > << >> or |
char	**ft_prepare_argv(char **arg, int *pos)
{
	int		len;
	char	**ret;

	len = 0;
	while (ft_is_delimiter(arg[len + (*pos)]) == 0)
		len++;
	printf("Length of argv is %i\n", len);
	ret = ft_copy_argv(arg, *pos, len);
	return (ret);
}
