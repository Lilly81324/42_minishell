/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:16 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/19 17:19:23 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[])
{
	char	**tokens;

	if (argc == 1)
		return (0);
	tokens = ft_split_quot_ex(argv[1], '/');
	ft_print_tokens(tokens);
	ft_nullb(tokens);
	return (0);
}
