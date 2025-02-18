/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:10:22 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/18 17:17:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int argc, char **argv)
{
	char	**tokens;
	int		i;

	if (argc == 1)
		return (0);
	i = -1;
	tokens = ft_split_quot_inc(argv[1], '/');
	while (tokens[++i] != NULL)
	{
		printf("%s\n", tokens[i]);
		free(tokens[i]);
	}
	free(tokens);
	return (0);
}
