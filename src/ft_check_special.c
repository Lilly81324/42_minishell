/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:08:21 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/17 17:35:52 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns 1 if special command or 0 if regular
int	ft_check_special(char *inp)
{
	int	i;

	i = 0;
	ft_skip_spaces(&i, inp);
	if (ft_strncmp(&inp[i], "exit", 4) == 0)
	{
		i += 4;
		ft_skip_spaces(&i, inp);
		if (inp[i] == '\0')
			return (1);
	}
	return (0);
}
