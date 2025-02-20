/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/20 14:38:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	func(char *str)
{
	int	i;

	free(str);
	str = (char *)malloc(10 * sizeof(char));
	i = -1;
	while (++i < 9)
		str[i] = 'b';
	str[9] = '\0'
}

int	main(int argc, char *argv[])
{
	char	*string;

	string = (char *)malloc(2 * sizeof(char));
	string[0] = 'a';
	string[1] = '\0';
	func(string);
	printf("%s\n", string);
	free(string);
	return (0);
}
