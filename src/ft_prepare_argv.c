/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:09:11 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 16:27:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_prepare_argv(char *inp)
{
	char	**ret;

	ret = ft_split_quot_ex(inp, ' ');
	return (ret);
}
