/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:59:55 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:27:59 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// runs builtin commands like exit, cd, unset
// returns 0-255 if programm should close with that code
// returns -1 if programm should continue
int	ft_special_cmd(char **tokens, int *pos)
{
	int	i;

	i = 0;
	ft_skip_spaces(&i, tokens[*pos]);
	if (ft_strncmp(&tokens[*pos][i], "exit", 4) == 0)
		return (1000);
	(*pos)++;
	return (-1);
}
