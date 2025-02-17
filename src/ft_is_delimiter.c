/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_delimiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:48:00 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:36:43 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_delimiter(char *str)
{
	if (str == NULL)
		return (1);
	if (str[0] == '\0')
		return (0);
	if (str[0] == '>' && str[1] == '\0')
		return (1);
	if (str[0] == '<' && str[1] == '\0')
		return (1);
	if (str[0] == '|' && str[1] == '\0')
		return (1);
	if (str[0] == ';' && str[1] == '\0')
		return (1);
	if (str[0] == '>' && str[1] == '>' && str[2] == '\0')
		return (1);
	if (str[0] == '<' && str[1] == '<' && str[2] == '\0')
		return (1);
	return (0);
}
