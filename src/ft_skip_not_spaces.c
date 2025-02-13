/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_not_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:32:26 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/13 17:14:09 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// gives back index of next 'space' or \0
void	ft_skip_not_spaces(int *i, char *str)
{
	while (str[*i] != ' ' && str[*i] != '\n' && str[*i] != '\t' \
		&& str[*i] != '\v' && str[*i] != '\f' && str[*i] != '\r' \
		&& str[*i] != '\0')
		(*i)++;
	return ;
}
