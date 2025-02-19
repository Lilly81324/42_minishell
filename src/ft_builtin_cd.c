/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:00:27 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/19 19:00:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Called when instruction is exactly ".." changes cwd to new directory
// move to end of cwd, then back to the earliest '/' from the back
// then set a '\0' on that position to mark moving up
// then actually change directory to that
static int	ft_dir_move_up(char *cwd, char **envp)
{
	int	len;

	len = 0;
	while (cwd[len] != '\0')
		len++;
	while (cwd[len] != '/')
		len--;
	if (len == 0)
		len++;
	cwd[len] = '\0';
	chdir(cwd);
	if (envp == NULL)
		return (1000);
	return (-1);
}

static int	ft_dir_move_down(char *cwd, char *goal, char **envp)
{
	int		len_cwd;
	int		len_goal;
	char	*copy;

	len_cwd = 0;
	while (cwd[len_cwd] != '\0')
		len_cwd++;
	printf("PWD is %i long\n", len_cwd);
	printf("Goal is [%s]\n", goal);
	len_goal = ft_strlen(goal);
	printf("Final length is %i long\n", len_cwd + len_goal + 2);
	printf("Target is [%s/%s]\n", cwd, goal);
	copy = ft_strdup(cwd);
	free(cwd);
	cwd = (char *)malloc((len_cwd + len_goal + 2) * sizeof(char));
	cwd[len_cwd + len_goal + 1] = '\0';
	while(len_goal > 0)
	{
		cwd[len_cwd + len_goal] = goal[len_goal - 1];
		len_goal--;
	}
	cwd[len_cwd + len_goal] = '/';
	while(len_cwd > 0)
	{
		cwd[len_cwd - 1] = copy[len_cwd -1];
		len_cwd--;
	}
	printf("Final Result: [%s]\n", cwd);
	chdir(cwd);
	ft_null(copy);
	if (envp == NULL)
		return (1000);
	return (-1);
}


static int	ft_change_directory(char **inst, char *cwd, char **envp)
{
	int	i;

	if (envp == NULL)
		return (1000);
	i = -1;
	while (inst[++i] != NULL)
	{
		printf("Handling instruction: [%s]\n", inst[i]);
		if (inst[i][0] == '.' && inst[i][1] == '.' && inst[i][2] == '\0') // carefull, that the inst is long enough
			ft_dir_move_up(cwd, envp);
		else
			ft_dir_move_down(cwd, inst[i], envp);
	}
	printf("Directoy changed");
	return (-1);
}

// continously runs through the <token[*pos]> until it reached the end
// ..
// if input has whitespaces -> error, doesnt exist
// ERROR Can only handle relative paths (../folder), not absolute pahts (/home/sikunne/Desktop)
// need to add a check for wether the first parth of the input is a /
int	ft_builtin_cd(char **tokens, int *pos, char *envp[])
{
	char	*cwd;
	char	**instru;

	(*pos)++;	
	if (ft_is_delimiter(tokens[*pos]) == 1)
		return (-1);
	cwd = getcwd(NULL , 0);
	if (tokens[*pos][0] == '/')
		printf("Absolute Path\n");
	else
		printf("Relative Path\n");
	instru = ft_split_quot_ex(tokens[*pos], '/');
	ft_print_tokens(instru);
	ft_change_directory(instru, cwd, envp);
	ft_nullb(instru);
	ft_null(cwd);
	if (envp == NULL)
		printf("error");
	(*pos)++;
	return (-1);
}
