/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:07 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 16:27:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// frees a 2d array that end with its last element being null
void	ft_nullb(char **ptr)
{
	int	i;

	i = -1;
	if (ptr == NULL)
		return ;
	while (ptr[++i] != NULL)
		ft_null(ptr[i]);
	ft_null(ptr);
}
