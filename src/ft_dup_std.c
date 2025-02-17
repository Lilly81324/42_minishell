/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_std.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:46:04 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 16:47:31 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dup_std(int *std)
{
	std[0] = dup(STDIN_FILENO);
	std[1] = dup(STDOUT_FILENO);
	std[2] = dup(STDERR_FILENO);
}
