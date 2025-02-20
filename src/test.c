/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/20 17:36:18 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redo_pwd(char ***envp)
{
	int		i;
	char	*new_str;

	i = 0;
	while ((*envp)[i] != NULL && ((*envp)[i][0] != 'P' || (*envp)[i][1] != 'W' || (*envp)[i][2] != 'D'))
		i++;
	if ((*envp)[i] == NULL)
		return ;
	printf("PWD found at %i\n%s\n", i, (*envp)[i]);
	new_str = (char *)malloc(4 * (sizeof(char)));
	new_str[0] = 'A';
	new_str[1] = 'b';
	new_str[2] = 'C';
	new_str[3] = '\0';
	free((*envp)[i]);
	(*envp)[i] = new_str;
}

int	main(int argc, char *argv[], char *env[])
{
	char	*string;
	char	**new_env;

	if (argc == 1 || argv[0] == NULL)
		return (0);
	string = getenv("PWD");
	printf("PWD=%s\n", string);
	ft_redo_pwd(&env);
	string = getenv("PWD");
	printf("PWD=%s\n", string);
	return (0);
}
