/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:08:21 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/12 18:42:07 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if special command or 0 if regular
int	ft_check_special(char *inp)
{
	int	i;

	i = 0;
	i = ft_skip_spaces(i, inp);
	if (ft_strncmp(&inp[i], "exit", 4) == 0)
	{
		printf("Rest: [%s]\n", &inp[i + 4]);
		i = ft_skip_spaces(i + 4, inp);
		if (inp[i + 4] == '\0')
			return (1);
	}
	return (0);
}