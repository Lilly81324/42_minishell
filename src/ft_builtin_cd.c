/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:27 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/20 16:24:18 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// change directory by reassigning cwd with /<goal> at the end
// or just <goal> if we are at cwd = "/"
// get length of cwd and goal and reassign that much space to new cwd
// use copy to fill in the old contents of cwd into the new cwd
static int	ft_new_dir(char **cwd, char *goal)
{
	int		len_cwd;
	int		len_goal;
	char	*copy;

	len_cwd = ft_strlen(*cwd);
	if ((*cwd)[0] == '/' && (*cwd)[1] == '\0')
		len_cwd--;
	len_goal = ft_strlen(goal);
	copy = ft_strdup((*cwd));
	free(*cwd);
	(*cwd) = (char *)malloc((len_cwd + len_goal + 2) * sizeof(char));
	(*cwd)[len_cwd + len_goal + 1] = '\0';
	len_goal++;
	while(--len_goal > 0)
		(*cwd)[len_cwd + len_goal] = goal[len_goal - 1];
	(*cwd)[len_cwd + len_goal] = '/';
	len_cwd++;
	while(--len_cwd > 0)
		(*cwd)[len_cwd - 1] = copy[len_cwd -1];
	ft_null(copy);
	return (-1);
}

// Changes directory based off of relative descriptors
// such as: "../same_dir" or "new_dir" or "../../../../../home"
// Uses 2d array of tokens divided
static int	ft_rel_directory(char *target, char **envp)
{
	int		i;
	char	**inst;
	char	*cwd;

	if (envp == NULL)
		return (9999999);
	i = -1;
	inst = ft_split_quot_ex(target, '/');
	cwd = getcwd(NULL , 0);
	while (inst[++i] != NULL)
	{
		printf("Handling instruction: [%s]\n", inst[i]);
		ft_new_dir(&cwd, inst[i]);
	}
	printf("Final directory to change to is %s\n", cwd);
	ft_nullb(inst);
	i = chdir(cwd);
	ft_null(cwd);
	return (i);
}

// continously runs through the <token[*pos]> until it reached the end
// ..
// if input has whitespaces -> error, doesnt exist
// ERROR Can only handle relative paths (../folder), not absolute pahts (/home/sikunne/Desktop)
// need to add a check for wether the first parth of the input is a /
int	ft_builtin_cd(char **tokens, int *pos, char *envp[])
{
	int		status;

	(*pos)++;
	if (ft_is_delimiter(tokens[*pos]) == 1)
		return (-1);
	if (tokens[*pos][0] == '/')
		status = chdir(tokens[*pos]);
	else
		status = ft_rel_directory(tokens[*pos], envp);
	printf("Status:%i\n", status);
	if (status == 0)
	{
		printf("Succesfully changed directory\n");
		status = -1;
	}
	else
	{
		printf("Failed to change directory\n");
		status = 2;
	}
	(*pos)++;
	if (envp == NULL)
		printf("error");
	return (status);
}
